/*
程序功能：传输一个特定的文件，名字为test.txt
运行环境：Linux,UNIX
*/  

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main ()
{
    /******************************建立Socket连接*********************************/
    int length,clilen;
    struct sockaddr_in  server,client;
    int ServerListenSock,ServerTempSock;
    
    ServerListenSock=socket(AF_INET,SOCK_STREAM,0); //向系统申请socket资源
    if (ServerListenSock<0)
    {
        perror("opening stream socket");
        exit(1);
    }

    //服务端server结构体参数设置
    server.sin_family=AF_INET;  //这里指的是Internet协议
    server.sin_addr.s_addr=INADDR_ANY;  //接收任何IP连接
    server.sin_port=htons(20000);       //端口号固定值20000， htons()是格式转换函数

    if( bind(ServerListenSock,(struct sockaddr *)&server,sizeof server)<0) /*将IP地址和端口号绑到sock上*/
    {
        perror("Wrong:binding stream socket");
        exit(1);
    }

    length=sizeof server;
    if( getsockname(ServerListenSock,(struct sockaddr *)&server,&length)<0) /*获得指定socket的本地地址，成功返回0，错误返回-1。*/
    {
        perror("Wrong:getting socket name");
        exit(1);
    }
    printf("Socket port: %d\n",ntohs(server.sin_port)); /*显示服务器端监听端口号，client那边连过来时需要设置这个数*/

    listen(ServerListenSock,5); /*进行端口监听，允许5个连接请求排队等待，一般5个*/
    printf("正在监听......\n\n");
    
    /*******listen函数等待客户来连接,如果来客户了,accept函数就建立临时socket,可以当成文件读写**********/   

    while(1)
    {        
        clilen=sizeof client;
        ServerTempSock=accept(ServerListenSock,(struct sockaddr *)&client,(int *)&clilen);/*创建一个新的与ServerSock相同的临时sock用来收发数据，而ServerSock继续监听*/
        printf("创建临时socket，用于一次服务......\n\n");        
     
        if (ServerTempSock!=-1) 
        {	
			//////////////////  文件发送开始 /////////////////////////  

            #define BUFSIZE	128  /*每次发送总长是128字节，有效数据长126  */
            
            int infile;
            ssize_t file_nread;//记录从文件读取的信息长度
            char buf[BUFSIZE];
            int i=0;    /*文件块计数器*/
	 	
            if((infile=open("test.txt",O_RDONLY))==-1)  //打开本地要发送的文件，指定了文件名，只读方式打开
            {
                printf("找不到文件test.txt或打不开,停止运行\n");
                exit(1);
            }
            printf("打开文件test.txt，将其内容发送出去......\n\n"); 
	 	
            memset(buf,0,sizeof buf);/*缓冲区清零，准备存储将发送内容*/            
            while((file_nread=read(infile,buf,BUFSIZE-2))>0) /*将文件读到缓冲区，每次最多读取126字节，file_nread记录了数据实际长度，循环读到文件尾*/
            {
                printf("从文件中读了大小为 %d 的数据。",file_nread);
                buf[BUFSIZE-2]=file_nread;   /*把本次读取的实际长度，以数值方式放在buf的倒数第二字节，一并发送出去*/
                
                i++;   //统计读取了第i块数据
                buf[BUFSIZE-1]=(i%10)+48;   // 将计数器i转成可见,i+48是i的ASCII值。放在buf的最后一个字节，一并发送出去
                
                if(write(ServerTempSock,buf,BUFSIZE) <= file_nread)   /*将缓冲区的内容写入socket，发送给客户端*/ 
                    printf("写sock出了错\n");
                else
                   printf("发送包大小 %d, 块编号 %d ......\n",BUFSIZE,i%10);
	 		
                memset(buf,0,sizeof buf);   /*缓冲区再次清零，准备存储来自客户端返回的应答*/
                if(read(ServerTempSock,buf,BUFSIZE)<0)    /*从scok读信息*/
                    printf("读sock出了错\n");
                else
                    printf("...收到应答，对方收到块编号为 %s 的包。\n\n",buf);//显示应答，给人看的
            }/*文件读取和发送结束*/	
            
            
            close(infile);//本地发送的文件读完，关闭
            printf("......读文件结束，关闭文件test.txt。\n\n"); 
        
            
            //文件发送完收尾，告诉接收方这边没了
            printf("发送实际数据大小为0的包，作为文件传送结束标志，不需要应答......\n\n"); 
            buf[BUFSIZE-2]=0;/*和那边商量好了,如果这里为"0"表示这边文件到尾了*/
            if(write(ServerTempSock,buf,BUFSIZE)<=file_nread)/*将缓冲区的内容写到sock*/	 		
                printf("写sock出错\n");   

            //////////////////  文件发送结束 /////////////////////////     
	
	
			//////////////////  文件接收开始 ///////////////////////// 
            #define BUFSIZE	128  //每次接收信息的总长度
            #define PERM	0644 /* 新建文件的默认属性*/
    
            int outfile;
            ssize_t sock_nread;//记录从socket读取的信息长度
            int realn;//有效数据长度
            int i2=0;  /*客户端文件块计数器*/
            char charnum; //记录到达包的块编号，
    
            printf("创建文件test2.txt用于接收网络信息......\n\n\n");
            if((outfile=open("test2.txt",O_WRONLY|O_CREAT|O_TRUNC,PERM))==-1) //新建文件，用来接收服务器数据，文件名自定，这里定为test2.txt
            {
                printf("创建文件出错\n");
                exit(1);
            }
            memset(buf,0,sizeof buf);/*缓冲区清零，准备存储收到的内容*/
            while((sock_nread=read(ServerTempSock,buf,BUFSIZE))>0)  /*从sock读取传来的文件内容到缓冲区，每次最多读128长*/
            {
                printf("...从sock读了第 %d 个数据包,大小是 %d ,",++i2,sock_nread);
        
                realn=buf[BUFSIZE-2]; /*查一下有效数据长度，服务器那边写在包末尾*/
                printf("数据实际大小是 %d ，块编号是\"%c\".  \n",realn,buf[BUFSIZE-1]);
        
                if(realn==0) /*如果有效长度为0表示那边文件发完了，发来的是收尾信息。这边也收尾*/
                {
                    printf("\n.....收到数据实际大小为0的特定包，对方发送结束，跳出循环，接收文件结束...\n\n");
                    break; //跳过下面的正常操作，跳出while循环，进行收尾
                }
        
                //正常操作，收到的数据写入文件
                printf("将有效数据写入文件。");
                if(write(outfile,buf,realn)<realn) /*将缓冲区的内容写到文件里*/
                    printf("写文件时出了错\n");
        
                charnum=buf[BUFSIZE-1]; //取得到达信息的块编号，反馈回服务器
                printf("将块编号 \"%c\" 返回服务器作为应答......\n\n",charnum);//显示应答，给人看的
                memset(buf,0,sizeof buf);/*缓冲区再次清零，准备存储将反馈给服务器的内容*/
                buf[0]=charnum; /*告诉对方收到信息的编号*/
                write(ServerTempSock,buf,BUFSIZE);/*写socket，把反馈信息发回去*/

            }//while循环，一直运行到里面的break操作跳出
    
            //从上面的break语句跳来, 文件接收结束的收尾操作
            printf("......关闭文件test2.txt\n\n");
            close(outfile);

            //////////////////  文件接收结束 /////////////////////////
        } 
        else    
            perror("Wrong:accept");   
        
        printf("......一次服务结束，临时socket不再需要，消除。\n\n");   
        close(ServerTempSock);/*一次服务完成，关闭本次服务的临时套节字sock，内核试图发送已在队列的所有数据*/  
             
     
        printf("继续监听......\n\n");

    }//while(1);//服务器程序是死循环，一个服务完成后再等待下一次服务，不会自行退出。想退出按Ctrl+C
    
    exit(0);  //运行不到这行
}

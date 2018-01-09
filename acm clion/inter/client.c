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

int main(argc,argv)
int argc;
char *argv[];
{
    /***************************建立Socket连接*******************************/     
    int ClientSock;
	struct sockaddr_in  server,client;
    struct hostent *hp,*gethostbyname(); 
    
    printf("创建socket，用于连接服务器......\n\n"); 
    ClientSock=socket(AF_INET,SOCK_STREAM,0); /* 向系统申请socket资源，参数AF_INET,SOCK_STREAM是指TCP协议*/
    if (ClientSock<0)
    {
        perror("Wrong:opening stream socket");
        exit(1);
    }
     

    //客户端server结构体参数设置
    server.sin_family = AF_INET;  //这里指的是Internet协议
	
    hp = gethostbyname(argv[1]);  /*根据程序参数包含的主机名查地址，返回指针指向hostent结构*/
    if (hp==0) 
    {   /*当没有此主机名时*/ 
        fprintf(stderr,"%s:unknown host\n",argv[1]);
        exit(2);
    }
    memcpy((char *)&server.sin_addr,(char *)hp->h_addr,hp->h_length); // 从hp向结构体server复制地址，用来连接服务器
	
    server.sin_port = htons(atoi(argv[2]));  /*设置要连接的服务器的端口号。参数argv[2]是端口号，来自服务器的窗口显示*/

    if (connect(ClientSock,(struct sockaddr *)&server,sizeof server)<0) /*根据结构体server连接服务器连接服务器，建立连接*/
    {
        perror("Wrong:connecting stream socket");
        exit(1);
    }

    /******上面建好了Socket连接，下面就是怎么用了，和对待文件一样进行读写操作***********/
    
	    //////////////////  文件接收开始 ///////////////////////// 
    #define BUFSIZE	128  //每次接收信息的总长度 
    #define PERM	0644 /* 新建文件的默认属性*/ 
    
    int outfile;
    ssize_t sock_nread;//记录从socket读取的信息长度
    char buf[BUFSIZE];
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
    while((sock_nread=read(ClientSock,buf,BUFSIZE))>0)  /*从sock读取传来的文件内容到缓冲区，每次最多读128长*/
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
        write(ClientSock,buf,BUFSIZE);/*写socket，把反馈信息发回去*/
		
    }//while循环，一直运行到里面的break操作跳出
    
    //从上面的break语句跳来, 文件接收结束的收尾操作    
    printf("......关闭文件test2.txt\n\n");    
	close(outfile);
    
    //////////////////  文件接收结束 ///////////////////////// 
    
	
	
	//////////////////  文件发送开始 /////////////////////////  

            #define BUFSIZE	128  /*每次发送总长是128字节，有效数据长126  */
            
            int infile;
            ssize_t file_nread;//记录从文件读取的信息长度
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
                
                if(write(ClientSock,buf,BUFSIZE) <= file_nread)   /*将缓冲区的内容写入socket，发送给客户端*/ 
                    printf("写sock出了错\n");
                else
                   printf("发送包大小 %d, 块编号 %d ......\n",BUFSIZE,i%10);
	 		
                memset(buf,0,sizeof buf);   /*缓冲区再次清零，准备存储来自客户端返回的应答*/
                if(read(ClientSock,buf,BUFSIZE)<0)    /*从scok读信息*/
                    printf("读sock出了错\n");
                else
                    printf("...收到应答，对方收到块编号为 %s 的包。\n\n",buf);//显示应答，给人看的
            }/*文件读取和发送结束*/	
            
            
            close(infile);//本地发送的文件读完，关闭
            printf("......读文件结束，关闭文件test.txt。\n\n"); 
        
            
            //文件发送完收尾，告诉接收方这边没了
            printf("发送实际数据大小为0的包，作为文件传送结束标志，不需要应答......\n\n"); 
            buf[BUFSIZE-2]=0;/*和那边商量好了,如果这里为"0"表示这边文件到尾了*/
            if(write(ClientSock,buf,BUFSIZE)<=file_nread)/*将缓冲区的内容写到sock*/	 		
                printf("写sock出错\n");   

            //////////////////  文件发送结束 /////////////////////////       
    
		


    
    printf("......连接结束，关闭socket。\n\n"); 
    close(ClientSock);/*关闭客户端连接*/
    
    
    exit(0);
}

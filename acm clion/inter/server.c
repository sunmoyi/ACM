/*
�����ܣ�����һ���ض����ļ�������Ϊtest.txt
���л�����Linux,UNIX
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
    /******************************����Socket����*********************************/
    int length,clilen;
    struct sockaddr_in  server,client;
    int ServerListenSock,ServerTempSock;
    
    ServerListenSock=socket(AF_INET,SOCK_STREAM,0); //��ϵͳ����socket��Դ
    if (ServerListenSock<0)
    {
        perror("opening stream socket");
        exit(1);
    }

    //�����server�ṹ���������
    server.sin_family=AF_INET;  //����ָ����InternetЭ��
    server.sin_addr.s_addr=INADDR_ANY;  //�����κ�IP����
    server.sin_port=htons(20000);       //�˿ںŹ̶�ֵ20000�� htons()�Ǹ�ʽת������

    if( bind(ServerListenSock,(struct sockaddr *)&server,sizeof server)<0) /*��IP��ַ�Ͷ˿ںŰ�sock��*/
    {
        perror("Wrong:binding stream socket");
        exit(1);
    }

    length=sizeof server;
    if( getsockname(ServerListenSock,(struct sockaddr *)&server,&length)<0) /*���ָ��socket�ı��ص�ַ���ɹ�����0�����󷵻�-1��*/
    {
        perror("Wrong:getting socket name");
        exit(1);
    }
    printf("Socket port: %d\n",ntohs(server.sin_port)); /*��ʾ�������˼����˿ںţ�client�Ǳ�������ʱ��Ҫ���������*/

    listen(ServerListenSock,5); /*���ж˿ڼ���������5�����������Ŷӵȴ���һ��5��*/
    printf("���ڼ���......\n\n");
    
    /*******listen�����ȴ��ͻ�������,������ͻ���,accept�����ͽ�����ʱsocket,���Ե����ļ���д**********/   

    while(1)
    {        
        clilen=sizeof client;
        ServerTempSock=accept(ServerListenSock,(struct sockaddr *)&client,(int *)&clilen);/*����һ���µ���ServerSock��ͬ����ʱsock�����շ����ݣ���ServerSock��������*/
        printf("������ʱsocket������һ�η���......\n\n");        
     
        if (ServerTempSock!=-1) 
        {	
			//////////////////  �ļ����Ϳ�ʼ /////////////////////////  

            #define BUFSIZE	128  /*ÿ�η����ܳ���128�ֽڣ���Ч���ݳ�126  */
            
            int infile;
            ssize_t file_nread;//��¼���ļ���ȡ����Ϣ����
            char buf[BUFSIZE];
            int i=0;    /*�ļ��������*/
	 	
            if((infile=open("test.txt",O_RDONLY))==-1)  //�򿪱���Ҫ���͵��ļ���ָ�����ļ�����ֻ����ʽ��
            {
                printf("�Ҳ����ļ�test.txt��򲻿�,ֹͣ����\n");
                exit(1);
            }
            printf("���ļ�test.txt���������ݷ��ͳ�ȥ......\n\n"); 
	 	
            memset(buf,0,sizeof buf);/*���������㣬׼���洢����������*/            
            while((file_nread=read(infile,buf,BUFSIZE-2))>0) /*���ļ�������������ÿ������ȡ126�ֽڣ�file_nread��¼������ʵ�ʳ��ȣ�ѭ�������ļ�β*/
            {
                printf("���ļ��ж��˴�СΪ %d �����ݡ�",file_nread);
                buf[BUFSIZE-2]=file_nread;   /*�ѱ��ζ�ȡ��ʵ�ʳ��ȣ�����ֵ��ʽ����buf�ĵ����ڶ��ֽڣ�һ�����ͳ�ȥ*/
                
                i++;   //ͳ�ƶ�ȡ�˵�i������
                buf[BUFSIZE-1]=(i%10)+48;   // ��������iת�ɿɼ�,i+48��i��ASCIIֵ������buf�����һ���ֽڣ�һ�����ͳ�ȥ
                
                if(write(ServerTempSock,buf,BUFSIZE) <= file_nread)   /*��������������д��socket�����͸��ͻ���*/ 
                    printf("дsock���˴�\n");
                else
                   printf("���Ͱ���С %d, ���� %d ......\n",BUFSIZE,i%10);
	 		
                memset(buf,0,sizeof buf);   /*�������ٴ����㣬׼���洢���Կͻ��˷��ص�Ӧ��*/
                if(read(ServerTempSock,buf,BUFSIZE)<0)    /*��scok����Ϣ*/
                    printf("��sock���˴�\n");
                else
                    printf("...�յ�Ӧ�𣬶Է��յ�����Ϊ %s �İ���\n\n",buf);//��ʾӦ�𣬸��˿���
            }/*�ļ���ȡ�ͷ��ͽ���*/	
            
            
            close(infile);//���ط��͵��ļ����꣬�ر�
            printf("......���ļ��������ر��ļ�test.txt��\n\n"); 
        
            
            //�ļ���������β�����߽��շ����û��
            printf("����ʵ�����ݴ�СΪ0�İ�����Ϊ�ļ����ͽ�����־������ҪӦ��......\n\n"); 
            buf[BUFSIZE-2]=0;/*���Ǳ���������,�������Ϊ"0"��ʾ����ļ���β��*/
            if(write(ServerTempSock,buf,BUFSIZE)<=file_nread)/*��������������д��sock*/	 		
                printf("дsock����\n");   

            //////////////////  �ļ����ͽ��� /////////////////////////     
	
	
			//////////////////  �ļ����տ�ʼ ///////////////////////// 
            #define BUFSIZE	128  //ÿ�ν�����Ϣ���ܳ���
            #define PERM	0644 /* �½��ļ���Ĭ������*/
    
            int outfile;
            ssize_t sock_nread;//��¼��socket��ȡ����Ϣ����
            int realn;//��Ч���ݳ���
            int i2=0;  /*�ͻ����ļ��������*/
            char charnum; //��¼������Ŀ��ţ�
    
            printf("�����ļ�test2.txt���ڽ���������Ϣ......\n\n\n");
            if((outfile=open("test2.txt",O_WRONLY|O_CREAT|O_TRUNC,PERM))==-1) //�½��ļ����������շ��������ݣ��ļ����Զ������ﶨΪtest2.txt
            {
                printf("�����ļ�����\n");
                exit(1);
            }
            memset(buf,0,sizeof buf);/*���������㣬׼���洢�յ�������*/
            while((sock_nread=read(ServerTempSock,buf,BUFSIZE))>0)  /*��sock��ȡ�������ļ����ݵ���������ÿ������128��*/
            {
                printf("...��sock���˵� %d �����ݰ�,��С�� %d ,",++i2,sock_nread);
        
                realn=buf[BUFSIZE-2]; /*��һ����Ч���ݳ��ȣ��������Ǳ�д�ڰ�ĩβ*/
                printf("����ʵ�ʴ�С�� %d ��������\"%c\".  \n",realn,buf[BUFSIZE-1]);
        
                if(realn==0) /*�����Ч����Ϊ0��ʾ�Ǳ��ļ������ˣ�����������β��Ϣ�����Ҳ��β*/
                {
                    printf("\n.....�յ�����ʵ�ʴ�СΪ0���ض������Է����ͽ���������ѭ���������ļ�����...\n\n");
                    break; //�����������������������whileѭ����������β
                }
        
                //�����������յ�������д���ļ�
                printf("����Ч����д���ļ���");
                if(write(outfile,buf,realn)<realn) /*��������������д���ļ���*/
                    printf("д�ļ�ʱ���˴�\n");
        
                charnum=buf[BUFSIZE-1]; //ȡ�õ�����Ϣ�Ŀ��ţ������ط�����
                printf("������ \"%c\" ���ط�������ΪӦ��......\n\n",charnum);//��ʾӦ�𣬸��˿���
                memset(buf,0,sizeof buf);/*�������ٴ����㣬׼���洢��������������������*/
                buf[0]=charnum; /*���߶Է��յ���Ϣ�ı��*/
                write(ServerTempSock,buf,BUFSIZE);/*дsocket���ѷ�����Ϣ����ȥ*/

            }//whileѭ����һֱ���е������break��������
    
            //�������break�������, �ļ����ս�������β����
            printf("......�ر��ļ�test2.txt\n\n");
            close(outfile);

            //////////////////  �ļ����ս��� /////////////////////////
        } 
        else    
            perror("Wrong:accept");   
        
        printf("......һ�η����������ʱsocket������Ҫ��������\n\n");   
        close(ServerTempSock);/*һ�η�����ɣ��رձ��η������ʱ�׽���sock���ں���ͼ�������ڶ��е���������*/  
             
     
        printf("��������......\n\n");

    }//while(1);//��������������ѭ����һ��������ɺ��ٵȴ���һ�η��񣬲��������˳������˳���Ctrl+C
    
    exit(0);  //���в�������
}

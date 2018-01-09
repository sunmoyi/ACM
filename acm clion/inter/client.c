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

int main(argc,argv)
int argc;
char *argv[];
{
    /***************************����Socket����*******************************/     
    int ClientSock;
	struct sockaddr_in  server,client;
    struct hostent *hp,*gethostbyname(); 
    
    printf("����socket���������ӷ�����......\n\n"); 
    ClientSock=socket(AF_INET,SOCK_STREAM,0); /* ��ϵͳ����socket��Դ������AF_INET,SOCK_STREAM��ָTCPЭ��*/
    if (ClientSock<0)
    {
        perror("Wrong:opening stream socket");
        exit(1);
    }
     

    //�ͻ���server�ṹ���������
    server.sin_family = AF_INET;  //����ָ����InternetЭ��
	
    hp = gethostbyname(argv[1]);  /*���ݳ���������������������ַ������ָ��ָ��hostent�ṹ*/
    if (hp==0) 
    {   /*��û�д�������ʱ*/ 
        fprintf(stderr,"%s:unknown host\n",argv[1]);
        exit(2);
    }
    memcpy((char *)&server.sin_addr,(char *)hp->h_addr,hp->h_length); // ��hp��ṹ��server���Ƶ�ַ���������ӷ�����
	
    server.sin_port = htons(atoi(argv[2]));  /*����Ҫ���ӵķ������Ķ˿ںš�����argv[2]�Ƕ˿ںţ����Է������Ĵ�����ʾ*/

    if (connect(ClientSock,(struct sockaddr *)&server,sizeof server)<0) /*���ݽṹ��server���ӷ��������ӷ���������������*/
    {
        perror("Wrong:connecting stream socket");
        exit(1);
    }

    /******���潨����Socket���ӣ����������ô���ˣ��ͶԴ��ļ�һ�����ж�д����***********/
    
	    //////////////////  �ļ����տ�ʼ ///////////////////////// 
    #define BUFSIZE	128  //ÿ�ν�����Ϣ���ܳ��� 
    #define PERM	0644 /* �½��ļ���Ĭ������*/ 
    
    int outfile;
    ssize_t sock_nread;//��¼��socket��ȡ����Ϣ����
    char buf[BUFSIZE];
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
    while((sock_nread=read(ClientSock,buf,BUFSIZE))>0)  /*��sock��ȡ�������ļ����ݵ���������ÿ������128��*/
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
        write(ClientSock,buf,BUFSIZE);/*дsocket���ѷ�����Ϣ����ȥ*/
		
    }//whileѭ����һֱ���е������break��������
    
    //�������break�������, �ļ����ս�������β����    
    printf("......�ر��ļ�test2.txt\n\n");    
	close(outfile);
    
    //////////////////  �ļ����ս��� ///////////////////////// 
    
	
	
	//////////////////  �ļ����Ϳ�ʼ /////////////////////////  

            #define BUFSIZE	128  /*ÿ�η����ܳ���128�ֽڣ���Ч���ݳ�126  */
            
            int infile;
            ssize_t file_nread;//��¼���ļ���ȡ����Ϣ����
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
                
                if(write(ClientSock,buf,BUFSIZE) <= file_nread)   /*��������������д��socket�����͸��ͻ���*/ 
                    printf("дsock���˴�\n");
                else
                   printf("���Ͱ���С %d, ���� %d ......\n",BUFSIZE,i%10);
	 		
                memset(buf,0,sizeof buf);   /*�������ٴ����㣬׼���洢���Կͻ��˷��ص�Ӧ��*/
                if(read(ClientSock,buf,BUFSIZE)<0)    /*��scok����Ϣ*/
                    printf("��sock���˴�\n");
                else
                    printf("...�յ�Ӧ�𣬶Է��յ�����Ϊ %s �İ���\n\n",buf);//��ʾӦ�𣬸��˿���
            }/*�ļ���ȡ�ͷ��ͽ���*/	
            
            
            close(infile);//���ط��͵��ļ����꣬�ر�
            printf("......���ļ��������ر��ļ�test.txt��\n\n"); 
        
            
            //�ļ���������β�����߽��շ����û��
            printf("����ʵ�����ݴ�СΪ0�İ�����Ϊ�ļ����ͽ�����־������ҪӦ��......\n\n"); 
            buf[BUFSIZE-2]=0;/*���Ǳ���������,�������Ϊ"0"��ʾ����ļ���β��*/
            if(write(ClientSock,buf,BUFSIZE)<=file_nread)/*��������������д��sock*/	 		
                printf("дsock����\n");   

            //////////////////  �ļ����ͽ��� /////////////////////////       
    
		


    
    printf("......���ӽ������ر�socket��\n\n"); 
    close(ClientSock);/*�رտͻ�������*/
    
    
    exit(0);
}

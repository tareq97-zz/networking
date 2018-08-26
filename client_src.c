#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <signal.h>

#define BUFSIZE 128
//#define FILEBUFF 1023

typedef struct packet1{
 int sq_no;
}ACK_PKT;
typedef struct packet2{
 int packet_no;
 int packet_size;
 char data[BUFSIZE];
}DATA_PKT; 
struct sockaddr_in serverAdd;
struct sigaction act;

int packets(FILE *ptr);
int ceilValue(long a, long b);
int sock = 0;

int main(){
	int WINDOW_SIZE=0;

	printf("This is client:...\n");
	printf("Enter window size:...\n");
	scanf("%d",&WINDOW_SIZE);
	

	FILE *fptr;
	fptr= fopen("in.txt", "r");
	if (fptr == NULL) {
               perror("fopen");
               exit(EXIT_FAILURE);
        }
	/*Calculate the number of packets*/
	
	/*Creating a socket*/
	sock = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
	/*Socket not created then error message and exit*/
	if(sock<0){ printf("Error in opening the socket");exit(0);}

	/*Else open the socket*/
	printf("Socket is open : %d\n", sock);
	
	/*Connection of socket established with the server*/
	
	memset(&serverAdd,0, sizeof(serverAdd));
	serverAdd.sin_family = PF_INET;
	serverAdd.sin_port = htons(9002); //You can change port number here
	serverAdd.sin_addr.s_addr = INADDR_ANY; //Specify server's 
	printf("Address assigned\n");

	/*Establish connection*/
	int conn = connect(sock,(struct sockaddr*) &serverAdd , sizeof(serverAdd));
	if(conn<0){ 
		printf("Error in opening the socket");
		close(sock);
		exit(0);
	}
	printf("Connection is established : %d\n", sock);

	/*Send window size*/
	char *buffer;
	int value = WINDOW_SIZE;
	buffer = (char *)&value;
	int len = sizeof(value);
	int s_len =sizeof(serverAdd);
	printf("Buffer : %d\n", value);
	int send = sendto(sock,buffer,len, 0, (struct sockaddr *) &serverAdd, s_len);  
	
	ACK_PKT ack_pkt[WINDOW_SIZE];
	int Count=0;
	char filebuf[BUFSIZE];
	DATA_PKT send_pkt[WINDOW_SIZE];
	char c = fgetc(fptr);
	while (c != EOF)
    	{
		
		printf("This has enter");
    		for(int i=0;i<BUFSIZE;i++)
    		{
        		if(c!=EOF)
        		{
            			filebuf[i]=c;
           		 	//fputc(filebuf[i], fptr);
				printf("%c",filebuf[i]);
       			}
    		}
		
		/*for (int i = 0; i < BUFSIZE; i++) {
			//printf("WINDOW ?_SIZE NOW IS %d\n", WINDOW_SIZE);
      			send_pkt[Count].data[i] = filebuf[i];
			send_pkt[Count].packet_no = Count;
	
			printf("Packet to send %d = %c ::: File Packet = %c:::::Pac No: %d\n", Count,send_pkt[Count].data[i], filebuf[i],send_pkt[Count].packet_no);
  		}
		//send_pkt[Count].packet_size =*/  
		//Count++;       
	}

	long packet = packets(fptr);
	printf("No of packets for file: %ld\n",packet);

		
	long noWindows = ceilValue(packet,WINDOW_SIZE);
	printf("No of Windows will be send : %ld\n", noWindows);
	
	

	fclose(fptr);
	
	/*Atlast close the socket*/
	int s_close=close(sock);
	printf("Socket is close : %d\n", s_close);
}


int packets(FILE *ptr){
 
    // Moving pointer to end
    	fseek(ptr, 0, SEEK_END);
     
    // Printing position of pointer
	long size = ftell(ptr);
	//fseek(ptr, 0, SEEK_SET);
	rewind(ptr);
	int packet = ceilValue(size, BUFSIZE);
	return packet;
}

int ceilValue(long a, long b){
	if(a % b==0){
		return a/b;
	}
	else{
		return (a/b)+1;
	}
}


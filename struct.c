#include <stdio.h>
#include <stdlib.h>
#define BUFSIZE 10

int main(){

	typedef struct packet{
		 int packet_no;
 		 int packet_size;
 		 char data[BUFSIZE];
	}DATA_PKT;
	int WINDOW_SIZE;

	
	printf("Enter window size:");
	scanf("%d", &WINDOW_SIZE);
	DATA_PKT send_pkt[WINDOW_SIZE];

	for (int i = 0; i < BUFSIZE; i++) {
			printf("WINDOW ?_SIZE NOW IS %d\n", WINDOW_SIZE);
      			send_pkt[Count].data[i] = 0;
			printf("Packet to send %d = %c ::::: File Packet = %c\n",send_pkt[Count].data[i], filebuf[i]);
  	}
	
	return 0;
}


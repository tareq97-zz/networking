#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
int main(){
	printf("This is client:...\n");
	int sock = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
	/*Socket not created then error message and exit*/
	if(sock<0){ printf("Error in opening the socket");exit(0);}

	/*Else open the socket*/
	printf("Socket is open : %d\n", sock);
	
	/*Connection of socket established with the server*/
	struct sockaddr_in serverAdd;
	memset(&serverAdd,0, sizeof(serverAdd));
	serverAdd.sin_family = PF_INET;
	serverAdd.sin_port = htons(139); //You can change port number here
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

	/*Atlast close the socket*/
	int s_close=close(sock);
	printf("Socket is close : %d\n", s_close);
}

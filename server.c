#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
int main(){
	printf("This is Server:...\n");
	int sock = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
	/*Socket not created then error message and exit*/
	if(sock<0){ printf("Error in opening the socket");exit(0);}

	/*Else open the socket*/
	printf("Socket is open %d\n", sock);
	
	struct sockaddr_in serverAdd;
	memset(&serverAdd,0, sizeof(serverAdd));
	serverAdd.sin_family = PF_INET;
	serverAdd.sin_port = htons(53); //You can change port number here
	printf(serverAdd.sin_port);
	serverAdd.sin_addr.s_addr = 127.0.0.1; //Specify server's 
	printf("Address assigned\n");

	int b = bind(sock,(struct sockaddr*) &serverAdd , sizeof(serverAdd));
	if(b<0){ printf("Error in Binding the socket %d\n",b); close(sock) ;exit(0);}
	/*Else open the socket*/
	printf("Socket is open %d\n", sock);

	int l = listen(sock, 5);
	if(l<0){
		printf("Actual error is : %s/n" strerror(errno));
	printf("Error in Binding the socket %d\n",b); close(sock) ;exit(0);
	}
	printf("Server started listening : %d" l);


	/*Atlast close the socket*/
	int s_close=close(sock);
	printf("Socket is close %d\n", s_close);
}

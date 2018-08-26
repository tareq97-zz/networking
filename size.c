#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <inttypes.h>
#include <errno.h>
#define BUFSIZE 10

int main(){
	
	FILE *fp;
    	fp = fopen("in.txt", "r");
     
    // Moving pointer to end
    	fseek(fp, 0, SEEK_END);
     
    // Printing position of pointer
    	printf("%ld", ftell(fp));

	fseek(fp, 0, SEEK_SET);
	return 0;
}


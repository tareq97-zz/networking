#include <stdio.h>
#include <string.h>

int main(){

	FILE * fptr;
	//FILE * fprt1;
	char buffer[1200];
	fptr = fopen("in.txt", "r");
	//fptr1 = fopen("out.txt", "a+");
	/* Seek to the beginning of the file */
        fgets(buffer, 1200, fptr);
	printf("%s\n", buffer);
	//fwrite(buffer,sizeof(char),strlen(buffer)-1,fptr);
	
   	fclose(fptr);
	//fclose(fptr1);	

	return 0;
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	int count=0;
	while(count<10){
	float i = drand48() * 100;
	printf("drnd value : %0.f\n", i);
	count++;
	}
	/*FILE * fptr;
	//FILE * fprt1;
	char buffer[32];
	fptr = fopen("in.txt", "r");
	//fptr1 = fopen("out.txt", "a+");
	/* Seek to the beginning of the file 
	int Count=0;        
	while(fscanf(fptr,"%s", &buffer[Count])==1){
		printf("%d\n", buffer[Count]);
		Count++;
	}
	//while(fscanf(fptr,"%s", buffer) ==1)
	//{
	//	printf("%s", buffer);
	//}

   	fclose(fptr);*/
	//fclose(fptr1);	

	return 0;
}

#include <stdio.h>

int main(){
	FILE * fptr;

	char greeting[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
	fptr = fopen("out.txt","a+");
	fwrite(greeting , sizeof(char), 5, fptr);
	fprintf(fptr, "\n");
	fclose(fptr);
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char** argv){

	int random;
	random = rand();
	printf("%d", random);

	char buffer[32];
	char buffer2[32];
	
	char *p_buffer2[2];
	p_buffer2[0] = buffer2;
	p_buffer2[1] = NULL;
	fgets(buffer2, 32, stdin);

	//char buffer[32];
        //strcpy(buffer, argv[2]);
	gets(buffer);

	execve(buffer2, p_buffer2, NULL);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char buf[32];

int main(int argc, char** argv){

	printf("Le Door> Le Peanutcave is protected by the best password generator of the planet!\n");

	unsigned int random;

	while(1) {
		random = rand();
        	char key[32];

		printf("Le Door> Le Great Door is waiting for the password:\n");

		int fd = atoi( argv[1] ) - 0x1234;
        	int len = 0;
        	len = read(fd, key, 32);

		printf("%d\n", atoi(key));

        	if( (atoi(key) ^ random) == 0x9000dd09 ){

			printf("Alfred> Be careful, with great power comes great responsibility.\n");
			
			char buffer[32];
			char buffer2[32];

        		char *p_buffer2[2];
        		p_buffer2[0] = buffer2;
        		p_buffer2[1] = NULL;

        		strcpy(buffer2, argv[1]);
			gets(buffer);

        		execve(buffer2, p_buffer2, NULL);

			return 0;
        	}

        	printf("Le Door> Mouhahaha do you think you can fool Le Great Door of le Peanutcave? Your failure changed the password, you will never find it!\n");
	}
}


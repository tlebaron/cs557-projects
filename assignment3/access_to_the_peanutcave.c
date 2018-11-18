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

        	printf("Le Door> Enter le password:\n");
        	unsigned int key = 0;
        	scanf("%d\n", &key);

        	if( (key ^ random) == 0x9000dd09 ){

			//printf("Alfred> I am glad to see you safe master Peanut.\n");

			int fd = atoi( argv[1] ) - 0x1234;
        		int len = 0;
        		len = read(fd, buf, 32);

        		if(strcmp("ILOVEPEANUT\n", buf) == 0){

				//printf("Alfred> Be careful, with great power comes great responsibility.\n");
			
				char buffer[32];
			        char buffer2[32];

        			char *p_buffer2[2];
        			p_buffer2[0] = buffer2;
        			p_buffer2[1] = NULL;

        			strcpy(buffer2, argv[1]);
				gets(buffer);

        			execve(buffer2, p_buffer2, NULL);

				printf("Content of buffer is  %x", *buffer);

				return 0;
        		}

			printf("Alfred> I guess you can rest for a bit.\n");

                	return 0;
        	}

        	printf("Le Door> Mouhahaha do you think you can fool Le Great Door of le Peanutcave? Your failure changed the password, you will never find it!\n");
		return 0;
	}
}


#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void peanut(){

	char buffer[512];
        fgets(buffer, 512, stdin);
        printf(buffer);

        exit(1);

}

int main(int argc, char **argv) {
	//void *p = NULL;
        //printf("%p", (void*)&p);

	//size_t size = sysconf(_SC_PAGESIZE);
	//printf("%d", size);

	char *name[2];
	//name[0] = "/bin/shh";
        fgets(name[0], 8, stdin);
        name[1] = NULL;


	peanut();

}

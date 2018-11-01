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
	
	char *name[2];
	name[0] = "/bin/shh";
        name[1] = NULL;


	peanut();

}

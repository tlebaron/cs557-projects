
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

	peanut();

}

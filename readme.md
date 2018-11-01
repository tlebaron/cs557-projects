Ideas:
- use the fd challenge of pwnable.kr
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char buf[32];
int main(int argc, char* argv[], char* envp[]){
	if(argc<2){
		printf("pass argv[1] a number\n");
		return 0;
	}
	int fd = atoi( argv[1] ) - 0x1234;
	int len = 0;
	len = read(fd, buf, 32);
	if(!strcmp("LETMEWIN\n", buf)){
		printf("good job :)\n");
		system("/bin/cat flag");
		exit(0);
	}
	printf("learn about Linux file IO\n");
	return 0;

}

- instead of printf good job and printf, use a gets funciton to allow a buffer overflow (need to remove stack canaries though). With this, a simple ROP chaing is enough
- change LETMEWIN to ILOVEPEANUT to earn some sympathy points
- need to disable ASLR too
- the buffer will be someting like "/bin/shh"+LOTOFCRAP+address of the first gadget+list of addresses of following gadgets
- seems to be a bit too obvious. need to find smth a bit better



- Second idea, we take a fun CTF like random():
#include <stdio.h>

int main(){
	unsigned int random;
	random = rand();	// random value!

	unsigned int key=0;
	scanf("%d", &key);

	if( (key ^ random) == 0xdeadbeef ){
		printf("Good!\n");
		system("/bin/cat flag");
		return 0;
	}

	printf("Wrong, maybe you should try 2^32 cases.\n");
	return 0;
}
- we directly execute execve("/bin/shh") if they find the right key. It is like a "protected" admin page. We can pump it a bit by asking for a password to access the admin privileges.

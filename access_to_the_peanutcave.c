#include <stdio.h>

int main(){

	printf("Door> The Peanutcave is protected by the best password generator of the planet\n");

	unsigned int random;
	random = rand();

	printf("Door> Enter the password:\n");
	unsigned int key=0;
	scanf("%d", &key);

	if( (key ^ random) == 0xdeadbeef ){
		printf("Alfred> Good morning master Peanut, it is good to see you\n");
		execve("/bin/shh");
		return 0;
	}

	printf("Door> You are not Peanut! I am calling the security\n");
	return 0;
}


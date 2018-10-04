char* encryption(buffer){
	
}

int main() {
	printf("Encrypter");

	int choice = 1;
	char buffer[16];
	char enc_buffer[16];

	while(choice){
		fgets(buffer, 16, stdin);
		enc_buffer = encryption(buffer);
		printf("Result in hex is %x", enc_buffer);
		do {
			printf("Continue? [0] No [1] Yes");
			fgets(choice, 4, stdin);
		}while(choice != 1 || choice != 0)
	}
	return 0;

}

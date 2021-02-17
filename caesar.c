#include <stdlib.h>
#include <stdio.h>
#include <string.h>

const char* caesar_encrypt(char* message, int key);

int main(int argc, char* argv[]){

	if(argc != 4){
		printf("Syntax: caesar [mode] [message] [key]\n");
		exit 1;
	}
	else if(strncmp(argv[1], "e", 1) != 0 || strncmp(argv[1], "d", 1) != 0){
		prinf("Arg1 error --> [mode]: 'e' for encrypt or 'd' for decrypt\n");
		exit 1;
	}
	else if(strlen(argv[2]) > 100){
		printf("Arg2 error --> Input message too long, max 100 characters\n");
		exit 1;
	}
	int key = atoi(argv[3]) % 26;
	
	char message[100], ch;
	strncpy(argv[2], message, 100);
	int i;
	
	if(strncmp(argv[1], "e", 1) == 0){
		for(i = 0; message[i] != '\0'; ++i){
			ch = message[i];
		
			if(ch >= 'a' && ch <= 'z'){
				ch = ch + key;
			
				if(ch > 'z'){
					ch = ch - 'z' + 'a' - 1;
				}
			
				message[i] = ch;
			}
			else if(ch >= 'A' && ch <= 'Z'){
				ch = ch + key;
			
				if(ch > 'Z'){
					ch = ch - 'Z' + 'A' - 1;
				}
			
				message[i] = ch;
			}
		}
		
		printf("Encrypted message: %s\n", message);
	}
	else if(strncmp(argv[1], "d", 1) == 0){
		for(i = 0; message[i] != '\0'; ++i){
			ch = message[i];
		
			if(ch >= 'a' && ch <= 'z'){
				ch = ch - key;
			
				if(ch < 'a'){
					ch = ch + 'z' - 'a' + 1;
				}
			
				message[i] = ch;
			}
			else if(ch >= 'A' && ch <= 'Z'){
				ch = ch - key;
			
				if(ch < 'A'){
					ch = ch + 'Z' - 'A' + 1;
				}
			
				message[i] = ch;
			}
		}
		printf("Decrypted message: %s\n", message);
	}
	
	return 0;
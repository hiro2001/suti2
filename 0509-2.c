#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

char com1[10] = "tsuda";
char com2[10] = "tuda";
char one[256];
int A = 0, B = 0;

void comper2(){
	int c, m = 0, n = 0, i = 0;
	printf("%s", com1);
	while(1){
		if(com1[m] == com2[n]){
			one[i] = 1;
			m++;
			n++;
			i++;
		}
		else if(com1[m] == com2[n+1]){
			one[i] = 0;
			one[i+1] = 1;
			for(c = A+1; c >= i; c--){
				com1[c] = com1[c - 1];
			}
			com1[i] = 0x20;
			A++;
			i += 2;
			m += 2;
			n += 2;
		}
		else if(com1[m+1] == com2[n]){
			one[i] = 0;
			one[i+1] = 1;
			for(c = B+1; c >= i; c--){
				com2[c] = com2[c - 1];
			}
			com2[i] = 0x20;
			B++;
			i += 2;
			m += 2;
			n += 2;
		}
		else{
			one[i] = 0;
			i++;
			m++;
			n++;
		}
			
		if(com1[m] == 0x0a|| com2[n] == 0x0a)
			break;
	}
	
	for(c = 0; c < 2; c++){
		for(m = 0;m < i; m++){
			switch(c){
				case 0:
					printf("%c", com1[m]);
					break;
				case 1:
					printf("%c", com2[m]);
					break;
				default:
					c = 0;
					break;
			}
		}
		printf("\n");
	}
	for(m = 0;m < i; m++){
		switch(one[m]){
			case 0:
				printf("x");
				break;
			case 1:
				printf("o");
				break;
			default:
				printf("ellor");
				break;
		}
	}
	printf("\n");
}

int main(){
	comper2();
	return 0;
}

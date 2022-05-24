#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

int main(){
	char com1[256];
	char com2[256];
	int one[256];
	int A, B;
	int c = 0, m = 0, n = 0, i = 0;

	printf("1:");
	scanf(" %s", com1);
	printf("2:");
	scanf(" %s", com2);
	A = strlen(com1);
	B = strlen(com2);
	for(i = 0; i < 256; i++)
		one[i] = 0x0a;
		
  i = 0;
	n = 0;
	m = 0;	
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
			i += 2;
			m += 2;
			n += 2;
		}
		else if(com1[m+1] == com2[n]){
			one[i] = 0;
			one[i+1] = 1;
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
			
		if(m >= A && n >= B){
			break;
		}
	}
	
	for(m = 0;m < A; m++){
		printf("%c", com1[m]);
	}
	printf("\n");
	for(m = 0;m < B; m++){
		printf("%c", com2[m]);
	}
	printf("\n");
	for(m = 0;m < i; m++){
		switch(one[m]){
			case 0:
				printf("x");
				break;
			case 1:
				printf("o");
				break;
			default:
				printf("ellor\n");
				exit(0);
				break;
		}
	}
	printf("\n");

	
	return 0;
}

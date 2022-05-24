#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>

char com1[256], com2[256], one[256];
int A = 0, B = 0;

void comper1(FILE *fp){
	int i = 0, a = 0;
	char cha;

	if (fp == NULL) {
    printf ("comp.txt file not found.\n");
    exit(0);
  }
	while((cha = fgetc(fp)) != EOF){
		if((cha >= 'A') && (cha <= 'Z')){
      cha += 0x20;
    }
		if(cha == 0x0a && a == 0){
			a++;
			A = i;
			i = 0;
		}
		if(cha != 0x0a){
			switch(a){
				case 0:
					com1[i] = cha;
					break;
				case 1:
					com2[i] = cha;
					break;
				default:
					a = 0;
					break;
			} 
			i++;
		}
	}
	B = i;
	fclose(fp);
}

void comper2(){
	int c, m = 0, n = 0, i = 0;
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
	FILE *fp1;
	int i;
	char com[256];

	for(i = 0; i < 256; i++)
		com1[i] = 0x0a;
	for(i = 0; i < 256; i++)
		com2[i] = 0x0a;
	for(i = 0; i < 256; i++)
		one[i] = 0x0a;

	fp1 = fopen("comp.txt", "w");
	if(fp1 == NULL){
		printf("ellor\n");
		exit(0);
	}
	printf("1: ");
	scanf(" %s", com);
	fprintf(fp1,"%s\n\n", com);

	printf("2: ");
	scanf(" %s", com);
	fprintf(fp1,"%s", com);
	fclose(fp1);

	fp1 = fopen("comp.txt", "r");
	comper1(fp1);
	comper2();
	return 0;
}

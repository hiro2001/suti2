#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
	int i= 0, m, n[256];
	char A[256];
	FILE *fp;
	fp = fopen("date.txt", "r");
	
	if(fp == NULL){
		printf("date.txt file not found.");
		return 1;
	}
	
	while(fgets(A, 256, fp) != NULL){
		printf("%s\n", A);
		n[i] = atoi(A);
		i++;
	}
	
	printf("%d\n", i);

	printf("hoge\n");
	m = i;

	for(i = 0; i < m; i++){
		printf("%d\n", n[i]);
	}
	fclose(fp);


	return 0;
}

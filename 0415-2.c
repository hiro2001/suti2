#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
	int i= 0, m, n[256], total = 0, ave = 0;
	char A[256];
	FILE *fp;
	fp = fopen("date.txt", "r");
	if(fp == NULL){
		printf("date.txt file not found.");
		return 1;
	}
	
	while(fgets(A, 256, fp) != NULL){
		n[i] = atoi(A);
		i++;
	}
	
	printf("格納されていた数字の個数は%d個です。\n", i);
	m = i;
	for(i = 0; i < m; i++){
		printf("%d\n", n[i]);
		total += n[i];
	}
	fclose(fp);
	ave = total / m;
	printf("%d", ave);
	
	return 0;
}

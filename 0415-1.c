#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main(){
	int i,m;
	FILE *fp;

	int A[256];

	fp = fopen("date.txt", "w");
	printf("count scan\n");
	scanf("%d", &m);

	for(i = 0; i < m; i++){
		//printf("%d\n", i);
		A[i] = rand()%100;
		fprintf(fp, "%d \n", A[i]);
	}
	fclose(fp);
	printf("fin\n");
	return 0;
}

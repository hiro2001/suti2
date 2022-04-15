#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	int i= 0, m, n[256];
	double total = 0, total2 = 0, ave = 0, squ = 0, v = 0, s = 0;
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
		total2 += n[i]*n[i];
	}
	fclose(fp);
	ave = total / m;
	squ = total2 - (total * total / m);
	v = squ / (m - 1);
	s = sqrt(v);

	printf("平均：%.3lf\n", ave);
	printf("分散：%.3lf\n", v);
	printf("標準偏差：%.3lf\n", s);

	return 0;
}

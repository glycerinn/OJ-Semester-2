#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	int N, Q;
	scanf("%d %d", &N, &Q);
	
	int day[N];
	for(int i = 0; i<N; i++){
		scanf("%d", &day[i]);
	}
	
	
	char opr;
	int i, x;
	int l, r;
	for(int p = 0; p < Q; p++){
		scanf(" %c", &opr);
		
		if(opr == 'U'){
			scanf("%d %d", &i, &x);
			day[i-1] = x;
		}else{
			scanf("%d %d", &l, &r);
			int sum = 0;
			for(int j = l-1; j <= r-1; j++){
				sum += day[j];
			}
			printf("%d\n", sum);
		}
	}
	
}

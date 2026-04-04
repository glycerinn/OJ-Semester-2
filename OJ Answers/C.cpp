#include<stdio.h>

int main(){
	int N;
	scanf("%d", &N);
	
	int num[N];
	for(int i = 0; i<N; i++){
		scanf("%d", &num[i]);
	}
	
	int max = 0;
	for(int i = 0; i < N; i++){
		if(max < num[i]){
			max = num[i];
			printf("%d\n", max);
		}else{
			printf("%d\n", max);
		}
	}
	
}

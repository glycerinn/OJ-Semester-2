#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	int N, K;
	scanf("%d %d", &N, &K);
	
	int num[N];
	for(int i = 0; i<N; i++){
		scanf("%d", &num[i]);
	}
	
	for(int i = 0; i < N/2; i++){
		int temp = num[i];
		num[i] = num[N-1-i];
		num[N-1-i] = temp;
	}
	
	for(int i = 0; i < K/2; i++){
		int temp = num[i];
		num[i] = num[K-1-i];
		num[K-1-i] = temp;
	}
	
	for(int i = 0; i < (N-K)/2; i++){
		int temp = num[K+i];
		num[K+i] = num[N-1-i];
		num[N-1-i] = temp;
	}
	
	for(int i = 0; i < N; i++){
		printf("%d ", num[i]);
	}
}

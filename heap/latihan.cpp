#include<stdio.h>

int heap[100];
int size = 0;

void swap(int a, int b){
	int temp = heap[a];
	heap[a] = heap[b];
	heap[b] = temp;
}

void insert(int val){
	size++;
	heap[size] = val;
	
	int cur = size;
	while(cur != 1 && heap[cur] < heap[cur/2]){
		swap(cur, cur/2);
		cur/=2;
	}
}

void delet(){
	heap[1] = heap[size];
	size--;
	
	int cur = 1;
	while(cur*2 <= size){
		int next = cur;
		if(heap[cur] > heap[cur*2])
			next = cur*2;
		
		if(heap[next]>heap[cur*2+1])
			next = cur*2+1;
		
		if(next == cur)
			break;
			
		swap(next, cur);
		cur = next;
	}
}

void maxheapify(int cur){
	while(cur * 2 <= size){
		int next = cur;
		int left = cur* 2;
		int right = cur * 2 +1;
		
		if(heap[left] > heap[next])
			next = left;
		
		if(right <= size && heap[right] > heap[next])
			next = right;
		
		if(next == cur)
			break;
			
		swap(next, cur);
		cur = next;
	}
}

int heaptop(){
	return heap[1];
}

int main(){
	int contoh[30];
	int n;
	
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++){
		scanf("%d", &contoh[i]);
		insert(contoh[i]);
	}
	
	printf("Min Heap:\n");
	for(int i = 1; i <= size; i++){
	    printf("%d ", heap[i]);
	}
	printf("\n");
	
	for(int i = size/2; i >= 1; i--){
    	maxheapify(i);
	}
	
	printf("Max Heap:\n");
	for(int i = 1; i <= size; i++){
	    printf("%d ", heap[i]);
	}
	printf("\n");
}

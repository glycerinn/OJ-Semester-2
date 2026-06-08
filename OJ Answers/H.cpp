#include <stdio.h>

typedef struct{
	char ch;
	int frq;
}Node;

Node heap[30];
int size = 0;

int higher(Node a, Node b){
	if(a.frq != b.frq)
		return a.frq > b.frq;
	
	return a.ch > b.ch;
}

void swap(int a, int b){
	Node temp =  heap[a];
	heap[a] = heap[b];
	heap[b] = temp;
}

void insert(Node val){
	size++;
	heap[size] = val;
	
	int cur = size;
	while(cur != 1 && higher(heap[cur], heap[cur/2])){
		swap(cur, cur/2);
		cur /= 2;
	}
}

void del(){
	heap[1] = heap[size];
	size--;
	
	int cur = 1;
	while(cur * 2 <= size){
		int next = cur;
		int left = cur*2;
		int right = cur*2 + 1;
		
		if(higher(heap[left], heap[next])){
			next = left;
		}
		
		if(right <= size && higher(heap[right], heap[next])){
			next = right;
		}
		
		if(next == cur){
			break;
		}
		
		swap(cur, next);
		cur = next;
	}
}

Node top(){
	return heap[1];
}

int main(){
	int k;
	char s[101];
	
	scanf("%d", &k);
	scanf("%s", s);
	
	int frq[26] = {0}; 
	
	for(int i = 0; s[i]; i++){
		frq[s[i] - 'A']++;
	}
	
	for(int i = 0; i < 26; i++){
		if(frq[i]>0){
			Node temp;
			temp.ch = 'A' + i;
			temp.frq = frq[i];
			
			insert(temp);
		}
	}
	
	while(k-- && size>0){
		Node cur = top();
		printf("%c %d\n", cur.ch, cur.frq);
		del();
	}
}

#include<stdio.h>
#include<stdlib.h>

struct data{
	int angka;
	struct data* next;
	struct data* prev;
}*head, *tail;

void backpush(int angka){
	struct data *curr = (struct data*)malloc(sizeof(struct data));
	curr->angka = angka;
	curr->next = NULL;
	curr->prev = NULL;
	
	if(head == NULL){
		head = tail = curr;
	}else{
		tail->next = curr;
		curr->prev = tail;
		tail = curr;
	}
}

void printall(){	
	struct data *temp = head;
	while(temp != NULL){
		printf("%d ", temp->angka);
		temp = temp->next;
	}
	
}

int main(){
	int N, x;
	scanf("%d", &N);
	
	for(int i = 0; i < N; i++){
		scanf("%d", &x);
		backpush(x);
	}
	
	printall();
}

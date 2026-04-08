#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct data{
	int angka;
	char word[200];
	struct data* next;
	struct data* prev;
}*head, *tail, *top;

void PushQueue(char word[]){
	struct data *curr = (struct data*)malloc(sizeof(struct data));
	strcpy(curr->word, word);
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

void PopQueue(){
	struct data *temp = head;
	head = head->next;
	
	if(head != NULL){
		head->prev = NULL;
	}
	
	free(temp);
}

void PushStack(char word[]){
	struct data *curr = (struct data*)malloc(sizeof(struct data));
	strcpy(curr->word, word);
	curr->next = NULL;
	curr->prev = NULL;
	
	if(top == NULL){
		top = curr;
	}else{
		curr->next = top;
		top->prev = curr;
		top = curr;
	}
}

void PopStack(){
	struct data *temp = top;
	top = top->next;
	
	if(top != NULL){
		top->prev = NULL;
	}
	
	free(temp);
}

void printallQueue(){	
	struct data *temp = head;
	printf("Queue is: ");
	while(temp != NULL){
		printf("\"%s\" ", temp->word);
		temp = temp->next;
	}
	
}

void printallStack(){	
	struct data *temp = top;
	printf("Stack is: ");
	while(temp != NULL){
		printf("\"%s\" ", temp->word);
		temp = temp->next;
	}
	
}

int main(){
	int N;
	char x[200], p[200];
	scanf("%d", &N);
	getchar();
	
	for(int i = 0; i < N; i++){
		fgets(x, sizeof(x), stdin);
		x[strcspn(x, "\n")] = 0;
		PushQueue(x);
	}
	
	for(int i = 0; i < N; i++){
		fgets(p, sizeof(p), stdin);
		p[strcspn(p, "\n")] = 0;
		PushStack(p);
	}
	
	printallQueue();
	printf("\n");
	printallStack();
}

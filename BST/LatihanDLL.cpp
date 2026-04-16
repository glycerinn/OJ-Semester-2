#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
	struct node *prev;
};

struct node *head1 = NULL;
struct node *head2 = NULL, *tail2 = NULL;

void pushstack(int num){
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->data = num;
	temp->next = NULL;
	temp->prev = NULL;
	
	if(head1 == NULL){
		head1 = temp;
	}else{
		temp->next=head1;
		head1->prev = temp;
		head1 = temp;
	}
}

int popstack(){
	if(head1 == NULL) return NULL;
	
	struct node *temp =head1;
	head1 = head1->next;
	int val = temp->data;
	
	if(head1 != NULL)
		head1->prev = NULL;
		
	free(temp);
	
	return val;
}

void pushqueue(int num){
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->data = num;
	temp->next = NULL;
	temp->prev = NULL;
	
	if(head2 == NULL){
		head2 = tail2 = temp;
	}else{
		tail2->next = temp;
		temp->prev = tail2;
		tail2=temp;
	}
}

void popqueue(){
	if(head2 == NULL) return;
	
	struct node *temp =head2;
	head2 = head2->next;
	
	if(head2 != NULL){
		head2->prev = NULL;
	}
	else{
		tail2 = NULL;
	}
		
	free(temp);
}

int sum(){
	struct node *temp = head2;
	int num = 0;
	while(temp != NULL){
		num += temp->data;
		temp = temp->next;
	}
	
	return num;
}

int main(){
	int N, M;
	scanf("%d %d", &N, &M);
	
	int x;
	for(int i = 0; i<N; i++){
		scanf("%d", &x);
		pushstack(x);
	}
	
	for(int i = 0; i<M; i++){
		scanf("%d", &x);
		pushqueue(x);
	}
	
	while(head1 != NULL){
		int stack = popstack();
		for(int j = 0; j < stack && head2 != NULL; j++){
			popqueue();
		}
	}
	
	printf("%d\n", sum());
}

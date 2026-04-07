#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct data{
	int nilai;
	struct data *next;
}*head, *tail, *top;

//back push
void pushQueue(int angka){
	struct data *curr = (struct data*)malloc(sizeof(struct data));
	curr->nilai = angka;
	curr->next = NULL;
	
	if(head == NULL){
		head = tail = curr;
	}else{
		tail->next = curr;
		tail = curr;
	}
}

//front Pop
int popQueue(){
	if(head == NULL) return -1;

	struct data *temp = head;
	int val = temp->nilai;

	head = head->next;

	if(head == NULL) tail = NULL;

	free(temp);
	return val;
}

//push front
void pushStack(int angka){
	struct data *curr = (struct data*)malloc(sizeof(struct data));
	curr->nilai = angka;
	curr->next = top;
	top = curr;
}

//front pop
int popStack(){
	if(top == NULL) return -1;

	struct data *temp = top;
	int val = temp->nilai;

	top = top->next;
	free(temp);

	return val;
}

int topStack(){
	if(top == NULL) return -1;
	return top->nilai;
}

int queueSize(){
	int count = 0;
	struct data *curr = head;
	while(curr){
		count++;
		curr=curr->next;
	}
	
	return count;
}

int main(){
	int N;
	scanf("%d", &N);
	
	int dev[N], proj[N];
	for(int i=0; i<N; i++){
		scanf("%d", &dev[i]);
		pushQueue(dev[i]);
	}
	
	for(int i= N-1; i >= 0; i--){
		scanf("%d", &proj[i]);
		pushStack(proj[i]);
	}
	
	int rot = 0;
	
	while(head != NULL && top != NULL){
		int frontDev = popQueue();
		int topProj = topStack();
		
		if(frontDev == topProj){
			popStack();
			rot = 0;
		}else{
			pushQueue(frontDev);
			rot++;
		}
		
		if(rot == queueSize()){
			break;
		}
	}
	
	printf("%d\n", queueSize());
}

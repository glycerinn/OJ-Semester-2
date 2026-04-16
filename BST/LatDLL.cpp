#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct data{
	int prio;
	char nama[100];
	struct data *next;
	struct data *prev;
}*head, *tail;

void push(char prio[], char name[]){
	int p;
	if(strcmp(prio, "Critical")==0){
		p = 1;
	}else if(strcmp(prio, "Serious")==0){
		p = 2;
	}else if(strcmp(prio, "Fair")==0){
		p = 3;
	}else if(strcmp(prio, "Good")==0){
		p = 4;
	}
	
	struct data *curr= (struct data*)malloc(sizeof(struct data));
	curr->prio = p;
	strcpy(curr->nama, name);
	curr->next = NULL;
	curr->prev = NULL;
	
	if(head == NULL){
		head = tail = curr;
	}else{
		if(p == 4){
			curr->prev = tail;
			tail->next = curr;
			tail = curr;
		}else{
			struct data *temp = head;
			while(temp->prio < p+1){
				temp = temp->next;
				if(temp==NULL) break;
			}
			
			if(temp==NULL){
				curr->prev=tail;
				tail->next = curr;
				tail= curr;
			}else{
				if(temp==head){
					curr->next = head;
					head->prev = curr;
					head = curr;
				}else{
					curr->next = temp;
					curr->prev = temp->prev;
					temp->prev->next = curr;
					temp->prev = curr;
				}
			}
		}
	}
}

void printrest(){
	printf("Waiting room: ");
	struct data *temp = head;
	if(temp != NULL){
		while(temp!= NULL){
			printf("%s", temp->nama);
			if(temp->next != NULL){
				printf(", ");
			}
			temp = temp->next;
		}
	}else{
		printf("None");
	}
	printf("\n");
}

void pop(){
	struct data *curr = head;
	while(curr != NULL){
		head = head->next;
		head->prev = NULL;
		printf("%s is in the consultation room\n", curr->nama);
		free(curr);
		return;
	}
	
	
}

int main(){
	head = tail = NULL;
	
	int N;
	char A[100], prio[100], name[100];
	scanf("%d", &N);
	
	for(int i = 0; i < N; i++){
		scanf("%s", A);
		getchar();
		if(strcmp(A, "ADD") == 0){
			scanf("%s %s", &name, &prio);
			getchar();
			push(prio, name);
		}else if(strcmp(A, "CALL") == 0){
			pop();
		}
	}
	
	printrest();
}

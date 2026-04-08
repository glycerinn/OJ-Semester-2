#include<stdio.h>
#include<stdlib.h>

struct data{
	int id;
	struct data *next;
};

struct data *Ohead = NULL, *Otail = NULL;
struct data *Whead = NULL, *Wtail = NULL;
struct data *Hhead = NULL, *Htail = NULL;

void PushO(int angka){
	struct data *curr = (struct data*)malloc(sizeof(struct data));
	curr->id = angka;
	curr->next = NULL;
	
	if(Ohead == NULL){
		Ohead = Otail = curr;
	}else{
		Otail->next = curr;
		Otail = curr;
	}
}

int PopO(){
	if(Ohead == NULL) return -1;
	
	struct data* temp = Ohead;
	int val = temp->id;
	
	Ohead = Ohead->next;
	
	if(Ohead == NULL) Otail = NULL;
	free(temp);
	
	return val;
}

void PushW(int angka){
	struct data *curr = (struct data*)malloc(sizeof(struct data));
	curr->id = angka;
	curr->next = NULL;
	
	if(Whead == NULL){
		Whead = Wtail = curr;
	}else{
		Wtail->next = curr;
		Wtail = curr;
	}
}

int PopW(){
	if(Whead == NULL) return -1;
	
	struct data* temp = Whead;
	int val = temp->id;
	
	Whead = Whead->next;
	
	if(Whead == NULL) Wtail = NULL;
	free(temp);
	
	return val;
}

void PushH(int angka){
	struct data *curr = (struct data*)malloc(sizeof(struct data));
	curr->id = angka;
	curr->next = NULL;
	
	if(Hhead == NULL){
		Hhead = Htail = curr;
	}else{
		Htail->next = curr;
		Htail = curr;
	}
}

void printH(){
	struct data *temp = Hhead;
	while(temp != NULL){
		printf("%d ", temp->id);
		temp = temp->next;
	}
}

void popH(int x){
	struct data* curr = Hhead;
	struct data *temp = NULL;
	
	while(curr != NULL){
		if(curr->id == x){
			if(curr == Hhead){
				Hhead = curr->next;
				free(curr);
				curr = Hhead;
			}else{
				temp->next = curr->next;
				
				if(curr == Htail){
					Htail = temp;
				}
				
				free(curr);
				curr = temp->next;
			}
		}
		else{
			temp = curr;
			curr = curr->next;
		}
	}
}

int main(){
	int N, M, onl, walk;
	scanf("%d %d", &N, &M);
	
	for(int i = 0; i < N; i++){
		scanf("%d", &onl);
		PushO(onl);
	}
	
	for(int i = 0; i < M; i++){
		scanf("%d", &walk);
		PushW(walk);
	}
	
	int P, canc[N+M-1];
	scanf("%d", &P);
	
	for(int i = 0; i < P; i++){
		scanf("%d", &canc[i]);
	}
	
	while(Ohead != NULL || Whead != NULL){
		if(Ohead != NULL){
	        int o = PopO();
	        PushH(o);
	    }
	
	    if(Whead != NULL){
	        int w = PopW();
	        PushH(w);
	    }
	}
	
	for(int i = 0; i < P; i++){
		popH(canc[i]);
	}
	
	printH();
	printf("\n");
}

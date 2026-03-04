#include<stdio.h>
#include<stdlib.h>

struct data
{
	int nilai;
	struct data *next;	
}*head, *tail;

void pushdepan(int angka)
{
	struct data *curr =(struct data *) malloc(sizeof(struct data));
	curr->nilai = angka;
	curr->next = NULL;
	
	if (head == NULL)		//data masih kosong
	{
		head = tail = curr;
	}
	else	//data sudah ada
	{
		curr->next = head;
		head = curr;
	}
}

void pushbelakang(int angka)
{
	struct data *curr =(struct data *) malloc(sizeof(struct data));
	curr->nilai = angka;
	curr->next = NULL;
	
	if (head == NULL)		//data masih kosong
	{
		head = tail = curr;
	}
	else	//data sudah ada
	{
		tail->next = curr;
		tail = curr;
	}
}

void pushtengah(int index, int angka)
{
	struct data *curr =(struct data *) malloc(sizeof(struct data));
	curr->nilai = angka;
	curr->next = NULL;
	
	if (head == NULL)		//data masih kosong
	{
		head = tail = curr;
	}
	else	//data sudah ada
	{
		struct data *temp = head;
		for(int i = 0 ; i < index ; i++)
		{
			if (temp != NULL)
				temp = temp->next;
			else
			{
				free(curr);
				return;
			}
		}
		
		curr->next = temp->next;	
		temp->next = curr;
		
		if(curr->next == NULL)
			tail = curr;
	}
}

void popdepan()
{
	if (head == NULL)
		return;
		
	struct data *temp = head;
	head = head->next;
	
	free(temp);
}

void popbelakang()
{
	if (head == NULL)
		return;
	
	struct data *temp = head;
	while (temp->next != tail)
		temp = temp->next;
		
	free(tail);
	tail = temp;
	tail->next = NULL;
	
}

void poptengah(int index)
{
	if (head == NULL)
		return;
	
	struct data *temp = head;
	for(int i = 0 ; i < index-1 ; i++)
		temp = temp->next;
		
	struct data *temp2 = temp->next;
		
	temp->next = temp2->next;
	free(temp2);
	
}

void popall()
{
	while (head != NULL)
		popdepan();
	
	head = tail = NULL;
}

void push(int angka)
{
	struct data *curr =(struct data *) malloc(sizeof(struct data));
	curr->nilai = angka;
	curr->next = NULL;
	
	if (head == NULL)	//data kosong
	{
		//pushdepan(angka);
		head = tail = curr;
	}
	else
	{
		if (angka <= head->nilai)
		{
			curr->next = head;
			head = curr;
		}
		else if (angka >= tail->nilai)
		{
			tail->next = curr;
			tail = curr;
		}
		else
		{
			struct data *temp = head;
			int a = 0;
			while (temp->next->nilai < angka)
			{
				temp = temp->next;
				a++;
			}
			//pushtengah(a, angka);
			//a = 2
			
			curr->next = temp->next;
			temp->next = curr;
		}
	}
}

void pop(int angka)
{
	if (head == NULL)
		return;
	
	if (angka == head->nilai)
	{
		popdepan();
	}
	else if (angka == tail->nilai)
	{
		popbelakang();
	}
	else
	{
		struct data *temp = head;
		int idx = 0;
		while (temp != NULL)
		{
			if (temp->nilai == angka)
			{
				//ketemu
				poptengah(idx);
			}
			else
			{
				temp = temp->next;
				idx++;
			}
		}
	}
}

void printall()
{
	struct data *temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->nilai);
		temp = temp->next;
	}
}
int main()
{
	head = tail = NULL;
	push(2);
	push(10);
	push(1);
	push(5);
	push(7);
	push(9);
	push(100);
	push(20);
	push(50);
	
	printall();
	popdepan();
	popbelakang();
	poptengah(2);
	
	pop(1);
	
	popall();
	/*
	printf("%d", head->nilai);	//10
	
	printf("%d", head->next->next->next->nilai);	//1
	
	struct data *curr = head;
	for(int i = 0 ; i < 5 ; i++)
		curr = curr->next;
		
	printf("%d", curr->nilai);
	*/
	return 0;
}

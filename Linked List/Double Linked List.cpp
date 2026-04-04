#include<stdio.h>
#include<stdlib.h>

struct data
{
	int nilai;
	struct data *next;
	struct data *prev;	
}*head, *tail;

void pushdepan(int angka)
{
	struct data *curr =(struct data *) malloc(sizeof(struct data));
	curr->nilai = angka;
	curr->next = NULL;
	curr->prev = NULL;		
	
	if (head == NULL)	
	{
		head = tail = curr;
	}
	else
	{
		curr->next = head;
		head->prev = curr;	
		head = curr;
	}
}

void pushbelakang(int angka)
{
	struct data *curr =(struct data *) malloc(sizeof(struct data));
	curr->nilai = angka;
	curr->next = NULL;
	curr->prev = NULL;
	
	if (head == NULL)	
	{
		head = tail = curr;
	}
	else	
	{
		tail->next = curr;
		curr->prev = tail;	
		tail = curr;
	}
}

void pushtengah(int index, int angka)
{
	struct data *curr =(struct data *) malloc(sizeof(struct data));
	curr->nilai = angka;
	curr->next = NULL;
	curr->prev = NULL;		
	
	if (head == NULL)		
	{
		head = tail = curr;
	}
	else
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
		curr->prev = temp;		
		
		temp->next = curr;
		curr->next->prev = curr;
		
		
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
	
	if (head != NULL)
		head->prev = NULL;	
	
	free(temp);
}

void popbelakang()
{
	if (head == NULL)
		return;
	
	struct data *temp = tail;
	tail = tail->prev;
	
	if (tail != NULL)
		tail->next = NULL;
	
	free(temp);
}

void poptengah(int index)
{
	if (head == NULL)
		return;
	
	struct data *temp = head;
	for(int i = 0 ; i < index ; i++)
		temp = temp->next;
		
	temp->prev->next = temp->next;
	temp->next->prev = temp->prev;
	
	free(temp);
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
	curr->prev = NULL;	
	
	if (head == NULL)
	{
		head = tail = curr;
	}
	else
	{
		if (angka <= head->nilai)
		{
			curr->next = head;
			head->prev = curr;	
			head = curr;
		}
		else if (angka >= tail->nilai)
		{
			tail->next = curr;
			curr->prev = tail;	
			tail = curr;
		}
		else
		{
			struct data *temp = head;
			while (temp->nilai < angka)
			{
				temp = temp->next;
			}
			curr->next = temp;
			curr->prev = temp->prev;
			
			curr->prev->next = curr;
			temp->prev = curr;
			
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
				poptengah(idx);
				return;
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
	
	pop(7);
	
	printall();
	
	
	
	return 0;
}

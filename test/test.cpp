#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct data 
{
	int id;
	int prio;
	double duration;
	char nama[100];
	struct data *next;
	struct data *prev;
}*head, *tail, *curr;

void push(int id, char prio, double balance, char n[] )
{
	int p;
	if (prio == 'e')
		p = 1;
	else if (prio == 'p')
		p = 2;
	else
		p = 3;
		
	int dur = balance/ 10.0;
	//printf("%d %lf\n", p, dur);
	curr = (struct data *) malloc(sizeof(struct data));
	curr->id = id;
	curr->prio = p;
	curr->duration = dur;
	strcpy(curr->nama, n);
	curr->next = curr->prev = NULL;
	if (head == NULL)
	{
		head = tail = curr;
	}
	else
	{
		if (p == 3)
		{
			curr->prev = tail;
			tail->next = curr;
			tail = curr;
		}
		else 
		{
			struct data *temp = head;
			while (temp->prio < p+1)
			{
				temp = temp->next;
				if (temp == NULL) break;
			}
			if (temp == NULL)
			{
				curr->prev = tail;
				tail->next = curr;
				tail = curr;
			}
			else
			{
				if (temp == head)
				{
					curr->next = head;
					head->prev = curr;
					head = curr;
				}
				else
				{
					curr->next = temp;
					curr->prev = temp->prev;
					temp->prev->next = curr;
					temp->prev = curr;
				}
			}
		}
	}
}

void pop(char n[])
{
	struct data *temp = head;
	while (temp != NULL)
	{
		if (strcmp(temp->nama, n) == 0)
		{
			if (temp == head)
			{
				head = head->next;
				if (head != NULL)
					head->prev = NULL;
				else
					head = tail = NULL;
				free(temp);
			}
			else if (temp == tail)
			{
				tail = temp->prev;
				tail->next = NULL;
				free(temp);
				
			}
			else
			{
				temp->prev->next = temp->next;
				temp->next->prev = temp->prev;
				free(temp);
			}
			return;
		}
		else
		{
			temp = temp->next;
		}
	}
}

void printall()
{
	int i = 0;
	curr = head;
	if (curr == NULL)
		printf("Empty List");
	else
		while (curr != NULL)
		{
			if (i == 0)
			{
				printf("ID:%d(P%d) - %s - %.0lf min", curr->id, curr->prio, curr->nama, curr->duration);
				i = 1;
			}
			else
				printf(" <-> ID:%d(P%d) - %s - %.0lf min", curr->id, curr->prio, curr->nama, curr->duration);
			
			curr = curr->next;
		}
	printf("\n");
}

void popall()
{
	while (head != NULL)	
	{
		curr = head;
		head = head->next;
		free(curr);
	}
	head = tail = NULL;
}
int main()
{
	int id = 1;
	head = tail = curr = NULL;
	int n;
	scanf("%d", &n);
	getchar();
	for(int ii = 0 ; ii < n ; ii++)
	{
		char i, p;
		double b;
		char name[100];
		scanf("%c", &i);
		getchar();
		if (i == 'i')
		{
			scanf("%c %lf %s", &p, &b, &name);
			getchar();
			push(id,p, b, name);
			id++;
		}
		if (i == 'x')
		{
			scanf("%s", &name);
			getchar();
			pop(name);
		}
	}
	printall();
	popall();
	return 0;
}

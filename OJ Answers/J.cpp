#include<stdio.h>
#include<stdlib.h>

struct data
{
	int nilai;
	struct data *next;
	struct data *prev;	
}*head, *tail;

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

void merge(struct data **headA, struct data **tailA,
           struct data **headB, struct data **tailB)
{
    // If B empty ? nothing
    if (*headB == NULL) return;

    // If A empty ? A becomes B
    if (*headA == NULL)
    {
        *headA = *headB;
        *tailA = *tailB;
    }
    else
    {
        // Connect A tail to B head
        (*tailA)->next = *headB;
        (*headB)->prev = *tailA;

        // Update tailA
        *tailA = *tailB;
    }

    // Make B empty
    *headB = NULL;
    *tailB = NULL;
}

void pushbelakang(struct data **head, struct data **tail, int angka)
{
    struct data *curr =(struct data *) malloc(sizeof(struct data));
    curr->nilai = angka;
    curr->next = NULL;
    curr->prev = NULL;
    
    if (*head == NULL)	
    {
        *head = *tail = curr;
    }
    else	
    {
        (*tail)->next = curr;
        curr->prev = *tail;	
        *tail = curr;
    }
}

void printall(struct data *head)
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
    struct data *headA = NULL, *tailA = NULL;
    struct data *headB = NULL, *tailB = NULL;

    int N, M, x;
    scanf("%d %d", &N, &M);

    // Input A
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &x);
        pushbelakang(&headA, &tailA, x);
    }

    // Input B
    for (int i = 0; i < M; i++)
    {
        scanf("%d", &x);
        pushbelakang(&headB, &tailB, x);
    }

    // Merge B into A
    merge(&headA, &tailA, &headB, &tailB);

    // Output
    printall(headA);

    return 0;
}

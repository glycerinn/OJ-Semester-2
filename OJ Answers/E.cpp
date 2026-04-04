#include<stdio.h>
#include<stdlib.h>

struct data
{
    int nilai;
    struct data *next;
    struct data *prev;	
} *head = NULL, *tail = NULL;


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

void deleteOdd()
{
    struct data *curr = head;

    while (curr != NULL)
    {
        struct data *nextNode = curr->next; 

        if (curr->nilai % 2 != 0) // odd
        {
            // Case 1: only one node
            if (curr == head && curr == tail)
            {
                head = tail = NULL;
            }
            // Case 2: delete head
            else if (curr == head)
            {
                head = curr->next;
                head->prev = NULL;
            }
            // Case 3: delete tail
            else if (curr == tail)
            {
                tail = curr->prev;
                tail->next = NULL;
            }
            // Case 4: middle node
            else
            {
                curr->prev->next = curr->next;
                curr->next->prev = curr->prev;
            }

            free(curr);
        }

        curr = nextNode; 
    }
}

void printall()
{
    if (head == NULL)
    {
        printf("-1\n");
        return;
    }

    struct data *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->nilai);
        temp = temp->next;
    }
}

int main()
{
    int N, x;
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &x);
        pushbelakang(x);
    }

    deleteOdd();

    printall();

    return 0;
}

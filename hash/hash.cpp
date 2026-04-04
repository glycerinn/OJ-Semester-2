#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct hash
{
	char kata[100];
	struct hash *next;
}*head[26], *tail[26];

int hashfunction(char str[])
{
	int key;
	
	if (str[0] < 'a')
		key = str[0] - 'A';
	else
		key = str[0] - 'a';
	return key;
}

void insert(char str[])
{
	//1
	int key = hashfunction(str);
	
	//2
	struct hash *temp = (struct hash *) malloc(sizeof(struct hash));
	temp->next = NULL;
	strcpy(temp->kata,str);

	if (head[key] == NULL)
	{
		head[key] = tail[key] = temp;
	}
	else
	{
		tail[key]->next = temp;
		tail[key] = temp;
	}
}

int search(char str[])
{
	//1
	int key = hashfunction(str);
	
	//2
	if (head[key] == NULL)
	{
		return 0;
	}
	else
	{
		struct hash *temp = head[key];
		while (temp != NULL)
		{
			if (strcmp(temp->kata, str) == 0 )	// kata nya sama
				return 1;
			else
				temp = temp->next;
		}
		return 0;
	}
}

void printall()
{
	for (int i = 0 ; i< 26 ; i++)
	{
		if (head[i] != NULL)
		{
			struct hash *temp = head[i];
			while (temp != NULL)
			{
				if (temp == head[i])
					printf("%s", temp->kata);
				else
					printf(" - %s", temp->kata);
					
				temp = temp->next;
			}
			printf("\n");
		}
	}
}

void popdepan(int idx)
{
	if (head[idx] == NULL)
	{
		return;
	}
	struct hash *temp = head[idx];
	head[idx] = head[idx]->next;
	free(temp);
}

void popall()
{
	for(int i = 0 ; i < 26 ; i++)
	{
		while (head[i] != NULL)
		{
			popdepan(i);
		}
		head[i] = tail[i] = NULL;
	}
}

int main()
{
	for(int i = 0 ; i < 26 ; i++)
	{
		head[i] = tail[i] = NULL;
	}
	
	insert("jambu");
	insert("jeruk");
	insert("jam");
	insert("Jagung");
	insert("jelly");
	insert("jus");
	insert("apel");
	insert("ayam");
	
	int hasil;
	
	hasil = search("juus");
	if (hasil == 0)
		printf("FALSE\n");
	else
		printf("TRUE\n");
	
	hasil = search("Jagung");
	printf("%s\n", hasil == 0?"FALSE":"TRUE");
	
	printall();
	
	popall();
	
	return 0;
}

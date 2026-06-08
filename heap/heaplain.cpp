#include<stdio.h>

int arr[20];
int idx = 0;

void insert(int angka)
{
	idx++;
	arr[idx] = angka;


	//upheap
	int temp = idx;
	int tukar = 0;
	do
	{
		tukar = 0;

		if (arr[temp] < arr[temp/2] && temp != 1)
		{
			int curr = arr[temp];
			arr[temp] = arr[temp/2];
			arr[temp/2] = curr;
			temp = temp/2;
			tukar = 1;
		}
	}while(tukar == 1);
}

void del()
{
	if (idx == 0)
	{
		printf("Tidak ada data\n");
		return;
	}
	printf("Delete angka %d\n", arr[1]);
	
	arr[1] = arr[idx];
	
	idx--;
	
	//downheap
	int temp = 1;
	int cl, cr;
	int tukar = 0;
	do
	{
		tukar = 0;
		cl = temp * 2 > idx ? 0 : temp * 2;
		cr = temp * 2 + 1 > idx ? 0 : temp * 2 + 1;
		//printf("%d %d %d %d %d %d\n", temp, cl, cr, arr[temp], arr[cl], arr[cr]);
		if (arr[cl] < arr[cr])
		{
			if ( arr[cl] < arr[temp])
			{
				int curr = arr[temp];
				arr[temp] = arr[cl];
				arr[cl] = curr;
				temp = cl;
				tukar = 1;
			}
		}
		else
		{
			if ( arr[cr] < arr[temp])
			{
				int curr = arr[temp];
				arr[temp] = arr[cr];
				arr[cr] = curr;
				temp = cr;
				tukar = 1;
			}
		}
	}while (tukar == 1);
	

}

int main()
{
	arr[0] = 99999999;
	insert(10);
	insert(5);
	insert(7);
	insert(100);
	insert(54);
	insert(15);
	insert(25);
	insert(8);
	insert(6);
	
	for(int i = 1 ; i< idx ; i++)
	{
		printf("%d\n", arr[i]);
	}
	del();
	del();
	del();
	del();
	del();
	del();
	del();
	del();
	del();
	del();
	
	return 0;
}

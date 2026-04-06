#include <stdio.h>
#include <ctype.h>

struct data
{
	int angka;
	int op;		//0 = operand, 1 == operator
};

char stack[100];
int top = -1;
struct data hasil[100];
int k = 0;

void push(char x) {
    stack[++top] = x;
}

char pop() {
    return stack[top--];
}

void convert(char str[], int idx)
{
	if (idx == 0 ) return;
	int angka = 0;
    int multiplier = 1;
    for(int xx = idx-1 ; xx >= 0 ; xx--)
    {
    	angka = angka + 
		(
			(str[xx] - '0') * multiplier
		);
    	multiplier *= 10;
	}
    hasil[k].angka = angka;
    hasil[k].op = 0;
    k++;
}

int priority(char x) {
    if (x == '(') return 0;
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/') return 2;
    return 0;
}

int main() {
    char infix[100], postfix[100];
    int i = 0, j = 0;

    scanf("%s", infix);

    while (infix[i] != '\0') {

        if (isdigit(infix[i])) {
            postfix[j++] = infix[i];
        }

        else if (infix[i] == '(') {
        	
            push(infix[i]);
        }

        else if (infix[i] == ')') {
        	//convert
            convert(postfix, j);
            j = 0;
            while (stack[top] != '(') {
                hasil[k].angka = pop();
                hasil[k].op = 1;
                k++;
            }
            pop(); // delete '('
        }

        else { // operator
        	
			//convert
            convert(postfix, j);
            j = 0;
            while (
			top != -1 
					&&
            priority(stack[top]) >= priority(infix[i])
			) 
			{
                hasil[k].angka = pop();
                hasil[k].op = 1;
                k++;
            } 
            push(infix[i]);
        }

        i++;
    }

	convert(postfix, j);
	j = 0;

    while (top != -1) {
        hasil[k].angka = pop();
        hasil[k].op = 1;
        k++;
    }

    //postfix[j] = '\0';

	for(int xx = 0 ; xx < k ; xx++)
	{
		if (hasil[xx].op == 0)
			printf("%d ", hasil[xx].angka);
		else if(hasil[xx].op == 1)
			printf("%c ", hasil[xx].angka);
	}
	printf("\n\n");
    //printf("%s\n", postfix);
	
	for(int xx = 0 ; xx < k ; xx++)
	{
		if (hasil[xx].op == 1)
		{
			int yy = xx-2;
			int zz = xx-1;
			switch(hasil[xx].angka)
			{
				case '+':
					hasil[yy].angka = hasil[yy].angka + hasil[zz].angka;
					break;
				case '-':
					hasil[yy].angka = hasil[yy].angka - hasil[zz].angka;
					break;
				case '*':
					hasil[yy].angka = hasil[yy].angka * hasil[zz].angka;
					break;
				case '/':
					hasil[yy].angka = hasil[yy].angka / hasil[zz].angka;
					break;
			}
			hasil[yy].op = 0;
			
			//shifting
			for(int kk = xx+1 ; kk < k ; kk++)
			{
				hasil[kk-2] = hasil[kk];
			}
			k -= 2;
			xx -= 2;
		}
			
	}
	
	printf("%d\n", hasil[0].angka);
    return 0;
}

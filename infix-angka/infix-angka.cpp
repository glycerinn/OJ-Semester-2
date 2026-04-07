#include <stdio.h>
#include <ctype.h>

// Structure to store postfix elements
struct data
{
	int angka;     // stores number OR operator (as ASCII)
	int op;        // 0 = operand (number), 1 = operator
};

char stack[100];   // stack for operators
int top = -1;      // stack top (starts empty)
struct data hasil[100]; // array to store postfix expression
int k = 0;         // size of hasil[]

void push(char x) {
    stack[++top] = x; // increment top, then insert
}

char pop() {
    return stack[top--]; // return top element, then decrement
}

// Convert collected digits (char array) into integer
void convert(char str[], int idx)
{
	if (idx == 0 ) return; // if no digits, do nothing
	
	int angka = 0;
    int multiplier = 1;

    // convert from string (e.g. "123") to integer
    for(int xx = idx-1 ; xx >= 0 ; xx--)
    {
    	angka = angka + 
		(
			(str[xx] - '0') * multiplier
		);
    	multiplier *= 10;
	}

    // store as operand in hasil[]
    hasil[k].angka = angka;
    hasil[k].op = 0;
    k++;
}

// Operator precedence
int priority(char x) {
    if (x == '(') return 0;
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/') return 2;
    return 0;
}

int main() {
    char infix[100], postfix[100]; // postfix[] used as temporary number buffer
    int i = 0, j = 0; // i = infix index, j = postfix buffer index

    scanf("%s", infix);

    // ===== INFIX TO POSTFIX CONVERSION =====
    while (infix[i] != '\0') {

        // If digit ? store in postfix buffer
        if (isdigit(infix[i])) {
            postfix[j++] = infix[i];
        }

        // If '(' ? push to stack
        else if (infix[i] == '(') {
            push(infix[i]);
        }

        // If ')' ? process until '('
        else if (infix[i] == ')') {
        	// convert any number collected before ')'
            convert(postfix, j);
            j = 0;

            // pop operators until '('
            while (stack[top] != '(') {
                hasil[k].angka = pop(); // store operator
                hasil[k].op = 1;
                k++;
            }

            pop(); // remove '(' (not stored)
        }

        // If operator (+, -, *, /)
        else {
        	// convert any number collected before operator
            convert(postfix, j);
            j = 0;

            // pop operators with higher/equal precedence
            while (
			    top != -1 &&
                priority(stack[top]) >= priority(infix[i])
			) 
			{
                hasil[k].angka = pop();
                hasil[k].op = 1;
                k++;
            }

            // push current operator
            push(infix[i]);
        }

        i++;
    }

    // convert last number (if any)
	convert(postfix, j);
	j = 0;

    // pop remaining operators
    while (top != -1) {
        hasil[k].angka = pop();
        hasil[k].op = 1;
        k++;
    }

    // ===== PRINT POSTFIX =====
	for(int xx = 0 ; xx < k ; xx++)
	{
		if (hasil[xx].op == 0)
			printf("%d ", hasil[xx].angka); // operand
		else if(hasil[xx].op == 1)
			printf("%c ", hasil[xx].angka); // operator
	}
	printf("\n\n");

    // ===== EVALUATE POSTFIX =====
	for(int xx = 0 ; xx < k ; xx++)
	{
		// if operator found
		if (hasil[xx].op == 1)
		{
			int yy = xx-2; // left operand
			int zz = xx-1; // right operand

			// perform operation
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

			hasil[yy].op = 0; // result becomes operand

			// shift array left by 2 positions (remove used operands + operator)
			for(int kk = xx+1 ; kk < k ; kk++)
			{
				hasil[kk-2] = hasil[kk];
			}

			k -= 2;   // reduce size
			xx -= 2;  // move index back to re-evaluate
		}
	}

    // final result
	printf("%d\n", hasil[0].angka);

    return 0;
}

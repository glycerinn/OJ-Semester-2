#include <stdio.h>
#include <ctype.h>
#include <string.h>

int prec(char op) {
    if (op=='+' || op=='-') return 1;
    else if (op=='*' || op=='/') return 2;
    else return 0;
}

int main() {
    char infix[100];
	char postfix[100]; 
	char stack[100];
    int top=-1;
	int j=0;

    scanf("%s",infix);
	int len=strlen(infix);
	
    for(int i=0;i<len;i++) {
        char c=infix[i];
        if (isdigit(c)) postfix[j++] = c;
        else if (c=='(') stack[++top]=c;	
        else if (c==')') {
			while(top!=-1 && stack[top]!='(') 
            postfix[j++]=stack[top--];
            top--;	
        } else {
            while(top!=-1 && prec(stack[top])>=prec(c))
                postfix[j++]=stack[top--];
            stack[++top]=c;
        }
    }

    while(top!=-1) postfix[j++]=stack[top--];
    postfix[j]='\0';

    printf("postfix: %s\n", postfix);
    return 0;
}

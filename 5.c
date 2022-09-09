#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int top = -1;
char stack[100];

// function prototypes
void push(char);
void pop();
void find_top();

void main()
{
	int i;
	char a[100];
	printf("enter your expression\n");
	scanf("%s", &a);
	for (i = 0; a[i] != '\0';i++)
	{
		if (a[i] == '(')
		{
			push(a[i]);
		}
		else if (a[i] == ')')
		{
			pop();
		}


		else if (a[i] == '[')
		{
			push(a[i]);
		}
		else if (a[i] == ']')
		{
			pop();
		}

		else if (a[i] == '{')
		{
			push(a[i]);
		}
		else if (a[i] == '}')
		{
			pop();
		}
	}

	find_top();
}


void push(char a)
{
	stack[top] = a;
	top++;
}


void pop()
{
	if (top == -1)
	{
		printf("expression is invalid\n");
		exit(0);
	}
	else
	{
		top--;
	}
}


void find_top()
{
	if (top == -1)
		printf("\nexpression is correct expression\n");
	else
		printf("\nexpression is incorrect expression\n");
}

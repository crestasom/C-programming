#include <stdio.h>
#include <string.h>
void push(char);
char pop();
char stack[100];
int top = -1;
main()
{
	char str[100],strrev[100];
	char c;
	int i, count = 0, len;
	printf("Enter string to check it is palindrome or not : ");
	scanf("%s", str);
	len = strlen(str);
	for (i = 0; i < len; i++)
	{
		push(str[i]);
	}
	for (i = 0; i < len; i++)
	{
		c=pop();
		strrev[i]=c;
		if (str[i] == c)
		count++;
	}
	if (strcmp(str,strrev) == 0)
		printf("%s is a Palindrome string\n", str);
	else
		printf("%s is not a palindrome string\n", str);
}

/* Function to push character into stack */
void push(char c)
{
	stack[++top] = c;
}

/* Function to pop the top character from stack */
char pop()
{
	return(stack[top--]);
}
#include<stdio.h>
#include<stdlib.h>     
#include<ctype.h> 
#include<string.h>

#define MAX 100

char stack[MAX];
int back = -1;

void f_push(char ch)
{
	if (back >= MAX - 1)
	{
		printf("\n스택 오버플로우.");
	}
	else
	{
		back = back + 1;
		stack[back] = ch;
	}
}
char f_pop()
{
	char data;

	if (back < 0)
	{
		printf("스택 언더 플로우\n");
		getchar();
		exit(1);
	}
	else
	{
		data = stack[back];
		back = back - 1;
		return(data);
	}
}

int is_operator(char op)
{
	if (op == '^' || op == '*' || op == '/' || op == '+' || op == '-')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int priority(char op)
{
	if (op == '^')
	{
		return(3);
	}
	else if (op == '*' || op == '/')
	{
		return(2);
	}
	else if (op == '+' || op == '-')
	{
		return(1);
	}
	else
	{
		return(0);
	}
}

void makePostfix(char infix[], char postfix[])
{
	int next, tail;
	char var;
	char temp;

	f_push('(');                               
	strcat(infix, ")");                  

	next = 0;
	tail = 0;
	var = infix[next];         

	while (var != '\0')        
	{
		if (var == '(')
		{
			f_push(var);
		}
		else if (isdigit(var) || isalpha(var))
		{
			postfix[tail] = var;             
			tail++;
		}
		else if (is_operator(var) == 1)       
		{
			temp = f_pop();
			while (is_operator(temp) == 1 && priority(temp) >= priority(var))
			{
				postfix[tail] = temp;                  
				tail++;
				temp = f_pop();                       
			}
			f_push(temp);
			f_push(var);                 
		}
		else if (var == ')')       
		{
			temp = f_pop();                  
			while (temp != '(')             
			{
				postfix[tail] = temp;
				tail++;
				temp = f_pop();
			}
		}
		else
		{
			printf("\n잘못된 수식입니다.\n");
			getchar();
			exit(1);
		}
		next++;


		var = infix[next];
	}
	if (back > 0)
	{
		printf("\n잘못된 수식입니다.\n");
		getchar();
		exit(1);
	}
	if (back > 0)
	{
		printf("\n잘못된 수식입니다.\n");
		getchar();
		exit(1);
	}
	postfix[tail] = '\0';
}
int main()
{
	char infix[MAX], postfix[MAX];
	printf("수식 변환기 : 한 글자의 문자나 숫자들로 이루어진 수식을 입력하면 됩니다. \n");
	printf("\n수식 입력 : ");
	gets(infix);

	makePostfix(infix, postfix);             
	printf("결과: ");
	puts(postfix);     
	system("pause");
	return 0;
}

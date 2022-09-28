#include <stdio.h>
#include <string.h>

#define maxLn 1000
int main()
{
	char str[maxLn] = "";

	printf("Max size of string is 1000 signs. Enter string = ");
	scanf_s("%s",&str);

 	char stack[maxLn] = {};
	int len = strlen(str);
	int curPosition = 0;
	int isCorrectStr = 1;

	for(int i = 0; i < len;++i)
	{
		switch(str[i])
		{
			case '(':
			case '[':
			case '{':
				stack[curPosition] = str[i];
				curPosition++;
				break;
			case ')':
				if (stack[curPosition - 1] == '(')
				{
					curPosition -= 1;
				}
				else
				{
					isCorrectStr = 0;
				}
				break;
			case ']':
				if (stack[curPosition - 1] == '[')
				{
					curPosition -= 1;
				}
				else
				{
					isCorrectStr = 0;
				}
				break;
			case '}':
				if (stack[curPosition - 1] == '{')
				{
					curPosition -= 1;
				}
				else
				{
					isCorrectStr = 0;
				}
				break;
			default:
				break;
									
		}
		if (!isCorrectStr)
		{
			break;
		}
	}
	if (isCorrectStr && curPosition == 0)
	{
		printf("The string is correct");
	}
	else
	{
		printf("The string is wrong");
	}
	return 0;
}
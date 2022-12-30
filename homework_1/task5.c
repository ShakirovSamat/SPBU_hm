#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define maxLn 1000

int main()
{
	char str[maxLn] = "";

	printf("Max size of string is 1000 signs. Enter string = ");
	scanf_s("%s", &str);

 	char stack[maxLn] = {};
	int len = strlen(str);
	int curPosition = 0;
	bool isCorrectStr = true;

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
					isCorrectStr = false;
				}
				break;
			case ']':
				if (stack[curPosition - 1] == '[')
				{
					curPosition -= 1;
				}
				else
				{
					isCorrectStr = false;
				}
				break;
			case '}':
				if (stack[curPosition - 1] == '{')
				{
					curPosition -= 1;
				}
				else
				{
					isCorrectStr = false;
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
		printf("The string is correct\n");
	}
	else
	{
		printf("The string is wrong\n");
	}
	return 0;
}
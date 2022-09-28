#include <stdio.h>
#include <string.h>

#define maxLn 1000

int main()
{
	char string[maxLn];
	char substring[maxLn];
	int count = 0;

	printf("The program counts the number of subtrings in a string. Max length of a string and a substring is 1000 chars\n");

	printf("Enter the string = ");
	scanf_s("%s", &string);

	printf("Enter the substring = ");
	scanf_s("%s", &substring);

	int stringLen = strlen(string);
	int substringLen = strlen(substring);
	for(int i = 0; i < stringLen - substringLen + 1; ++i)
	{
		int isSubstring = 1;
		for(int j = i; j < i + substringLen; ++j)
		{
			if (string[j] != substring[j - i]){
				isSubstring = 0;
				break;
			}
		}
		if (isSubstring) ++count; 
	}
	
	printf("Number of substring in string is %d\n", count);
	return 0;
}
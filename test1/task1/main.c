#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>


int isPalindrome(char str[], int len)
{
    int i = 0;
    int j = len - 1;
    while (i < j)
    {
        if (str[i] != str[j])
        {
            return 0;
        }
        ++i;
        --j;
    }
    return 1;
}

int test()
{
    char palindroms[2][6] = {"123321", "sossos"};
    char notPalindroms[2][6] = {"123456", "sososo"};
    if (!isPalindrome(palindroms[0], 6) || !isPalindrome(palindroms[1], 6))
    {
        return 0;
    }
    if (isPalindrome(notPalindroms[0], 6) || isPalindrome(notPalindroms[0], 6))
    {
        return 0;
    }
    if (!isPalindrome("", 0))
    {
        return 0;
    }
    return 1;
}

int main()
{
    if (!test())
    {
        printf("isPalindrom function error");
        return -1;
    }

    int len = -1;

    do
    {
        printf("Enter len of your string. It should be >= 0: ");
        scanf_s("%d", &len);
    } while (len < 0);

    if (len == 0)
    {
        printf("It is a palindrom\n");
        return 0;
    }

    char *str = calloc(1, sizeof(char) * len);

    if (str == NULL)
    {
        printf("Memory error");
        return -1;
    }

    printf("Enter your string: ");
    fflush(stdin);
    fgets(str, len + 1, stdin);
    fflush(stdin);

    if (isPalindrome(str, len))
    {
        printf("It is a palindrom\n");
        return 0;
    }
    
    printf("It is not a palindrom\n");
    return 0;
}
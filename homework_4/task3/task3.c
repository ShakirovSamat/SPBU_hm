#include <stdio.h>

int main()
{
    int comand = -1;
    printf("This is a phone book\nComands:\n0 - Exit\n1 - Add person\n2 - Show list of all people\n3 - Find phone number by name"
    "\n4 - Find nume by phone number\n5 - Save added data\n");
    printf("Enter comand: ");
    scanf("%d", &comand);
    while (comand != 0)
    {
        
        switch (comand)
        {
            case 1:

                break;
            case 2:

                break;
            case 3:

                break;
            case 4:

                break;
            case 5:

                break;
            default:
                printf("This comand doesn't exists\n"); 
        }
        printf("Enter comand: ");
        scanf("%d", &comand);
    }
    
    
    return 0;
}
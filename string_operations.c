#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void printStringDetails(char *data)
{
    // *data = "Hello";
    printf("String: %s\n", data);
    printf("Length: %d", (int)strlen(data));
}
void swap(char *c1, char *c2)
{
    char temp = *c1;
    *c1 = *c2;
    *c2 = temp;
}
char *reverse(char *st)
{
    int n = strlen(st);
    for (int i = 0; i < n / 2; i++)
    {
        swap(&st[i], &st[n - i - 1]);
    }
    return st;
}
int main()
{
    char *ch[] = {"Exit", "Read", "String details", "strtok", "strchr", "strstr", "Other", "Reverse"};
    while (1)
    {
        char str[] = "strtok needs to be called several times to split a string";
        int menu, n, index, value;
        char *data, *p, del = ' ', charsearch, st[] = "strtok";
        printf("\n==========\nMenus\n==========\n0. Exit\n1. Read\n2. String details\n3. strtok\n4. strchr\n5. strstr"
               "\n6. Other\n7. Reverse \n\nEnter your input: ");
        scanf("%d", &menu);
        // printf(">>>You selected %s\n", ch[menu]);
        switch (menu)
        {
        case 0:
            printf("Thank you.\n");
            exit(0);
            break;
        case 1:
            // int n;
            data = (char *)malloc(sizeof(char));
            printf("Enter String: ");
            scanf("%s", data);
            break;

        case 4:
            printf("Enter char to search: ");
            scanf("%s", &charsearch);
            p = strchr(data, charsearch);
            if (p)
            {
                printf("Found at %s", (char *)p);
            }
            else
            {
                printf("Not Found");
            }
            break;
        case 3:

            p = strtok(str, (char *)&del);
            while (p)
            {
                printf("Found at %s\n", reverse(p));
                p = strtok(NULL, (char *)&del);
            }

            // head = removeNode(head, index);
            break;
        case 2:
            printStringDetails(data);
            break;
        case 5:
            p = strstr(str, st);
            if (p)
            {
                printf("Found at %ld\n", strlen(str) - (p - str));
                printf("Found at %s\n", p);
                // p = strstr(str, st);
            }

            // head = removeNode(head, index);
            break;
        case 7:
            p = strpbrk(str, st);
            if (p)
            {
                printf("Reversed: %s\n", reverse(str));
                // p = strstr(str, st);
            }

            // head = removeNode(head, index);
            break;
        case 6:
            printf("Found at %d\n", strncmp(str, st, 10));
            break;

        default:
            printf("Invalid input please try again.\n");
            break;
        }
    }
    return 0;
}
// Q 10 => print this pattern..
/*
ABCDCBA
ABC CBA
AB   BA
A     A
*/
#include <stdio.h>
int main()
{
    char ch;
    printf("enter the character in uppter case \n");
    scanf("%c", &ch);
    for (int i = ch; i >= 'A'; i--)
    {
        for (int j = 'A'; j <= ch - 1; j++)
        {
            if (i >= j)
            {
                printf("%c",j);
            }
            else
            {
                printf(" ");
            }
        }
        for (int j = ch; j >='A'; j--)
        {
            if (j <= i)
            {
                printf("%c",j);
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}
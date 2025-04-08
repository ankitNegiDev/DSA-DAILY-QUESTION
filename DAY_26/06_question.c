// Q 6 => print this pattern..
/*
ABCDCBA
 ABCBA
  ABA
   A
*/
#include <stdio.h>
int main (){
    for (int i = 'A'; i <= 'D'; i++)
    {
        int temp='A';
        for (int j = 'A'; j <= 'D'; j++)
        {
            if (i <= j)
            {
                printf("%c",temp++);
            }
            else
            {
                printf(" ");
            }
        }
        --temp; // to cancel last iteration +1 and --temp is becasue we did not want to print D again . like if temp is D so temp ++ will become E and to make it D we do --temp so now temp is D and now we did not want to print D again so we made --temp to make temp as C.
        for (int j = 'C'; j >='A'; j--)
        {
            if (j >= i)
            {
                printf("%c",--temp);
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}
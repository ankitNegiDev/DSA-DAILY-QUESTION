// Q 8 => print this pattern...

/*
1
23
456
78910
*/
/*
#include <stdio.h>
int main (){
    int count=1;
    for(int i=1; i<=4; i++){
        for(int j=1; j<=4; j++){
            if(i>=j){
                printf("%d",count);
                count++;
            }
        }
        printf("\n");
    }
    return 0;
}
*/

#include <stdio.h>
int main()
{
    for (int i = 1; i <= 4; i++){
        int start = (i * (i - 1)) / 2 + 1;
        for (int j = 1; j <= i; j++){
            printf("%d", start + (j - 1));
            // ultimately we are doing i+1 after setting the start for each row. except 1st row.
        }
        printf("\n");
    }
    return 0;
}

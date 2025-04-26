// Q 1 => write a program to reverse a string.

// a n k i t --> tikna
// t       a
//   i   n

// length of string is 5 and we require 2 operation..

// b i n g o l i v -> length is 8
// v             b
//   i          i   -> if both char left and right are same no need to do swapping
//     l     n
//       o g
// for 8 length string we need 4 operation which is 8/2

// so for n length if n is odd then we need n/2-1 operation (i<=1 if n=5) 5/2 -> 2 0,1 means i<2 not i<=2 0,1,2 in last operation we are just swapping the str[2] with str[2]

// so for n length if n is even then we need exactly n/2-1 operation means if n=4 then n/2 -> 2 so 0,1  or n=8 -> n/2 -1 => 4-1 => 3 -> 0,1,2, i<=n/2-1

#include <stdio.h>
int calculateLength(char *str)
{
    int len;
    for (len = 0; str[len]; len++)
        ;
    str[len - 1] = '\0';
    printf("len is : %d \n", len);
    for (len = 0; str[len]; len++)
        ;
    printf("len is : %d ", len);

    return len;
}
void reverseString(char *str, int len)
{
    printf("the value is %d\n", len / 2);
    for (int i = 0; i < len / 2; i++)
    {
        printf("str[i] is %c \n", str[i]);
        if (str[i] == str[len - 1 - i])
        {
            printf("continue hit..\n");
            continue;
        }
        printf("swapping \n");
        int temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
}
int main()
{
    char str[100];
    printf("enter the value of string \n");
    fflush(stdin);
    fgets(str, 100, stdin);
    int length = calculateLength(str);
    printf("the length of %s string is : %d\n", str, length);
    reverseString(str, length);
    printf("the reversed string is : %s\n", str);
    return 0;
}

/*
enter the value of string
bingoliv
len is : 9
len is : 8 the length of bingoliv string is : 8
the value is 4
str[i] is b
swapping
str[i] is i
continue hit..
str[i] is n
swapping
str[i] is g
swapping
the reversed string is : vilognib
*/
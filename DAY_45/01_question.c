// Q 1 = Write a function to find a character in a given string between specified indices (start index inclusive and end index exclusive).

#include <stdio.h>

int findCharInRange(const char *str, char ch, int start, int end){
    int i;
    // iterate from start to end-1 (since end is exclusive (mat lo last ko))
    for (i = start; i < end; i++)
    {
        // if we reached to null character (means string is end) befor ethe end comes (that means end is out of bound either we handel it here or while passign it.)
        if (str[i] == '\0')
        {
            break;
        }

        // if character matches simply reutrn the index
        if (str[i] == ch)
        {
            return i;
        }
    }

    // if no character found return -1...
    return -1;
}

int main()
{
    char str[] = "HelloWorld"; 
    char ch = 'o';     
    int start = 2;            
    int end = 8;              


    int index = findCharInRange(str, ch, start, end);

    if (index != -1)
    {
        printf("Character '%c' found at index %d\n", ch, index);
    }
    else
    {
        printf("Character '%c' not found in the given range.\n", ch);
    }

    return 0;
}

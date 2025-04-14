// Q 8 => write a function to calculate the number of arrangements one can make from the n items and r selected at a time. (arrangements also called permutation)

// its like printing the permuation

#include <stdio.h>
#include <stdlib.h>
int printPermutation(int *p,int n);
int main (){
    int n,r;
    printf("enter the value of n, r\n");
    scanf("%d %d",&n,&r);
    // if think what's the need of this ... then refer to dangling, null, wild pointer..
    // this is a kind of good pratics.. if we were doign the repetative allocation..
    int *ptr=NULL;
    /*
    if(ptr==NULL){
        ptr = (int *)calloc(n, sizeof(int));
    }else{
        free(ptr);
        ptr = (int *)calloc(n, sizeof(int));
    }
    */
    ptr = (int *)calloc(n, sizeof(int));

    if (ptr == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1); 
    }

    // now putting values into the array from 1 to n.
    for(int i=0; i<n; i++){
        ptr[i]=i+1;
    }

    int permutation= printPermutation(ptr,n);
    printf("total permutation are : %d\n",permutation);
    return 0;
}

int printPermutation(int *ptr,int n){
    int count=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if (i != j)
            {
                printf("%d %d\n", (*ptr)+i, *(ptr)+j);
                count++;
            }
        }
        printf("\n");
    }
    return count;
}
// Q 2 => write a program to calculate the product of two matrix each of order 3*3.

/*
matrix multiplication means takes the first matrix row and multiply it with col of 2nd matrix and do it for the comman size because if matrix is 2*3 and 3*2 the comman size is 3 ...
* For matrix multiplication to be valid, the number of columns in matrix 𝐴 must match the number of rows in matrix B. In this case, both have 3 in that dimension, so they can be multiplied.
*/

#include <stdio.h>
#include <stdlib.h>
void inputTwoDArrayData(int **ptr, int rowSize, int colSize)
{
    for (int i = 0; i < rowSize; i++)
    {
        printf("\nEnter the data in the %d array\n", i + 1);
        for (int j = 0; j < colSize; j++)
        {
            scanf("%d", &ptr[i][j]);
        }
    }
}

void displayTwoDArrayData(int **ptr, int rowSize, int colSize)
{
    for (int i = 0; i < rowSize; i++)
    {
        for (int j = 0; j < colSize; j++)
        {
            printf("%d ", ptr[i][j]);
        }
        printf("\n");
    }
}

void productOfMatrix(int **ptr1, int **ptr2, int **result, int rowSize, int colSize, int commanSize)
{
    for (int i = 0; i < rowSize; i++)
    {
        for (int j = 0; j < colSize; j++)
        {
            result[i][j] = 0;
            // do the row multiplication (matrix 1) * col multiplication (matrix 2) until comman size is valid.
            for (int k = 0; k < commanSize; k++)
            {
                result[i][j] = result[i][j] + ptr1[i][k] * ptr2[k][j];
            }
        }
    }
}

int main()
{
    int row, col;
    printf("enter the value of rwo and col\n");
    scanf("%d %d", &row, &col);
    int **matrix1 = (int **)malloc(row * sizeof(int *));
    int **matrix2 = (int **)malloc(row * sizeof(int *));
    int **result = (int **)malloc(row * sizeof(int *));

    for (int i = 0; i < row; i++)
    {
        matrix1[i] = (int *)malloc(col * sizeof(int));
        matrix2[i] = (int *)malloc(col * sizeof(int));
        result[i] = (int *)malloc(col * sizeof(int));
    }
    printf("\n\nenter data in matrix 1 \n");
    inputTwoDArrayData(matrix1, row, col);
    printf("\n\nenter the data in matrix 2\n");
    inputTwoDArrayData(matrix2, row, col);
    printf("\n\ndata of matrix 1 is : \n");
    displayTwoDArrayData(matrix1, row, col);
    printf("\n\ndata of matrix 2 is : \n");
    displayTwoDArrayData(matrix2, row, col);
    productOfMatrix(matrix1, matrix2, result, row, col, row);
    printf("\n\nproduct of matrix is :\n");
    displayTwoDArrayData(result, row, col);
}
/*
data of matrix 1 is :
1 2 3
4 5 6
7 8 9


data of matrix 2 is :
1 2 3
4 5 6
7 8 9


product of matrix is :
30 36 42
66 81 96
102 126 150

(row * col)
take row and multiply it with col each time row is same but col changes...
1*1 + 2*4 + 3*7 = 30
1*2 + 2*5 + 3*8 = 36
1*3 + 2*6 + 3*9 = 42

4*1 + 5*4 + 6*7 = 66
4*2 + 5*5 + 6*8 = 81
4*3 + 5*6 + 6*9 = 96

7*1 + 8*4 + 9*7 = 102
7*2 + 8*5 + 9*8 = 126
7*3 + 8*6 + 9*9 = 150

 */
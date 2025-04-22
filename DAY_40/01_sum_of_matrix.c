// Q 1 => write a program to calculate the sum of two matrices each of order 3*3.

#include <stdio.h>
#include <stdlib.h>
void inputTwoDArrayData(int **ptr, int rowSize, int colSize)
{
    printf("enter the data in the matrix or 2d of rowsize and column size %d * %d \n", rowSize, colSize);
    for (int i = 0; i < rowSize; i++)
    {
        printf("enter the data in the %d array\n", i + 1);
        for (int j = 0; j < colSize; j++)
        {
            scanf("%d", &ptr[i][j]);
            // scanf("%d",&(*(*(ptr+i)+j)));
        }
    }
}
void displayTwoDArrayData(int **ptr, int rowSize, int colSize)
{
    printf("the data of the 2d array is \n");
    for (int i = 0; i < rowSize; i++)
    {
        // printf("data of %d array is : \n",i+1);
        for (int j = 0; j < colSize; j++)
        {
            printf("%d ", ptr[i][j]);
        }
        printf("\n");
    }
}

void sumOfMatrix(int **ptr1, int **ptr2, int **result, int rowSize, int colSize)
{
    for (int i = 0; i < rowSize; i++)
    {
        for (int j = 0; j < colSize; j++)
        {
            result[i][j] = ptr1[i][j] + ptr2[i][j];
            // *(result+i)+j = (*(ptr1+i)+j) + (*(ptr2+i)+j)
        }
    }
}
int main()
{
    int row, col;
    printf("enter the value of row and column\n");
    scanf("%d %d", &row, &col);
    int **matrix1 = (int **)malloc(row * sizeof(int *));
    int **matrix2 = (int **)malloc(row * sizeof(int *));
    int **result = (int **)malloc(row * sizeof(int *));

    // int ** is becuse we need to typecast it in and ** is because it is address of an one d array so if it is a normal variable then it would be int * because it is addres of normal variable.
    // malloc(row) only allocates memory for row in bytes, but each element in matrix1 (or matrix2) is a pointer, not an int type variable os for  Each pointer takes up sizeof(int *) bytes (typically 4 or 8 bytes, depending on the system architecture).

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
    sumOfMatrix(matrix1, matrix2, result, row, col);
    printf("\n\nthe sum of two matrix is \n\n");
    displayTwoDArrayData(result, row, col);
    return 0;
}
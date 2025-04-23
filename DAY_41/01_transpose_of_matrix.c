// Q 3 => write a program to print the transpose of a given matrix..

// The transpose of a matrix is formed by flipping the matrix over its diagonal.This means we convert all the rows into columns and all the columns into rows.
/*
rows are 2, col are 3
[1,2,3]
[4,5,6]

rows are 3, col are 2
[1 4]
[2,5]
[3,6]
*/

#include <stdio.h>
#include <stdlib.h>

void inputTwoDArrayData(int **ptr, int rowSize, int colSize)
{
    printf("enter data in matrix\n");
    for (int i = 0; i < rowSize; i++)
    {
        printf("enter data in the %d one d array\n", i + 1);
        for (int j = 0; j < colSize; j++)
        {
            scanf("%d", &ptr[i][j]);
        }
    }
}

void displayTwoDArrayData(int **ptr, int rowSize, int colSize)
{
    printf("data of matrix is \n");
    for (int i = 0; i < rowSize; i++)
    {
        for (int j = 0; j < colSize; j++)
        {
            printf("%d ", ptr[i][j]);
        }
        printf("\n");
    }
}

void transposeMatrix(int **matrix, int **result, int rowSize, int colSize)
{
    for (int i = 0; i < rowSize; i++)
    {
        for (int j = 0; j < colSize; j++)
        {
            result[j][i] = matrix[i][j];
        }
    }
}

int main()
{
    int rowSize, colSize;
    printf("enter the value of rowSize and colSize\n");
    scanf("%d %d", &rowSize, &colSize);

    // crating the matrix or 2d array..
    int **matrix = (int **)malloc(rowSize * sizeof(int *));
    for (int i = 0; i < rowSize; i++)
    {
        matrix[i] = (int *)malloc(colSize * sizeof(int));
    }

    // now transpose matrix will have row as col and col as row..
    int **result = (int **)malloc(colSize * sizeof(int *));
    for (int i = 0; i < colSize; i++)
    {
        result[i] = (int *)malloc(rowSize * sizeof(int));
    }

    // input data in matrix..
    inputTwoDArrayData(matrix, rowSize, colSize);
    displayTwoDArrayData(matrix, rowSize, colSize);
    transposeMatrix(matrix, result, rowSize, colSize);
    displayTwoDArrayData(result, colSize, rowSize);
    return 0;
}
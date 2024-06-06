#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int rows;
    int columns;
    int **data;
} Matrix;

typedef struct
{
    int rows;
    int **data;
} SquareMatrix;

//~ Function to create a matrix with the specified number of rows and columns
//~ By default will be 0 matrix
// Matrix createMatrix(int rows, int columns) {
//     Matrix matrix;
//     matrix.rows = rows;
//     matrix.columns = columns;

//     // Allocate memory for the matrix data
//     matrix.data = (int**)malloc(rows * sizeof(int*));
//     for (int i = 0; i < rows; i++) {
//         matrix.data[i] = (int*)malloc(columns * sizeof(int));
//     }

//     // Initialize the matrix elements to 0
//     for (int i = 0; i < rows; i++) {
//         for (int j = 0; j < columns; j++) {
//             matrix.data[i][j] = 0;
//         }
//     }

//     return matrix;
// }
SquareMatrix createIdentityMatrix(int rows)
{
    SquareMatrix matrix;
    matrix.rows = rows;

    // Allocate memory for the matrix data
    matrix.data = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++)
    {
        matrix.data[i] = (int *)malloc(rows * sizeof(int));
    }

    // Initialize the matrix elements to 0
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            matrix.data[i][j] = 0;
            if (i == j)
            {
                matrix.data[i][j] = 1;
            }
        }
    }

    return matrix;
}

// Function to print the matrix
void printMatrix(Matrix matrix)
{
    for (int i = 0; i < matrix.rows; i++)
    {
        for (int j = 0; j < matrix.columns; j++)
        {
            printf("%d ", matrix.data[i][j]);
        }
        printf("\n");
    }
}

void printIdentityMatrix(SquareMatrix matrix)
{
    for (int i = 0; i < matrix.rows; i++)
    {
        for (int j = 0; j < matrix.rows; j++)
        {
            printf("%d ", matrix.data[i][j]);
        }
        printf("\n");
    }
}

// Function to free the memory occupied by the matrix
void freeMatrix(Matrix matrix)
{
    for (int i = 0; i < matrix.rows; i++)
    {
        free(matrix.data[i]);
    }
    free(matrix.data);
}

void freeIdentityMatrix(SquareMatrix matrix)
{
    for (int i = 0; i < matrix.rows; i++)
    {
        free(matrix.data[i]);
    }
    free(matrix.data);
}

Matrix createMatrix(int rows, int columns, int **data)
{
}

int main()
{
    // Matrix myMatrix = createMatrix(3, 4, (int *[]){{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11}});

    // printf("Initial Matrix:\n");
    // printMatrix(myMatrix);

    // myMatrix.data[1][4] = 5; //! This is a bug as there as you can go to a column/row that doesnt exist FIX!!!!
    // myMatrix.data[2][0] = 8;

    // printf("\nModified Matrix:\n");
    // printMatrix(myMatrix);

    // freeMatrix(myMatrix);

    // SquareMatrix myIdentityMatrix = createIdentityMatrix(10);
    // printf("\nIdentity Matrix:\n");
    // printIdentityMatrix(myIdentityMatrix);
    // freeIdentityMatrix(myIdentityMatrix);

    // return 0;
   int x[3][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};
    printf("%d", x[1][2]);
}

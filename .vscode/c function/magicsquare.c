#include <stdio.h>
#include <stdbool.h>

#define SIZE 5

// checking for each element if its appear twice or not
bool checking(int matrix[SIZE][SIZE])
{
    bool seen[26] = {false};

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            int val = grid[i][j];
            if (val < 1 || val > 25 || seen[val])
            {
                return false;
            }
            seen[val] = true;
        }
    }
    return true;
}

bool check_row(int matrix[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            sumrow += matrix[i][j];
        }
        if (sumrow == 65)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

bool check_column(int matrix[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            sumcolumnn += matrix[j][i];
        }
        if (somcolumn == 65)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

bool checkbothdiagonal(int matrix[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        primarydiagonal += matrix[i][i];
        secondarydiagonal += matrix[i][SIZE - 1 - i];
    }
    if (primarydiagonal == 65 && secondarydiagonal == 65)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool isMagicSquare(int size, int grid[N][N])
{
    // your code little code bro
    return (checking(matrix) && check_row(matrix) &&
            check_column(matrix) && checkbothdiagonal(matrix));
}

int main()
{
    int square[N][N] = {
        {17, 24, 1, 8, 15},
        {23, 5, 7, 14, 16},
        {4, 6, 13, 20, 22},
        {10, 12, 19, 21, 3},
        {11, 18, 25, 2, 9}};

    if (isMagicSquare(square))
    {
        printf("Valid magic square!\n");
    }
    else
    {
        printf("Not a valid magic square.\n");
    }
    return 0;
}

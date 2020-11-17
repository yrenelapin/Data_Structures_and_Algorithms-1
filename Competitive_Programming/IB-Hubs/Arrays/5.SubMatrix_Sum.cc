/*
Submatrix Sum
Given a matrix A of size M*N and an integer K, find the submatrix sum at each element in A. At an element, submatrix is formed by extending K distance in all the four directions until it touches the edges.

Input
First line contains three space separated integers M, N and K. Each of the following M lines contains N space separated integers of A.

Output
Print M lines of N space separated integers representing the corresponding submatrix sum.
*/


// PREFIX SUM APPROACH


#include <iostream>
#include <vector>

using namespace std;
int m, n;
void row_prefix_sum(vector<vector<int>> &matrix)
{
    for (int i = 1; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] += matrix[i - 1][j];
        }
    }
    return;
}

void col_prefix_sum(vector<vector<int>> &matrix)
{
    for (int j = 1; j < n; j++)
    {
        for (int i = 0; i < m; i++)
        {
            matrix[i][j] += matrix[i][j - 1];
        }
    }
    return;
}

void matrix_block_sum(vector<vector<int>> &matrix, int k, vector<vector<int>> &ans)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int x = min(i + k, m - 1);
            int y = min(j + k, n - 1);
            ans[i][j] = matrix[x][y];
            int rowBound = i - k - 1;
            int is_row_bound_valid = 0, is_col_bound_valid = 0;
            if (rowBound >= 0)
            {
                ans[i][j] -= matrix[rowBound][y];
                is_row_bound_valid = 1;
            }
            int colBound = j - k - 1;
            if (colBound >= 0)
            {
                ans[i][j] -= matrix[x][colBound];
                is_col_bound_valid = 1;
            }
            if (is_row_bound_valid && is_col_bound_valid)
            {
                ans[i][j] += matrix[rowBound][colBound];
            }
        }
    }
    return;
}

void print_matrix(vector<vector<int>> matrix)
{
    for (auto row : matrix)
    {
        for (auto val : row)
            cout << val << " ";
        cout << endl;
    }
    return;
}
void print_matrix_block_sum(vector<vector<int>> &matrix, int k)
{
    row_prefix_sum(matrix);
    col_prefix_sum(matrix);

    vector<vector<int>> ans(m, vector<int>(n, 0));

    matrix_block_sum(matrix, k, ans);
    print_matrix(ans);
    return;
}

int main()
{
    int k;
    cin >> m >> n >> k;

    vector<int> col(n, 0);
    vector<vector<int>> matrix(m, col);

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }
    print_matrix_block_sum(matrix, k);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

/*
You are given a 2D integer matrix matrix(M x N), and T operations.
- Operation 1: find the sum of the elements inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).
- Operation 2: update the matrix at the given location(i and j) to given value value.

Input:
The first line of input contains two space-separated integers M and N respectively. Each of the next M lines contains N space-separated integers.
The next(M + 2 nd) line of input contains the integer T.
- Each of the next T lines contains a character and three/four integers with space separation.
    - In the case of Operation 1, four integers follow the character, the first two integers represent the upper left corner(row col) and the next two integers represent the lower right corner(row col).
    - In the case of Operation 2, three integers follow the character, the first two integers represent the location L(row col) and the third integer represents the value to be updated at location L.

Note: The character in the above T lines represents the action that needs to be performed, and it can only be s(for Operation 1), u(for Operation 2).

Time complexity: The time complexity of each operation is O(logN * logM) where N is the total number of integers given.
Space complexity: The space complexity of the solution is O(M * N)

Important:
All the tricks/steps involved in all the below methods is exactly similar to the ones used in
usual Binary Indexed Trees/ Fenwick Trees for 1D-Range Queries. So it is advised to revise that prior to this.
For more clarity, read the explanation provided in iB-Hubs Practice section - 2 of Advanced Trees.
*/

vector<vector<int>> tree;
vector<vector<int>> inp_matrix;
int _row;
int _col;

int firstSetBit(int x){
    return x & (-x);
}

void updateTree(int row, int col, int val)
{

    for (int i = row + 1; i <= _row; i += firstSetBit(i))
        for (int j = col + 1; j <= _col; j += firstSetBit(j))
        {
            tree[i][j] += val;
        }
}

void update(int &row, int &col, int &val, vector<vector<int>> &inp_matrix)
{
    updateTree(row, col, val - inp_matrix[row][col]);
    inp_matrix[row][col] = val;
}

int getSum(int row, int col){
    int sum = 0;
    for (int i = row; i > 0; i -= firstSetBit(i))
        for (int j = col; j > 0; j -= firstSetBit(j))
        {
            sum += tree[i][j];
        }
    return sum;
}

int sumRegion(int &row1, int &col1, int &row2, int &col2)
{
    return getSum(row2 + 1, col2 + 1) - getSum(row1, col2 + 1) - getSum(row2 + 1, col1) + getSum(row1, col1);
}

void BITree(vector<vector<int>> &inp_matrix)
{
    if (_row == 0)
        return;
    tree = vector<vector<int>>(_row + 1, vector<int>(_col + 1, 0));
    for (int i = 0; i < _row; i++)
        for (int j = 0; j < _col; j++)
        {
            updateTree(i, j, inp_matrix[i][j]);
        }
}


int main()
{
    int input;
    cin >> _row >> _col;
    vector<vector<int>> inp_matrix;
    for (int i = 0; i < _row; i++)
    {
        vector<int> row;
        for (int j = 0; j < _col; j++)
        {
            cin >> input;
            row.push_back(input);
        }
        inp_matrix.push_back(row);
    }

    BITree(inp_matrix);

    char ch;
    int r1, c1, r2, c2, val, T;
    cin >> T;
    while (T--)
    {
        cin >> ch;
        if (ch == 's')
        {
            cin >> r1 >> c1 >> r2 >> c2;
            cout << sumRegion(r1, c1, r2, c2) << " ";
        }
        else
        {
            cin >> r1 >> c1 >> val;
            update(r1, c1, val, inp_matrix);
        }
    }
}
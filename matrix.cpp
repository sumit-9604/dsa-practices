#include <iostream>
#include <vector>
#include <string>
using namespace std;

int linearsearch(int matrix[][3], int key, int r, int c){
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; i++){
            if (matrix[i][j] == key){
                cout << true;
                cout << i, j;}}}}




int maxrowsum(int arr[][3], int r, int c)
{
    int maxsum = INT16_MIN;
    for (int i = 0; i < r; i++)
    {
        int rowsum = 0;
        for (int j = 0; j < c; j++)
        {
            rowsum += arr[i][j];
        }
        maxsum = max(rowsum, maxsum);
    }
    return maxsum;
}

int diagnolsum(int matrix[][3], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += matrix[i][i];
        if (i != n - i - 1)
        {
            sum += matrix[i][n - i - 1];
        }
    }
    cout << sum;
}
int searchinrow(vector<vector<int>> &matrix, int t, int row)
{
    int n = matrix[0].size();
    int start = 0;
    int end = n;
    while (start <= end)
    {
        int mid2 = start + (end - start) / 2;
        if (t < matrix[row][mid2])
        {
            end = mid2 - 1;
        }
        else if (t > matrix[row][mid2])
        {
            start = mid2 + 1;
        }
        else
        {
            return true;
        }
    }
}

int search(vector<vector<int>> &matrix, int t)
{
    int m = matrix.size();
    int n = matrix[0].size();
    int sr = 0;
    int er = m - 1;
    while (sr <= er)
    {
        int mid = sr + (er - sr) / 2;
        if (t >= matrix[mid][0] && t <= matrix[mid][n - 1])
        {
            return searchinrow(matrix, t, mid);
        }
        else if (t > matrix[mid][n - 1])
        {
            sr = mid + 1;
        }
        else
        {
            er = mid - 1;
        }
    }
}

int search2(vector<vector<int>> &matrix, int t)
{
    int m = matrix.size();    // row calculation
    int n = matrix[0].size(); // column calculation
    int r = 0;
    int c = n - 1;

    while (r < m && c >= 0)
    {
        if (t == matrix[r][c])
        {
            return t;
        }
        else if (t > matrix[r][c])
        {
            r++;
        }
        else
        {
            c--;
        }
    }
}

vector<int> spiral(vector<vector<int>> &matrix){
    int m = matrix.size();                      // row calculation
    int n = matrix[0].size();                   // column calculation
    int sr = 0 , sc = 0 ;
    int er = m-1 , ec = n-1;
    vector<int> answer;


    while(sr <= er && sc<=ec){                       
        for (int j = sc; j < ec; j++){            //top
            answer.push_back(matrix[sr][j]);}

        for (int i = sr+1; i < er; i++){            //right
            answer.push_back(matrix[i][ec]);}
            
        for (int j = ec-1; j >=sc; j--){            //bottom
            if (sr==er){break;}
            answer.push_back(matrix[er][j]);}

        for (int i = er-1; i >= sr+1; i--){            //left
            if (sc==ec){break;}
            answer.push_back(matrix[i][sc]);}
        sr++; sc++; er--; ec--;}
        return answer;}





int main()
{
    cout<<spiral<<endl;

}

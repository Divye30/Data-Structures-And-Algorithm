#include<iostream>
#include<vector>
using namespace std;
int minFallingPathSum(vector<vector<int>>& matrix)
{
    int n=matrix.size();
    for(int i=1;i<n;i++)
    {
        int j=0;
        while(j<n)
        {
            if(j==0)
                matrix[i][j]+= min(matrix[i-1][j],matrix[i-1][j+1]);
            else if(j==n-1)
                matrix[i][j]+= min(matrix[i-1][j],matrix[i-1][j-1]);
            else
                matrix[i][j]+= min(min(matrix[i-1][j-1],matrix[i-1][j]),matrix[i-1][j+1]);
            j++;
        }
    }
    return *min_element(matrix[n-1].begin(),matrix[n-1].end());
}
int main()
{
    int n;
    cin>>n;
    vector<vector<int>> matrix(n,vector<int> (n));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            int data;
            cin>>data;
            matrix[i][j]=data;
        }
    }
    cout<<minFallingPathSum(matrix)<<endl;
}

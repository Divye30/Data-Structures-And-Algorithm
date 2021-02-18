#include<iostream>
#include<cmath>
using namespace std;
bool can_place(int **mat, int i, int j, int n, int num)
{
    for(int x=0; x<n; x++)
    {
        if(mat[x][j]==num || mat[i][x]==num)
        {
            return false;
        }
    }
    int rn=sqrt(n);
    int sx=(i/rn)*rn;
    int sy=(j/rn)*rn;
    for(int x=sx; x<sx+rn; x++)
    {
        for(int y=sy; y<sy+rn; y++)
        {
            if(mat[x][y]==num)
            {
                return false;
            }
        }
    }
    return true;
}
bool solve_Sudoku(int **mat, int i, int j, int n)
{
    if(i==n)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<mat[i][j]<<" ";
            }
            cout<<endl;
        }
        return true;
    }
    if(j==n)
    {
        return solve_Sudoku(mat,i+1,0,n);
    }
    if(mat[i][j]!=0)
    {
        return solve_Sudoku(mat,i,j+1,n);
    }
    for(int num=0; num<=n; num++)
    {
        if(can_place(mat,i,j,n,num))
        {
            mat[i][j]=num;
            bool solve_success=solve_Sudoku(mat,i,j+1,n);
            if(solve_success)
                return true;
        }
    }
    mat[i][j]=0;
    return false;
}
int main()
{
    int n;
    cin>>n;
    int **mat=new int*[n];
    for(int i=0; i<n; i++)
    {
        mat[i]=new int[n];
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>mat[i][j];
        }
    }
    cout<<endl;
    solve_Sudoku(mat,0,0,n);
    for(int i=0; i<n; i++)
    {
        delete [] mat[i];
    }
    delete [] mat;
}

#include<iostream>
using namespace std;
bool is_Safe(int board[][10], int i, int j, int n)
{
    for(int row=0; row<n; row++)
    {
        if(board[row][j]==1)
        {
            return false;
        }
    }
    int x=i,y=j;
    while(x>=0 && y>=0)
    {
        if(board[x][y]==1)
            return false;
        x--;
        y--;
    }
    x=i;
    y=j;
    while(x>=0 && y>=0)
    {
        if(board[x][y]==1)
            return false;
        x--;
        y++;
    }
    return true;
}
bool Place_N_Queen(int board[][10], int i, int n)
{
    if(i==n)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(board[i][j]==1)
                {
                    cout<<board[i][j]<<" ";
                }
                else
                {
                    cout<<"0"<<" ";
                }
            }
            cout<<endl;
        }
        cout<<endl;
        return false;
    }
    for(int j=0; j<n; j++)
    {
        if(is_Safe(board,i,j,n))
        {
            board[i][j]=1;
            bool next_place=Place_N_Queen(board, i+1, n);
            if(next_place)
                return true;
            board[i][j]=0;
        }
    }
    return false;
    
}
int main()
{
    int n;
    cin>>n;
    int board[10][10]={0};
    Place_N_Queen(board, 0, n);
}

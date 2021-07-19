#include<iostream>
using namespace std;
int R,C;
void print(char input[][50])
{
    for(int i=0; i<R; i++)
    {
        for(int j=0; j<C; j++)
        {
            cout<<input[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};
void flood_fill(char mat[][50], int i, int j, char ch, char color)
{
    if(i<0||j<0 || i>=R||j>=C)
        return;
    if(mat[i][j]!=ch)
        return;
    mat[i][j]=color;
    for(int k=0; k<4; k++)
    {
        flood_fill(mat, i+dx[k], j+dy[k], ch, color);
    }
}
int main()
{
    cin>>R>>C;
    char input[15][50];
    for(int i=0; i<R; i++)
    {
        for(int j=0; j<C; j++)
        {
            cin>>input[i][j];
        }
    }
    print(input);
    flood_fill(input, 0, 0, '.', '_');
    flood_fill(input, 8, 13, '.', 'r');
    print(input);
}

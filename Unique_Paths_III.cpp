#include<iostream>
#include<vector>
using namespace std;
int dfs(vector<vector<int>>& grid, int x, int y, int zero)
{
    if(x<0 or y<0 or x>=grid.size() or y>=grid[0].size() or grid[x][y]==-1)
        return 0;
    if(grid[x][y]==2)
        return zero==-1? 1:0;
    grid[x][y]=-1;
    zero--;
    int totalPaths=dfs(grid,x+1,y,zero)+
        dfs(grid,x,y+1,zero)+
        dfs(grid,x-1,y,zero)+
        dfs(grid,x,y-1,zero);
    grid[x][y]=0;
    zero++;
    return totalPaths;
}
int uniquePathsIII(vector<vector<int>>& grid)
{
    int zero=0,sx=0,sy=0;
    for(int r=0; r<grid.size(); r++)
    {
        for(int c=0; c<grid[0].size(); c++)
        {
            if(grid[r][c]==0)
                zero++;
            else if(grid[r][c]==1)
            {
                sx=r;
                sy=c;
            }
        }
    }
    return dfs(grid,sx,sy,zero);
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> grid;
    for(int r=0; r<n; r++)
    {
        vector<int> rows;
        for(int c=0; c<m; c++)
        {
            int data;
            cin>>data;
            rows.push_back(data);
        }
        grid.push_back(rows);
    }
    cout<<uniquePathsIII(grid)<<endl;
}

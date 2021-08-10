#include<iostream>
using namespace std;
#define int_max 999999
int n=4;
int dp[16][4];
int dist[10][10]={{0,20,42,25},
                  {20,0,30,34},
                  {42,30,0,10},
                  {25,34,10,0}};
int visited_all=(1<<n)-1;
int TSP(int mask,int pos)
{
    if(mask==visited_all)
        return dist[pos][0];
    int ans=int_max;
    if(dp[mask][pos]!=-1)
        return dp[mask][pos];
    for(int city=0; city<n; city++)
    {
        if((mask & (1<<city))==0)
        {
            int newAns=dist[pos][city]+TSP(mask|(1<<city),city);
            ans=min(ans,newAns);
        }
    }
    return dp[mask][pos]=ans;
}
int main()
{
    for(int i=0; i<(1<<n); i++)
    {
        for(int j=0; j<n; j++)
            dp[i][j]=-1;
    }
    cout<<TSP(1,0)<<endl;
}

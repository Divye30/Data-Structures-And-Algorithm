#include<iostream>
using namespace std;
int max_profit(int n, int c, int *wt, int *prices)
{
    if(n==0 || c==0)
    {
        return 0;
    }
    int ans=0;
    int inc=0,exc=0;
    if(wt[n-1]<=c)
    {
        inc= prices[n-1] + max_profit(n-1,c-wt[n-1],wt,prices);
    }
    exc=max_profit(n-1,c,wt,prices);
    ans=max(inc,exc);
    return ans;
}
int main()
{
    int n,c;
    cin>>n>>c;
    int weights[n],prices[n];
    for(int i=0; i<n; i++)
    {
        cin>>weights[i];
    }
    for(int i=0; i<n; i++)
    {
        cin>>prices[i];
    }
    cout<<max_profit(n,c,weights,prices)<<endl;
}

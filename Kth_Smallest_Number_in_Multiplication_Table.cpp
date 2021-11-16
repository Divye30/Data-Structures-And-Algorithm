#include<iostream>
using namespace std;
int countSmaller(int m, int n, int mid)
{
    int ans=0;
    for(int i=1;i<=m;i++)
        ans+= min(n,mid/i);
    return ans;
}
int findKthNumber(int m, int n, int k)
{
    int l=0, r=m*n, mid, res;
    while(l<=r)
    {
        mid= l+(r-l)/2;
        if(countSmaller(m,n,mid)<k)
            l=mid+1;
        else
            r=mid-1;
    }
    return l;
}
int main()
{
    int m,n,k;
    cin>>m>>n>>k;
    cout<<findKthNumber(m, n, k)<<endl;
}

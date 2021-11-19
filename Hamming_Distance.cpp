#include<iostream>
using namespace std;
int distance(int x, int y)
{
    int res=x^y;
    int ans=0;
    while(res)
    {
        ans+=res%2;
        res>>=1;
    }
    return ans;
}
int main()
{
    int x,y;
    cin>>x>>y;
    cout<<distance(x,y)<<endl;
}

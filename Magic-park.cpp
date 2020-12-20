#include<iostream>
using namespace std;
void escape(char a[1000][1000], int n, int m, int s, int k)
{
    bool temp= true;
    for(int i=0; i<n; i++)
    {
        int j=0;
        while(j<m && s>=k)
        {
            if(a[i][j]=='.')
            {
                s-=2;
                j++;
            }
            else if(a[i][j]=='*')
            {
                s+=5;
                j++;
            }
            else
            {
                break;
            }
            if(j!=m-1)
            {
                s--;
            }
        }
        if(s<k)
        {
            temp=false;
            break;
        }
    }
    if(temp)
    {
        cout<<"Yes"<<endl;
        cout<<s<<endl;
    }
    else
    {
        cout<<"No"<<endl;
        cout<<s<<endl;
    }
}
int main()
{
    char a[1000][1000];
    int n,m,s,k;
    cin>>n>>m>>s>>k;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>a[i][j];
        }
    }
    escape(a,n,m,s,k);
}

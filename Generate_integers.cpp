#include<iostream>
#include<cstring>
using namespace std;
int generate_integrs(char *out, int n, int i)
{
    if(i==n)
    {
        out[i]='\0';
        cout<<out<<endl;
        return 1;
    }
    out[i]='a';
    int count=0;
    count+=generate_integrs(out,n,i+1);
    if(out[i]=='a')
    {
        if(out[i-1]!='b')
        {
            out[i]='b';
            count+=generate_integrs(out,n,i+1);
        }
    }
    return count;
}
int main()
{
    int t;
    cin>>t;
    int i=1;
    while(t--)
    {
        int n;
        cin>>n;
        char out[25];
        int count= generate_integrs(out,n,0);
        cout<<"Count for Test Case #"<<i<<" = "<<count<<endl;
        i++;
    }
}

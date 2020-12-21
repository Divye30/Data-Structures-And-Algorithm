#include<iostream>
using namespace std;
int main()
{
    int N,M;
    cin>>N;
    int *a=new int[N];
    for(int i=0; i<N; i++)
    {
        cin>>a[i];
    }
    cin>>M;
    int *b=new int[M];
    for(int i=0; i<M; i++)
    {
        cin>>b[i];
    }
    int t=abs(N-M);
    int max=(N>M)?N:M;
    int *temp=new int[max];
    for(int i=0; i<max; i++)
    {
        if(i<t)
            temp[i]=0;
        else if(N<M)
            temp[i]=a[i-t];
        else if(N>M)
            temp[i]=b[i-t];
    }
    int *c=new int[max];
    int carry=0,sum=0;
        if(N<M)
        {
            for(int i=max-1; i>=0; i--)
            {
                sum=carry+temp[i]+b[i];
                carry=sum/10;
                c[i]=sum%10;
            }
        }
        else if(N>M)
        {
            for(int i=max-1; i>=0; i--)
            {
                sum=carry+a[i]+temp[i];
                carry=sum/10;
                c[i]=sum%10;
            }
        }
    if(carry!=0)
    {
        cout<<carry<<", ";
    }
    for(int i=0;i<max; i++)
    {
        cout<<c[i]<<", ";
    }
    cout<<"END"<<endl;
}

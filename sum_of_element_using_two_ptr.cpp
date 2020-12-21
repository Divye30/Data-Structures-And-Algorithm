#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int N;
    cin>>N;
    int *a=new int[N];
    for(int i=0; i<N; i++)
    {
        cin>>a[i];
    }
    sort(a,a+N);
    int k;
    cin>>k;
    int i=0,j=N-1;
    while(i<=j)
    {
        if(a[i]+a[j]<k)
        {
            i++;
        }
        else if(a[i]+a[j]>k)
        {
            j--;
        }
        else if(a[i]+a[j]==k)
        {
            cout<<a[i]<<" and "<<a[j]<<endl;
            i++;
            j--;
        }
    }
}

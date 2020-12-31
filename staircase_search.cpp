#include<iostream>
using namespace std;
bool search(int a[][30], int m, int n, int key)
{
    int i=0,j=n-1;
    while(j>=0 && i<m){
        if(a[i][j]<key)
        {
            i++;
        }
        else if(a[i][j]>key)
        {
            j--;
        }
        else if(a[i][j]==key)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    int n,m,key;
    cin>>m>>n;
    int a[30][30];
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>a[i][j];
        }
    }
    cin>>key;
    if(search(a,m,n,key))
        cout<<"Found"<<"<<endl;
    else
        cout<<"Not Found"<<endl;
}

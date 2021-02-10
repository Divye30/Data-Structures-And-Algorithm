#include<iostream>
#include<cstring>
using namespace std;
void consecutive_char(char *a, char *out, int i, int j)
{
    if(a[i]=='\0')
    {
        out[j]='\0';
        cout<<out<<endl;
        return;
    }
    if(a[i]==a[i+1])
    {
        out[j]=a[i];
        out[j+1]='*';
        out[j+2]=a[i+1];
        consecutive_char(a,out,i+1,j+2);
    }
    else
    {
        out[j]=a[i];
        consecutive_char(a,out,i+1,j+1);
    }
    return;
}
int main()
{
    char a[10000];
    cin>>a;
    char out[100000];
    consecutive_char(a,out,0,0);
}

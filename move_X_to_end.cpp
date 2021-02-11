#include<iostream>
#include<cstring>
using namespace std;
void move_to_end(char *a, char *out, int i, int j, int k)
{
    if(a[i]=='\0')
    {
        out[i]='\0';
        cout<<out<<endl;
        return;
    }
    if(a[i]!='x')
    {
        out[j]=a[i];
        move_to_end(a,out,i+1,j+1,k);
    }
    else
    {
        out[strlen(a)-k]=a[i];
        move_to_end(a,out,i+1,j,k+1);
    }
    return;
}
int main()
{
    char a[1000];
    cin>>a;
    char out[1000];
    move_to_end(a,out,0,0,1);
}

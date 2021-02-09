#include<iostream>
using namespace std;
void generate_brackets(char *output, int n, int i, int open, int close)
{
    if(i==2*n)
    {
        output[i]='\0';
        cout<<output<<endl;
        return;
    }
    if(open<n)
    {
        output[i]='(';
        generate_brackets(output, n, i+1, open+1, close);
    }
    if(close<open)
    {
        output[i]=')';
        generate_brackets(output,n,i+1,open,close+1);
    }
    return;
}
int main()
{
    int n;
    cin>>n;
    char output[1000];
    int i=0;
    generate_brackets(output, n, i, 0, 0);
}

#include<iostream>
using namespace std;
int clearRange_iToj(int N, int i, int j)
{
    int ones= (~0);
    int a= ones<<(j+1);
    int b= (1<<i)-1;
    int mask= a|b;
    return N&mask;
}
int replaceBits(int N, int M, int i, int j)
{
    int n=clearRange_iToj(N, i, j);
    return n|(M<<i);
}
int main()
{
    int N,M,i,j;
    cin>>N;
    cin>>M;
    cin>>i>>j;
    cout<<replaceBits(N, M, i, j)<<endl;
}

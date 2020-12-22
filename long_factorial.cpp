#include<iostream>
using namespace std;
#define MAX 10000
int multiply(int x, int res[], int res_size)
{
    int carry = 0;
    for (int i=0; i<res_size; i++)
    {
        int prod = res[i] * x + carry;
        res[i] = prod % 10;
        carry  = prod/10;
    }
    while(carry)
    {
        res[res_size] = carry%10;
        carry = carry/10;
        res_size++;
    }
    return res_size;
}
void factorial(int n)
{
    int temp[MAX];
    temp[0] = 1;
    int temp_size = 1;
    for (int x=2; x<=n; x++)
        temp_size = multiply(x, temp, temp_size);
    for (int i=temp_size-1; i>=0; i--)
        cout<<temp[i];
    cout<<endl;
}
int main()
{
    int n;
    cin>>n;
    factorial(n);
}

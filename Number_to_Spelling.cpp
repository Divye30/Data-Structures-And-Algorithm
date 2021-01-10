#include<iostream>
using namespace std;
char words[][10]={"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};
void print_spellings(int n)
{
    if(n==0)
        return;
    print_spellings(n/10);
    int digit=n%10;
    cout<<words[digit]<<" ";
    return;
}
int main()
{
    int n;
    cin>>n;
    print_spellings(n);
    cout<<endl;
}

#include<iostream>
#include<algorithm>
using namespace std;
int number_of_coins(int arr[],int n, int money)
{
    int count=0;
    while(money>0)
    {
        int *ub=upper_bound(arr,arr+n,money);
        money=money-*(ub-1);
        count++;
    }
    return count;
}
int main()
{
    int arr[10]={1,2,5,10,20,50,100,200,500,2000};
    int money;
    cin>>money;
    cout<<number_of_coins(arr, 10, money)<<endl;
}

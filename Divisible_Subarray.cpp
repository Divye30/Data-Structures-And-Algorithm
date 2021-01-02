#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    long long a[1000005], freq[1000005];
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        memset(freq,0,sizeof(freq));
        freq[0]=1;
        int sum=0;
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            sum+=a[i];
            sum%=n;
            sum=(sum+n)%n;
            freq[sum]++;
        }
        long long ans=0;
        for(int i=0; i<n; i++)
        {
            ans+=freq[i]*(freq[i]-1)/2;
        }
        cout<<ans<<endl;
    }
}

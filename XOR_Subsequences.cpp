#include<iostream>
using namespace std;
int main()
{
    long int n;
    cin>>n;
    long int *arr=new long int[n];
    long int frequency[1<<16]={0};
    for(long int i=0; i<n; i++)
    cin>>arr[i];
    for(long int i=1; i<(1<<n); i++)
    {
        long int j=0;
        long int t=i;
        long int xored=0;
        while(t>0)
       {
           if(i<5)
           {
               int last_bit=t&1;
               if(last_bit==1)
               xored=xored^arr[j];
           }
           else
           {
               int last_bit=t&1;
               if(last_bit==1 && ((t>>1)&1)!=0 && t>1)
               xored=xored^arr[j];
               else if(last_bit==1 && ((t>>1)&1)==0 && t>1)
               {
                   xored=-1;
                   break;
               }
               if(t==1)
               xored=xored^arr[j];
           }
           t=t>>1;
           j++;
       }
       if(xored>=0)
       frequency[xored]+=1;
    }
    long int maxx=frequency[0];
    long int min_index=0;
    for(long int k=1; k<(1<<16); k++)
    {
        if(maxx<frequency[k])
        {
            maxx=frequency[k];
            min_index=k;
        }
    }
    cout<<min_index<<" "<<maxx<<endl;
}

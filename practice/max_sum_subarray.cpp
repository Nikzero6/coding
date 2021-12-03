#include <iostream>
using namespace std;

int main(){

    int n;
    cin>>n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }

    int sum = 0;
    int mx = 0;
    int i=0, j =0;
    int st=-1, en=-1;

    while (j<n)
    {
        sum += a[j];

        if(sum <= 0){
            j++;
            i=j;
            sum = 0;
        }
        else{
            mx = max(mx, sum);
            if(sum == mx){
                st = i;
                en = j;
            }
            j++;
        }
    }

    cout<<st<<" "<<en;
    cout<<endl<<mx;

    return 0;
    
}
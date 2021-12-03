#include <iostream>
using namespace std;

int main(){

    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];

    int noWrapSum = 0;
    int sum = 0;
    int i=0, j=0;

    while(j<n){
        sum += a[j];
        if(sum <=0){
            sum = 0;
            j++;
            i = j;
        }
        else{
            noWrapSum = max(noWrapSum, sum);
            j++;
        }
    }

    for(int i=0; i<n; i++)
        a[i] = 0-a[i];

    int WrapSum = 0;
    int total = 0;
    sum = 0;
    i= j=0;

    while(j<n){
        sum += a[j];
        total += a[j];

        if(sum <=0){
            sum = 0;
            j++;
            i = j;
        }
        else{
            WrapSum = max(WrapSum, sum);
            j++;
        }
    }

    WrapSum = WrapSum-total;

    cout<<max(WrapSum, noWrapSum);

    return 0;
}
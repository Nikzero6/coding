#include <bits/stdc++.h>
using namespace std;
#define N 100000

int main(){

    long int n;
    cin>>n;
    long int a[n];
    for(long int i=0; i<n; i++)
        cin>>a[i];

    long int H[N+1];
    for(long int i=0; i<=N; i++)
        H[i] = -1;

    long int minIndex = INT_MAX;

    for(long int i=0; i<n; i++){

        if(H[a[i]] == -1){
            H[a[i]] = i;
        }
        else{
            minIndex = min(minIndex, H[a[i]]);
        }
    }

    cout<<minIndex;

    return 0;
}
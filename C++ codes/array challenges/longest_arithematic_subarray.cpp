#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;

    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    
    int maxCount=0;

    int count = 2;

    for(int j=1; j<n-1; j++){

        if((a[j]-a[j-1])==(a[j+1]-a[j])){
            count++;
        }
        else{
            maxCount = max(maxCount, count);
            count = 2;
        }
    }
    maxCount = max(maxCount, count);
    cout<<maxCount;

    return 0;
}
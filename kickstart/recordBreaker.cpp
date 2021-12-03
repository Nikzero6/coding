#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    int mx = a[0];
    int count=0;

    for(int i=0; i<n; i++){

        mx = max(a[i], mx);
        
        if(i != n-1){
            if(a[i] == mx && a[i]>a[i+1])
                count++;
        }
        else{
            if(a[i] == mx)
                count++;
        }

    }
    cout<<count;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;

    int v[n];
    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    int count = 0;
    int mx = v[0];

    for(int i=0; i<n; i++){
        
        mx = max(mx, v[i]);
        
        if(i == n-1 && v[i] == mx){
            count++;
        }
        else if(v[i] == mx && v[i]>v[i+1]){
            count++;
        }

    }

    cout<<count;    

    return 0;
}
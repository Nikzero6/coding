#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    //requires sorted array
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    int k;
    cin>>k;

    int l=0;
    int h=n-1;

    while(l<h){
        if(a[l]+a[h] == k){
            cout<<l<<" "<<h<<endl;
            return 0;
        }
        else if(a[l]+a[h] < k){
            l++;
        }
        else{
            h--;
        }
    }

    cout<<"no such pair";
    return 0;
}
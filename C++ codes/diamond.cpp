#include<iostream>
using namespace std;

int main() {

    int n;
    cin>>n;
    int mid = (n+1)/2;

    for(int i=1; i<=mid; i++) {
        for(int j=1; j<=(n-i); j++) {
            cout<<" ";
        }
        for(int j=1; j<=i; j++) {
            cout<<" *";
        }
        cout<<endl;
    }
    for(int i=mid-1; i>=1; i--) {
        for(int j=1; j<=(n-i); j++) {
            cout<<" ";
        }
        for(int j=1; j<=i; j++) {
            cout<<" *";
        }
        cout<<endl;
    }
    return 0;
}
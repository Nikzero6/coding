#include <iostream>
using namespace std;
#define N 100000

int main(){

    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    int H[N+1] = {0};

    for(int i=0; i<n; i++){
        if(a[i]>=0){
            H[a[i]]++;
        }
    }

    for(int i=0; i<=N; i++){
        if(H[i]==0){
            cout<<i;
            break;
        }
    }

    return 0;
}
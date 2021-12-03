#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;
    int A[n];
    for(int i=0; i<n; i++){
        cin>>A[i];
    }

    int mx = 2;
    int count = 2;
    int prev_diff = A[1]-A[0];

    for(int i=1; i<n-1; i++){
        
        int curr_diff = A[i+1]-A[i];

        if(prev_diff == curr_diff){
            count++;
        }
        else {
            count = 2;
        }
        mx = max(count, mx);
        prev_diff = curr_diff;
    }

    cout<<mx;
    return 0;
}
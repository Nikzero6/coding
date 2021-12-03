#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    int array[n];
    
    for(int i=0;  i<n; i++){
        cin>>array[i];
    }

    // int maxNo=INT_MIN;  //better to initialize with array[0]
    // int minNo=INT_MAX;  //better to initialize with array[0]

    // for(int i=0; i<n; i++){
    //     maxNo = max(maxNo, array[i]);
    //     minNo = min(minNo, array[i]);
    // }

    //better approach
    int maxNo = array[0];
    int minNo = array[0];

    for(int i=1; i<n; i++){
        if(array[i]>maxNo)
            maxNo = array[i];
        else if(array[i]<minNo)
            minNo = array[i];
    }

    cout<<"max: "<<maxNo<<endl<<"min: "<<minNo<<endl;

    return 0;
}
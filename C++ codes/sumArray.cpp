#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, sum = 0;
    cin>>n;

    int array[n];

    for(int i=0; i<n; i++){
        cin>>array[i];
        sum += array[i];
    }

    cout<<sum<<endl;

   return 0;
}
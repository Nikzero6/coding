#include <bits/stdc++.h>
using namespace std;

int maxSumSubarray(int a[], int n){
    // int maxSum = INT_MIN;

    //Brute force O(n^2)

    // for(int i=0; i<n; i++){
    //     int sum = 0;

    //     for(int j=i; j<n; j++){
    //         sum += a[j];
    //         maxSum = max(maxSum, sum);
    //     }
    // }

    //optimized O(n)

    // int prevSum=0;
    // int currSum=0;
    // int i=0, j=0;
    // for(j=1; j<n; j++){
        
    //     prevSum += a[i];

    //     if(prevSum < 0){
    //         prevSum = 0;
    //     }
        
    //     currSum = prevSum + a[j];
    //     maxSum = max(currSum, maxSum);
    //     i++;
      
    // }

    //Kadene's Algorithm : O(n)
    int currSum=0;
    int maxSum = INT_MIN;

    for(int i=0; i<n; i++){
        currSum += a[i];

        if(currSum < 0){
            currSum = 0;
        }

        maxSum = max(currSum, maxSum);
    }

    return maxSum;
}
int main(){

    int n;
    cin>>n;

    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    cout<<maxSumSubarray(a, n);

    return 0;
}
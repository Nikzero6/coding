#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int arrayCount(int arr[], int n){
    int count = 0;
    
    for(int i=0; i<n; i++){
        if(arr[i]%2 == 0){
            count++;
        }
    }
    
    return count;
}

int main() {
    
    int n, count = 0;
    cin>>n;
    
    int array[n];
    
    for(int i=0; i<n; i++){
        array[i] = (2*i + 1);
    }
    
    for(int i = 1; i <= n; i++){
        
        for(int j = i; j<=n; j+=i){
            
            array[j-1]++;
        }
    }

    
    cout<<arrayCount(array, n);
    
    return 0;
}

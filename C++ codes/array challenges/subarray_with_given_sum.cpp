#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin>>n;

    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    int reqSum;
    cin>>reqSum;

    //Naive approach
    //Time Complexity: O(n^2)

    // for(int i=0; i<n; i++){
    //     int sum=0;
    //     for(int j=i; j<n; j++){
    //         sum += a[j];
    //         if(sum == reqSum){
    //             cout<<i+1<<" "<<j+1<<endl;
    //             return 0;
    //         }
    //     }
    // }

    //optimized aprroach- 2 pointers method
    // int s=0,e=0;
    // int currSum=0;

    // while(a[s] <= reqSum){

    //     currSum = 0;
    //     e=s;

    //     while(currSum + a[e] <= reqSum){
    //         currSum += a[e];
    //         e++;
    //     }
    //     if(currSum == reqSum){
    //         cout<<s+1<<" "<<e;
    //         return 0;
    //     }

    //     s++;
    // }

    //efficient approach: inc end until currSum < reqSum,
    //if currSum > reqSum inc start pointer and decrease currSum by prev array element
    //if currSum == reqSum return ans
    //Time Complexity: O(n)

    int currSum = a[0];
    int s = 0;

    for(int e=1; e<=n; e++){ //e : end pointer
        if(currSum > reqSum && s<e-1){  //s : start pointer
            currSum -= a[s];
            s++;
        }

        if(currSum == reqSum){
            cout<<s+1<<" "<<e;
            return 0;
        }
        if(e<n){
            currSum += a[e];
        }

    }
    
    cout<<"No Subarray with sum "<<reqSum<<endl;

    return 0;
}
#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    int extraCandies;
    cin>>n>>extraCandies;

    int candies[n];
    int maxCandies=INT_MIN;

    for(int i=0; i<n; i++){
        cin>>candies[i];
        maxCandies = max(maxCandies, candies[i]);
    }

    bool check[n];
    for(int i=0; i<n; i++){
        if((candies[i]+extraCandies)>=maxCandies)
            check[i]=true;
        else
            check[i]=false;

        cout<<boolalpha
            <<check[i]<<" "
            <<noboolalpha;
    }

    return 0;
}
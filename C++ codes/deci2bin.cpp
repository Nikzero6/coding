#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int deci2bin(int n){

    int bin = 0;
    int rem = 0;
    int x = 1;

    while(n>0){

        rem = n%2;
        bin += rem*x;
        x *= 10;
        n /= 2;
    }

    return bin;
}

int main(){
    
    int n;
    cin>>n;

    cout<<deci2bin(n);

    return 0;
}
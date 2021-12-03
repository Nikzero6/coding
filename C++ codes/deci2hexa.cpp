#include <bits/stdc++.h>
#include <cmath>
using namespace std;

string deci2hexa(int n){

    string hexa;
    int rem = 0;
    int m = n;
    int count  = 0;

    while(m>0){
        m /= 16;
        count++;
    }
    hexa.resize(count);
    count--;

    while(n>0){

        rem = n%16;

        if(rem <= 9){
            hexa[count] = rem +'0';
            count--;
        }
        else {

            char c = 'A' + rem - 10;
            hexa[count] = c;
            count--;
        }

        n /= 16;
    }

    return hexa;
}

int main(){
    
    int n;
    cin>>n;

    cout<<deci2hexa(n);

    return 0;
}
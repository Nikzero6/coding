#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int oct2deci(int oct){
    int decimal=0;
    int rem=0;
    int a=0;

    while(oct>0){

        rem = oct%10;
        decimal += rem*pow(8, a);
        oct /= 10;
        a++;
    }

    return decimal;
}

int hexa2deci(string h){
    int decimal = 0;
    int x = 1;

    for(int i=h.size()-1; i>=0; i--){
        if(h[i] >= '0' && h[i] <= '9'){
            decimal += (h[i]-'0')*x;
            x*=16;
        }
        else if(h[i] >= 'A' && h[i] <= 'F'){
            decimal += (h[i]-'A'+10)*x;
            x*=16;
        }
    }

    return decimal;
}
int main(){
    
    string hexa;
    cin>>hexa;

   cout<<hexa2deci(hexa);

    return 0;
}
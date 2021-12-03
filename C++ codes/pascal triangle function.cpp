#include <iostream>
#include <cmath>
using namespace std;

int factorial(int n) {
    
    int fact = 1;
    
    while(n>0){
        fact = fact*n;
        n--;
    }
    
    return fact;
}

int ncr (int n, int r){
    int numeartor = factorial(n);
    int denominator = factorial(r)*factorial(n-r);

    return numeartor/denominator;
}

int main(){
    int n;
    cin>>n;

    for(int i = 0; i<n; i++){

        for(int j=1; j<n-i; j++){
            cout<<"  ";
        }
        for(int j=0; j<=i; j++){
            cout<<" "<<ncr(i, j)<<"  ";
        }
        cout<<endl;
    }

    return 0;
}
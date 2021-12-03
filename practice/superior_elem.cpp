#include <iostream>
using namespace std;

int superior_count(int * a, int n){

    int count=1;
    int mx = a[n-1];

    for(int i=n-2; i>=0; i--){
        mx = max(mx, a[i]);

        if(a[i] == mx)
            count++;
    }

    return count;
}
int main(){

    int n;
    cin>>n;

    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];

    cout<<superior_count(a, n);

    return 0;
}
#include <iostream>
using namespace std;

#define ll long long
#define m 1000000007

int main(){

    ll n;

    cin>>n;

    ll ans = (n*(n+1))/2 + 1;
    ans %= m;

    cout<<ans;

    return 0;
}
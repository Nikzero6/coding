#include<iostream>
using namespace std;

int main() {
    // #ifndef ONLINE_JUDGE
    //     freopen("input", "r", stdin);
    //     freopen("output", "w", stdout);
    // #endif

    int n,num=1;
    cin>>n;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=i; j++) {
            cout<<num<<" ";
            num=(!num);
        }
        if(i%2==0) {
            num=(!num);
        }
        cout<<endl;
    }

    return 0;
}
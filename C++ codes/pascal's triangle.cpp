#include<iostream>
using namespace std;

int main() {
    // #ifndef ONLINE_JUDGE
    //     freopen("input", "r", stdin);
    //     freopen("output", "w", stdout);
    // #endif

    int n,count=1;
    cin>>n;

    for(int i=0; i<n; i++){
        for(int j =1; j<=n-i; j++){
            cout<<"  ";
        }
        for(int j=0; j<=i; j++){
            if(j == 0 || i == 0){
                count=1;
            }
            else{
                count = count*(i-j+1)/j;
            }
            cout<<" "<<count<<"  ";
        }
        cout<<endl;
    }
    
    return 0;
}
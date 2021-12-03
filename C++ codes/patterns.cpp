#include<iostream>
using namespace std;

int main() {
    // #ifndef ONLINE_JUDGE
    //     freopen("input", "r", stdin);
    //     freopen("output", "w", stdout);
    // #endif

    int n=9;

    
    for(int i = 1; i<=3; i++){
        for(int j = 1; j<=n; j++){
            if((i+j)%4 == 0){
                cout<<"* ";
            }
            else if(i == 2 && j%2==0){
                cout<<"* ";
            }
            else{
                cout<<"  ";
            }

        }
        cout<<endl;
    }
    
    return 0;
}
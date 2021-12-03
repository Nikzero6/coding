#include <iostream>
using namespace std;
#define N 100000

int main(){

    int n;
    cin>>n;
    int key;
    cin>>key;

    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    bool H[2*N+2] = {0};

    for (int i = 0; i < n; i++)
    {
        if(a[i]>=0){
            H[a[i]] = 1;
        }
        else{
            H[N-a[i]] = 1;
        }
    }

    for(int i=0; i<n ; ++i){
        if((key-a[i]) >=0 && H[key-a[i]] == 1){
            cout<<a[i]<<" "<<key-a[i];
            break;
        }
        else if((key-a[i]) <0 && H[N-(key-a[i])] == 1){
            cout<<a[i]<<" "<<key-a[i];
            break;
        }
    }

    return 0;
}
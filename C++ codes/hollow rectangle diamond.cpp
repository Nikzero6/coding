#include<iostream>
using namespace std;

int main() {
    // #ifndef ONLINE_JUDGE
    //     freopen("input", "r", stdin);
    //     freopen("output", "w", stdout);
    // #endif

    int n;
    cin>>n;

    for(int i=1; i<=n; i++){
        
        for(int j=1; j<=n-i; j++){
            cout<<"* ";
        }
        for(int j=i; j>=1; j--){
            
              if(i==j){cout<<"* ";}
              else{cout<<"  ";}
        }
        for(int j=2; j<=i; j++){
             if(i==j){cout<<"* ";}
              else{cout<<"  ";}
        }
        for(int j=1; j<=n-i; j++){
             cout<<"* ";
        }
        cout<<endl;
        
    }
    for(int i=n; i>=1; i--){
        for(int j=1; j<=n-i; j++){
            cout<<"* ";
        }
        for(int j=i; j>=1; j--){
            
              if(i==j){cout<<"* ";}
              else{cout<<"  ";}
        }
        for(int j=2; j<=i; j++){
             if(i==j){cout<<"* ";}
              else{cout<<"  ";}
        }
         for(int j=1; j<=n-i; j++){
             cout<<"* ";
        }
        cout<<endl;
    }
    return 0;
}
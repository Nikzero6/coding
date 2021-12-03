#include <bits/stdc++.h>
using namespace std;
//only for sorted  matrix

int main() {
    int n,m;
    cin>>n>>m;

    int target;
    cin>>target;

    int a[n][m];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>a[i][j];
        }
    }

    int r=0, c=m-1;
    bool found=false;

    while(r<n && c>=0){

        if(a[r][c] == target){
            found = true;
            break;
        }
        else if(a[r][c] > target){
            c--;
        }
        else {
            r++;
        }
   }

   if(found){
       cout<<"element found";
   }
   else {
       cout<<"not found";
   }

   return 0;
}
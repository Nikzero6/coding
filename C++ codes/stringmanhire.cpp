#include <bits/stdc++.h>
using namespace std;

int main(){
    string str = "xxy";

    int op=0;

    int l = str.length();
    int count = 0;

    if(l%2 == 0){
        for(int i=0; i<l; i++){
            if(str[i] != str[l-i]){
                count++;
            }
        }
    }
}
#include <bits/stdc++.h>

using namespace std;

string addBinary(string bin1, string bin2){
    string sum;
    int carry=0;

    string zero;
    for(int i = 0; i < (bin1.size() - bin2.size()); i++){
        zero.push_back(0);
    }

    if(bin1.size()<bin2.size()){
        bin1 = zero + bin1;
    }
    else if(bin2.size()<bin1.size()){
        bin2 = zero + bin2;
    }

    sum.resize(bin1.size());

    for(int i=bin1.size()-1; i>=0; i--){

        if(bin1[i] == '1' && bin2[i] == '1'){
           
            sum[i] = carry+'0';
            carry++;
             if(i == 0){
                sum.insert(i, "1");
            }
        }
        else if(bin1[i] == '0' && bin2[i] == '0'){
             sum[i] = carry+'0';
            if(carry == 1)
                carry--;
        }
        else{
            if(carry == 1){
                sum[i] = '0';
                 if(i == 0){
                 sum.insert(i, "1");
                }
            }
            else{
                sum[i] = '1';
            }
        }
    }

    return sum;
}

int main(){
    
    string bin1, bin2;
    cin>>bin1>>bin2;

    cout<<addBinary(bin1, bin2);

    return 0;
}
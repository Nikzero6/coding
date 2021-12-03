#include <iostream>
using namespace std;

int check_niven(int n){
    int sum = 0;
    int org_num = n;

    while(n>0){
        int rem = n%10;

        sum += rem;

        n /= 10;
    }

    if(n%sum == 0)
        return (org_num/sum);
    else
        return 0;
}
int main(){

    int n;
    cin>>n;

    int result = check_niven(n);

    cout<<result;

    return 0;
}
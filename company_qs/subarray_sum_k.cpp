#include <iostream>
using namespace std;

int main(){
    
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];

    int sum = 0;
    int key;
    cin>>key;
    int i=0, j=0;

    while(i<n){

        sum += a[j];

        if(a[j] > key){
            i=j+1;
            j++;
            sum = 0;
        }
        else {
            if(sum == key){
            cout<<i<<" "<<j;
            break;
            }
            else if(sum < key){
                j++;
            }
            else {
                while(sum > key){
                    sum -= a[i++];
                }
                if(sum == key){
                    cout<<i<<" "<<j;
                    break;
                }
                else j++;
            }
        }
    }

    return 0;
}
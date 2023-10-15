#include<iostream>
using namespace std;

int main(){
    long long int n;
    cin >> n;
    cout << n << "\t";
    while(n>1){
        if(n%2==0){
            cout << n/2 << "\t";
            n = n/2;
        }
        else{
            cout << 3*n+1 << "\t";
            n = 3*n+1;
        }
    }
}
#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n-1;i++){
        cin >> a[i];
    }
    int pos;
    cin >> pos;
    int ele;
    cin >> ele;
    for(int i=n-2;i>=pos;i--){
        a[i+1]=a[i];
    }
    a[pos]=ele;
    for(int i=0;i<n;i++){
        cout << a[i] << '\t';
    }
}
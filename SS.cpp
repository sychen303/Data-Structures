#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n];
    int c = 0;
    int b[100000000] = {0};
    for(int i=0;i<n;i++){
        cin >> a[i];
        b[a[i]]++;
    }
    for(int i=0;;i++){
        if(b[i]>0){
            c++;
        }
    }
    cout << c;
}
#include <iostream>
using namespace std;
int fact(int n){
    return (n==1)?1:n*fact(n-1);
}
int main() {
    int n;
    cout<<"enter the number: ";
    cin>>n;
    cout<<fact(n);
    return 0;
}

#include<iostream>
using namespace std;
int getMax(int &a, int &b){
    return (a>b) ? a : b;
}
int main() {
    int a = 2, b = 3;
    int ans = getMax(a,b);
    cout << ans << endl;
    a = a+5;
    b = b+3;
    ans = getMax(a,b);
    cout << ans << endl;
}
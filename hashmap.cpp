#include <map>
#include <iostream>
using namespace std;
int main() {
    map <string,int> directory;
    directory["Amit"] = 10;
    directory["Aman"] = 55;
    directory["Naman"]  = 77;
    for (auto i:directory) {
        cout << "Name " << i.first;
        cout << "phone " << i.second<<endl;
    }
}
#include<iostream>
using namespace std;
int main(){
    int n;
    cout << "Enter the number of rows: ";
    cin >> n;
    int **arr = new int *[n];
    for(int i = 0; i < n; i++){
        arr[i] = new int[n];
    }
    cout << "Enter the elements of the 2D array: " << endl;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }
    cout << "The 2D array is: "<<endl;
    for (int i=0; i<n; i++){
        for (int j=0 ;j<n; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
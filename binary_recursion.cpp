#include<iostream>
using namespace std;

int binarySearch(int arr[], int s, int e, int k){
    if (s > e)
        return -1;

    int mid = s + (e - s)/2;

    if (arr[mid] == k)
        return mid;

    else if (arr[mid] < k)
        return binarySearch(arr, mid + 1, e, k);

    else
        return binarySearch(arr, s, mid - 1, k);
}

int main() {
    int arr[] = {2,3,4,5,6,7};
    int n = 6;
    int k = 6;

    int result = binarySearch(arr, 0, n-1, k);

    if (result == -1)
        cout << "Element not found";
    else
        cout << "Element found at index: " << result;

    return 0;
}
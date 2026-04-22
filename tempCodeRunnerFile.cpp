#include <iostream>
using namespace std;
int main() {
    int pageSize, numPages;
    cout << "Enter page size: ";
    cin >> pageSize;
    cout << "Enter number of pages: ";
    cin >> numPages;
    int pageTable[numPages];
    cout << "Enter frame number for each page:\n";
    for(int i = 0; i < numPages; i++) {
        cout << "Page " << i << " -> Frame: ";
        cin >> pageTable[i];
    }
    int logicalAddress;
    cout << "\nEnter logical address: ";
    cin >> logicalAddress;
    int pageNumber = logicalAddress / pageSize;
    int offset = logicalAddress % pageSize;
    if(pageNumber >= numPages) {
        cout << "Invalid logical address (Page number out of range)\n";
        return 0;
    }
    int frameNumber = pageTable[pageNumber];
    int physicalAddress = frameNumber * pageSize + offset;
    cout << "\nPage Number: " << pageNumber;
    cout << "\nOffset: " << offset;
    cout << "\nFrame Number: " << frameNumber;
    cout << "\nPhysical Address: " << physicalAddress << endl;
    return 0;
}
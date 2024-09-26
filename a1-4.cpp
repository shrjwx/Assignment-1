#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

// Function to find the median of two sorted arrays
double findMedian(int arr1[], int size1, int arr2[], int size2) {
    int totalSize = size1 + size2;
    int merged[totalSize];
    
    // Merge the two arrays into one
    int i = 0, j = 0, k = 0;
    
    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]) {
            merged[k++] = arr1[i++];
        } else {
            merged[k++] = arr2[j++];
        }
    }
    
    while (i < size1) {
        merged[k++] = arr1[i++];
    }
    
    while (j < size2) {
        merged[k++] = arr2[j++];
    }
    
    // Calculate the median
    if (totalSize % 2 == 0) {
        return (merged[totalSize / 2 - 1] + merged[totalSize / 2]) / 2.0;
    } else {
        return merged[totalSize / 2];
    }
}

int main() {
    int size1;
    cin >> size1;

    int arr[size1];
    for (int i = 0; i < size1; ++i) {
        cin >> arr[i];
    }

    int size2;
    cin >> size2;

    if (size1 == 0 && size2 == 0){
        cout << "Empty Array" << endl;
        return 0;
    }
    int arr1[size2];
    for (int i = 0; i < size2; ++i) {
        cin >> arr1[i];
    }
    
    // Handle cases where one array is empty
    if (size1 == 0) {
        cout << fixed << setprecision(1);
        cout << "Median = " << (size2 % 2 == 0 ? (arr1[size2 / 2 - 1] + arr1[size2 / 2]) / 2.0 : arr1[size2 / 2]) << endl;
        return 0;
    }
    
    if (size2 == 0) {
        cout << fixed << setprecision(1);
        cout << "Median = " << (size1 % 2 == 0 ? (arr[size1 / 2 - 1] + arr[size1 / 2]) / 2.0 : arr[size1 / 2]) << endl;
        return 0;
    }

    // Output the median with fixed decimal precision
    cout << fixed << setprecision(1);
    cout << "Median = " << findMedian(arr, size1, arr1, size2) << endl;
    
    return 0;
}


#include <iostream>
#include <vector>
using namespace std;

// Merge two sorted parts of the array
void merge(vector<int>& arr, int si, int mid, int ei) {

    vector<int> temp;

    // i points to the left part
    int i = si;

    // j points to the right part
    int j = mid + 1;

    // Compare elements from both parts
    while (i <= mid && j <= ei) {

        // Take the smaller element
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        }
        else {
            temp.push_back(arr[j]);
            j++;
        }
    }

    // Add remaining elements from left part
    while (i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }

    // Add remaining elements from right part
    while (j <= ei) {
        temp.push_back(arr[j]);
        j++;
    }

    // Copy sorted elements back to original array
    int x = 0;

    for (int idx = si; idx <= ei; idx++) {
        arr[idx] = temp[x];
        x++;
    }
}

// Divide the array into smaller parts
void divide(vector<int>& arr, int si, int ei) {

    // If only one element is present, stop
    if (si >= ei) {
        return;
    }

    // Find the middle index
    int mid = si + (ei - si) / 2;

    // Sort the left half
    divide(arr, si, mid);

    // Sort the right half
    divide(arr, mid + 1, ei);

    // Merge the two sorted halves
    merge(arr, si, mid, ei);
}

int main() {

    // Create the array
    vector<int> arr = {5, 2, 3, 1};

    // Find the size of the array
    int n = arr.size();

    // Apply merge sort
    divide(arr, 0, n - 1);

    // Print the sorted array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
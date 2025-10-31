#include <iostream>
#include <vector>
using namespace std;

// Function to partition array (for Quick Sort & Quick Select)
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Choose the last element as pivot
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Quick Sort function
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Quick Select function (to find k-th smallest element)
int quickSelect(vector<int>& arr, int low, int high, int k) {
    if (low <= high) {
        int pi = partition(arr, low, high);

        if (pi == k - 1)
            return arr[pi];
        else if (pi > k - 1)
            return quickSelect(arr, low, pi - 1, k);
        else
            return quickSelect(arr, pi + 1, high, k);
    }
    return -1; // Invalid case
}

// Function to print array
void printArray(const vector<int>& arr) {
    for (int val : arr)
        cout << val << " ";
    cout << endl;
}

// ---- Driver Code ----
int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "\nOriginal Array: ";
    printArray(arr);

    // Quick Sort
    vector<int> sortedArr = arr;
    quickSort(sortedArr, 0, n - 1);
    cout << "\nSorted Array (Quick Sort): ";
    printArray(sortedArr);

    // Quick Select
    int k;
    cout << "\nEnter k to find k-th smallest element: ";
    cin >> k;

    if (k >= 1 && k <= n) {
        int kth = quickSelect(arr, 0, n - 1, k);
        cout << "The " << k << "-th smallest element is: " << kth << endl;
    } else {
        cout << "Invalid k! Must be between 1 and " << n << "." << endl;
    }

    return 0;
}

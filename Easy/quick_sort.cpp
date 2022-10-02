// Similar to the Merge Sort algorithm, the Quick Sort algorithm is a Divide and Conquer algorithm. It initially selects an element as a pivot element
// and partitions the given array around the picked pivot. There are many different versions of quickSort that pick pivot in different ways. 
// 
// Always pick the first element as a pivot (implemented below).
// Always pick the last element as the pivot.
// Pick a random element as a pivot.
// Pick median as a pivot.
// The key process in quickSort is the partition() process. The aim of the partition() function is to receive an array and an element x of the array as a pivot, 
// put x at its correct position in a sorted array and then put all smaller elements (smaller than x) before x, and put all greater elements (greater than x) after x. All this should be done in linear time i.e.  Big O(n) .
// Pseudo Code for recursive QuickSort function : 
// 
// /* low  --> Starting index,  high  --> Ending index */
// quickSort(arr[], low, high)
// {
//     if (low < high)
//     {
//         /* pi is partitioning index, arr[p] is now
//            at right place */
//         pi = partition(arr, low, high);
// 
//         quickSort(arr, low, pi - 1);  // Before pi
//         quickSort(arr, pi + 1, high); // After pi
//     }
// }

#include <iostream>
using namespace std;
 
int partition(int arr[], int start, int end)
{
 
    int pivot = arr[start];
 
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }
 
    // Giving pivot element its correct position
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);
 
    // Sorting left and right parts of the pivot element
    int i = start, j = end;
 
    while (i < pivotIndex && j > pivotIndex) {
 
        while (arr[i] <= pivot) {
            i++;
        }
 
        while (arr[j] > pivot) {
            j--;
        }
 
        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }
 
    return pivotIndex;
}
 
void quickSort(int arr[], int start, int end)
{
 
    // base case
    if (start >= end)
        return;
 
    // partitioning the array
    int p = partition(arr, start, end);
 
    // Sorting the left part
    quickSort(arr, start, p - 1);
 
    // Sorting the right part
    quickSort(arr, p + 1, end);
}
 
int main()
{
 
    int arr[] = { 9, 3, 4, 2, 1, 8 };
    int n = 6;
 
    quickSort(arr, 0, n - 1);
 
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
 
    return 0;
}

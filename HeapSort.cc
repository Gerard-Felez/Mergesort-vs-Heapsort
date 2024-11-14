// C++ program for implementation of Heap Sort
#include <iostream>
#include <vector>
using namespace std;
 
// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void heapify(vector<int>& v, int n, int i)
{
    int largest = i; // Initialize largest as root Since we are using 0 based indexing
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2
 
    // If left child is larger than root
    if (l < n && v[l] > v[largest])
        largest = l;
 
    // If right child is larger than largest so far
    if (r < n && v[r] > v[largest])
        largest = r;
 
    // If largest is not root
    if (largest != i) {
        swap(v[i], v[largest]);
 
        // Recursively heapify the affected sub-tree
        heapify(v, n, largest);
    }
}
 
// main function to do heap sort
void heapSort(vector<int>& v, int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(v, n, i);
 
    // One by one extract an element from heap
    for (int i = n - 1; i >= 0; i--) {
        // Move current root to end
        swap(v[0], v[i]);
 
        // call max heapify on the reduced heap
        heapify(v, i, 0);
    }
}
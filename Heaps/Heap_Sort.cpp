#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int>& heap, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && heap[left] > heap[largest])
        largest = left;

    if (right < n && heap[right] > heap[largest])
        largest = right;

    if (largest != i)
    {
        swap(heap[i], heap[largest]);
        heapify(heap, n, largest);
    }
}

void heapSort(vector<int>& heap)
{
    int n = heap.size();
    for(int i = n/2 -1; i>=0; i--)
    {
        heapify(heap, n, i);
    }
    for(int i=n-1; i>0; i--)
    {
        swap(heap[0], heap[i]);
        heapify(heap, i, 0);
    }
}

int main() {
    vector<int> heap = {10, 20, 15, 30, 40};

    cout << "Before Heap Sort: ";
    for (int val : heap) cout << val << " ";
    cout << endl;

    heapSort(heap);

    cout << "After Heap Sort: ";
    for (int val : heap) cout << val << " ";
    cout << endl;

    return 0;
}

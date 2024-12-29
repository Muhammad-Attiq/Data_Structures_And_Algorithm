#include <iostream>

using namespace std;

void heapifyDown(vector<int>& heap, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && heap[left] > heap[largest])
        largest = left;

    if (right < n && heap[right] > heap[largest])
        largest = right;

    if (largest != i) {
        swap(heap[i], heap[largest]);
        heapifyDown(heap, n, largest);
    }
}

void deleteRoot(vector<int>& heap)
{
    int n = heap.size();
    if (n == 0) return;

    heap[0] = heap[n - 1];
    heap.pop_back();
    heapifyDown(heap, heap.size(), 0);
}

int main()
{
    vector<int> heap = {20, 18, 10, 12, 9, 9, 3, 5, 6, 8};

    cout << "Heap before deletion: ";
    for (int val : heap) cout << val << " ";
    cout << endl;

    deleteRoot(heap);

    cout << "Heap after deletion: ";
    for (int val : heap) cout << val << " ";
    cout << endl;

    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

void heapify(vector<int>& heap, int n, int i)
{
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if(left < n && heap[left] > heap[largest])
    {
        largest = left;
    }
    if(right < n && heap[right] > heap[largest])
    {
        largest = right;
    }
    if(largest != i)
    {
        swap(heap[i], heap[largest]);
        heapify(heap, n, largest);
    }
}

void build_heap(vector <int> & heap)
{
    int n = heap.size();
    for(int i=n/2-1; i >=0; i--)
    {
        heapify(heap, n, i);
    }
}

int main()
{
    vector <int> heap = {3, 6, 9, 7, 33, 44, 23, 90};

    for(int val : heap)
    {
        cout << val << " ";
    }

    build_heap(heap);
    cout << endl;

    for(int val : heap)
    {
        cout << val << " ";
    }

    return 0;
}

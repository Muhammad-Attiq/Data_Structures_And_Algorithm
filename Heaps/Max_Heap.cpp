#include <iostream>
#include <vector>

using namespace std;

class MaxHeap
{
private:
    vector<int> heap;

    void heapifyup(int index)
    {
        int parent = (index - 1) / 2;
        if (index > 0 && heap[index] > heap[parent])
        {
            swap(heap[index], heap[parent]);
            heapifyup(parent);
        }
    }

    void heapifydown(int index)
    {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int largest = index;

        if (left < heap.size() && heap[left] > heap[largest])
        {
            largest = left;
        }
        if (right < heap.size() && heap[right] > heap[largest])
        {
            largest = right;
        }
        if (largest != index)
        {
            swap(heap[index], heap[largest]);
            heapifydown(largest);
        }
    }

public:
    void insert(int value)
    {
        heap.push_back(value);
        heapifyup(heap.size() - 1);
    }

    int extractMax()
    {
        if (heap.empty())
        {
            throw out_of_range("Heap is empty");
        }
        int max_val = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifydown(0);
        return max_val;
    }

    void display()
    {
        for (int val : heap)
        {
            cout << val << " ";
        }
        cout << endl;
    }
};

int main()
{
    MaxHeap m;
    m.insert(10);
    m.insert(20);
    m.insert(30);
    m.insert(5);
    m.insert(25);

    cout << "Heap elements: ";
    m.display();

    int extract_max = m.extractMax();
    cout << "Extracted max is: " << extract_max << endl;

    cout << "Heap after extraction: ";
    m.display();

    return 0;
}

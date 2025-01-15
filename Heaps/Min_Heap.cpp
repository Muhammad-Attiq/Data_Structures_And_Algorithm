#include <iostream>
#include <vector>

using namespace std;

class MinHeap
{
private:
    vector<int> heap;

    void heapifyup(int index)
    {
        int parent = (index - 1) / 2;
        if (index > 0 && heap[index] < heap[parent])
        {
            swap(heap[index], heap[parent]);
            heapifyup(parent);
        }
    }

    void heapifydown(int index)
    {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int smallest = index;

        if (left < heap.size() && heap[left] < heap[smallest])
        {
            smallest = left;
        }
        if (right < heap.size() && heap[right] < heap[smallest])
        {
            smallest = right;
        }
        if (smallest != index)
        {
            swap(heap[index], heap[smallest]);
            heapifydown(smallest);
        }
    }

public:
    void insert(int value)
    {
        heap.push_back(value);
        heapifyup(heap.size() - 1);
    }

    int extractMin()
    {
        if (heap.empty())
        {
            throw out_of_range("Heap is empty");
        }
        int min_val = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifydown(0);
        return min_val;
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
    MinHeap m;
    m.insert(10);
    m.insert(20);
    m.insert(30);
    m.insert(5);
    m.insert(25);

    cout << "Heap elements: ";
    m.display();

    int extract_min = m.extractMin();
    cout << "Extracted min is: " << extract_min << endl;

    cout << "Heap after extraction: ";
    m.display();

    return 0;
}

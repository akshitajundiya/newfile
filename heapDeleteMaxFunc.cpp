//RIGHT CODE FOR DELETING THE MAXIMUM ELEMENT IN MIN-MAX HEAP
#include <bits/stdc++.h>
using namespace std;

void max_heapify_down(vector<int>& heap, int index) 
{
    int size = heap.size();
    int largest = index;
    
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;
    
    if (leftChild < size && heap[leftChild] > heap[largest]) 
    {
        largest = leftChild;
    }

    if (rightChild < size && heap[rightChild] > heap[largest]) 
    {
        largest = rightChild;
    }

    if (largest != index) 
    {
        swap(heap[index], heap[largest]);
        max_heapify_down(heap, largest);
    }
}

void delete_max(vector<int>& heap) 
{
    if (heap.size() == 0) 
    {
        cout << "Heap is empty!" << endl;
        return;
    }

    int maxIndex = (heap.size() > 2 && heap[2] > heap[1]) ? 2 : 1;

    heap[maxIndex] = heap.back();
    heap.pop_back();  

    if (maxIndex < heap.size()) 
    {
        max_heapify_down(heap, maxIndex);
    }

    cout << "Max element deleted." << endl;
}

int main() 
{
    vector<int> heap = {1, 10, 8, 9, 7, 5, 4};  
    
    cout << "Original heap: ";
    for (int val : heap) 
    {
        cout << val << " ";
    }
    cout << endl;
    
    delete_max(heap); 

    cout << "Heap after deleting max: ";
    for (int val : heap) 
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

// Function to get the index of the left child of a node
int leftChild(int i) {
    return 2 * i + 1;
}

// Function to get the index of the right child of a node
int rightChild(int i) {
    return 2 * i + 2;
}

// Function to get the index of the parent of a node
int parent(int i) {
    return (i - 1) / 2;
}

// Function to swap two elements in the heap
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Function to maintain the min-heap property after inserting a new element
void minHeapifyUp(vector<int> &heap, int index) {
    while (index > 0 && heap[index] < heap[parent(index)]) {
        swap(heap[index], heap[parent(index)]);
        index = parent(index);
    }
}

// Function to maintain the min-heap property after extracting the minimum element
void minHeapifyDown(vector<int> &heap, int index) {
    int left = leftChild(index);
    int right = rightChild(index);
    int smallest = index;

    if (left < heap.size() && heap[left] < heap[smallest])
        smallest = left;
    if (right < heap.size() && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != index) {
        swap(heap[index], heap[smallest]);
        minHeapifyDown(heap, smallest);
    }
}

// Function to extract the minimum value from the heap
int heapExtractMin(vector<int> &heap) {
    if (heap.empty()) {
        cout << "Heap is empty!" << endl;
        return INT_MAX; // Return a maximum value to indicate an error
    }

    int minVal = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    minHeapifyDown(heap, 0);
    return minVal;
}

// Function to insert a new value into the heap
void minHeapInsert(int value, vector<int> &heap) {
    heap.push_back(value);
    minHeapifyUp(heap, heap.size() - 1);
}

// Function to decrease the value at a specific index and maintain the min-heap property
void heapDecreaseKey(int index, int k, vector<int> &heap) {
    if (index >= heap.size() || index < 0) {
        cout << "Invalid index!" << endl;
        return;
    }

    if (k > heap[index]) {
        cout << "New value is greater than the current value!" << endl;
        return;
    }

    heap[index] -= k;
    minHeapifyUp(heap, index);
}

// Function to increase the value at a specific index and maintain the min-heap property
void heapIncreaseKey(int index, int k, vector<int> &heap) {
    if (index >= heap.size() || index < 0) {
        cout << "Invalid index!" << endl;
        return;
    }

    heap[index] += k;
    minHeapifyDown(heap, index);
}

int main() {
    vector<int> minHeap;

    // Read input numbers into the heap
    string input;
    getline(cin, input);
    stringstream ss(input);
    int num;
    while (ss >> num && num != -1) {
        minHeapInsert(num, minHeap);
    }

    // Print the initial heap
    cout << "Initial Min-Heap: ";
    for (int num : minHeap) {
        cout << num << " ";
    }
    cout << endl;

    // Process function calls
    while (cin >> num) {
        if (num == 1) {
            // Heap_Minimum
            int minVal = heapExtractMin(minHeap);
            cout << "Heap_Minimum: " << minVal << endl;
        } else if (num == 2) {
            // Heap_extract_min
            int minVal = heapExtractMin(minHeap);
            cout << "Heap_extract_min: " << minVal << endl;
        } else if (num == 3) {
            // Heap_decrease_key
            int index, k;
            cin >> index >> k;
            heapDecreaseKey(index, k, minHeap);
            cout << "Heap_decrease_key: " << k << endl;
        } else if (num == 4) {
            // Heap_increase_key
            int index, k;
            cin >> index >> k;
            heapIncreaseKey(index, k, minHeap);
            cout << "Heap_increase_key: " << k << endl;
        } else if (num == 5) {
            // Print the current state of the heap
            cout << "Current state of the heap: ";
            for (int num : minHeap) {
                cout << num << " ";
            }
            cout << endl;
        } else {
            cout << "Invalid function_id: " << num << endl;
        }
    }

    return 0;
}


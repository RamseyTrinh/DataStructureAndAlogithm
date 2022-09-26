#include<bits/stdc++.h>
using namespace std;

void heapify(vector<int>&heap, int pos) {
    int largest = pos;
    int l = 2 * pos + 1;
    int r = 2 * pos + 2;
    int size = heap.size();
    if(l < size && heap[largest] < heap[l]) {
        largest = l;
    }
    if(r < size && heap[largest] < heap[r]) {
        largest = r;
    }
    if(pos != largest) {
        swap(heap[pos],heap[largest]);
        heapify(heap,largest);
    }
}

void insert(vector<int>&heap, int num) {
    heap.push_back(num);
    if(heap.size() > 1) {
        for(int i = heap.size()/2 - 1; i >= 0; i--) {
            heapify(heap,i);
        }
    }
}

void deleteNode(vector<int>&heap, int num) {
    for(int i = 0; i < heap.size(); i++) {
        if(heap[i] == num) {
            swap(heap[i],heap[heap.size() - 1]);
            heap.pop_back();
            break;
        }
    }
    for(int i = heap.size()/2 - 1; i >= 0; i--) {
        heapify(heap,i);
    }
}

void print(vector<int>heap) {
    for(auto it : heap) {
        cout << it << " ";
    }
}

void heapsort(vector<int>heap) {
    while(!heap.empty()) {
        cout << heap[0] << " ";
        swap(heap[0],heap[heap.size() - 1]);
        heap.pop_back();
        heapify(heap,0);
    }
}

int main() {
    vector<int>maxHeap;
    insert(maxHeap,7);
    insert(maxHeap,1);
    insert(maxHeap,4);
    insert(maxHeap,6);
    insert(maxHeap,0);
    insert(maxHeap,9);
    print(maxHeap);
    cout << "\n";
    deleteNode(maxHeap,4);
    print(maxHeap);
    cout << "\n";
    heapsort(maxHeap);
}
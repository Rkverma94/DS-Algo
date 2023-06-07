#include<bits/stdc++.h>
using namespace std;
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}
void heapify(vector<int> &arr, int n, int x) {
    //x is the index of the element which is to be heapify
    int max = x;
    int leftChildIdx = 2*x+1;
    int rightChildIdx = 2*x+2; 
    if(leftChildIdx < n && arr[leftChildIdx] > arr[max]) {
        max = leftChildIdx;
    }
    if(rightChildIdx < n && arr[rightChildIdx] > arr[max]) {
        max = rightChildIdx;
    }
    //check if max not equals to x
    if(max != x) {
        swap(&arr[x], &arr[max]);
        heapify(arr, n, max);
    }
}
void printArr(vector<int> &arr) {
    cout<<"Array elements are:" <<endl;
    for(int i=0; i<arr.size();i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void heapSort(vector<int> &arr) {
    int idx = (arr.size()/2)-1;
    for(int i=idx; i>=0; i--) {
        heapify(arr, arr.size(), i);
    }
    printArr(arr);
    //Extract elements from heap
    for(int i=arr.size()-1; i>=0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
    cout<<"Arr after sorting"<<endl;
    printArr(arr);
}
int main() {
    vector<int> arr = {1,12,9,5,6,10,2,4,13,18};
    heapSort(arr);
    return 0;
}
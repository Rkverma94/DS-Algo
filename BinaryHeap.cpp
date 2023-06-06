#include<bits/stdc++.h>
using namespace std;

void swap(int *x, int *max) {
    int temp = *x;
    *x = *max;
    *max = temp;
}

//Method that will correct the node and make it a heap
void heapify(vector<int> &arr, int x) {
    //get the size of array to compare it with left and right child
    int s = arr.size();
    //copy the element to a variable where we will store maximum
    int max = x;
    // left child of x
    int left = 2*x+1;
    // right child of x
    int right = 2*x+2;
    // if array index of left child is in range and left child is greater than it's root then move left pointer to max
    if(left < s && arr[left] > arr[max]) {
        max = left;
    }
    // if array index of right child is in range and right child is greater than it's root then move right pointer to max
    if(right < s&& arr[right] > arr[max]) {
        max = right;
    }
    //if max and x are not same then swap them and call heapify to correct the heap
    if(max != x) {
        swap(&arr[x], &arr[max]);
        heapify(arr, max);
    }
}

void insert(vector<int> &arr, int x) {
    int s = arr.size();
    //if size is zero then add the element to the array
    if(s == 0) {
        arr.push_back(x);
    } else {
        //add element to the array
        arr.push_back(x);
        //calculate index for it's root
        int index = (arr.size()/2)-1;
        for(int i=index; i>=0; i--) {
            //heapify the tree at i as tree from i-1 is already heap
            heapify(arr, i);
        }
    }
}

void deleteNode(vector<int> &arr, int x) {
    //search for the element 
    int i;
    for(i=0; i<arr.size(); i++) {
        if(x == arr[i]) break;
    }
    swap(&arr[i], &arr[arr.size()-1]);
    arr.pop_back();
    cout<<"heap after deletion before heapify:"<<endl;
    for(int idx=0; idx<arr.size(); idx++) {
        cout<<arr[idx]<<" "<<endl;
    }
    //correct the heap by calling heapify
    for(int k=(arr.size()/2) - 1; k>=0; k--) {
        heapify(arr, k);
    }
}
int main() {
    vector<int> arr;
    insert(arr, 1);
    insert(arr, 4);
    insert(arr, 2);
    insert(arr, 7);
    insert(arr, 3);
    cout<<"heap as an array :"<<endl;
    for(int i=0; i<arr.size(); i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    deleteNode(arr, 7);
    cout<<"Heap after heapify :"<<endl;
    for(int i=0; i<arr.size(); i++) {
        cout<<arr[i]<<" ";
    }
    return 0;
}
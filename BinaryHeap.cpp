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
int main() {
    vector<int> arr;
    insert(arr, 1);
    insert(arr, 4);
    insert(arr, 2);
    insert(arr, 7);
    cout<<"heap as an array :"<<endl;
    for(int i=0; i<arr.size(); i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
class SortAlgos {

    void divideArr(vector<int> &, int, int);
    void mergeArr(vector<int> &, int, int, int);
    public:
    SortAlgos() {

    }

    void mergeSort(vector<int> &);

};

void SortAlgos :: mergeArr(vector<int> &arr, int left, int mid, int right) {
    vector<int> leftArr;
    vector<int> rightArr;
    leftArr.resize(mid + 1 - left);
    rightArr.resize(right - mid);
    cout<<"left arr capacity : "<<leftArr.capacity()<<endl;
    cout<<"right arr capacity : "<<rightArr.capacity()<<endl;
    /* mid + 1 = total number of elements 
    now (- left) i.e. we have to minus the value of left in order to get actual size  
    Ex: left = 0, right = 7, mid = left + (right - left) / 2 = 0 + (7 - 0) / 2 = 3
    mid = 3. Left arr size should be 4 i.e. 0 to 4 
    mid + 1 - left = 3 + 1 - 0 = 4 
    similarly right arr size should be equals to 4 i.e. right - mid = 7 - 3 = 4*/
    
    //initialize left and right arr elements from arr i.e. original array*/
    for(int i=0; i<leftArr.capacity(); i++) {
        leftArr[i] = arr[left + i];
    }

    for(int i=0; i<rightArr.capacity(); i++) {
        rightArr[i] = arr[mid + 1 + i];
    }
    
    //initialize the indices of left, right and original array for final sorting
    int leftIdx = 0, rightIdx = 0, arrIdx = left;
    //compare both left and right array's values till one of them is exhausted
    while(leftIdx < leftArr.capacity() && rightIdx < rightArr.capacity()) {
        if(leftArr[leftIdx] <= rightArr[rightIdx]) {
            arr[arrIdx] = leftArr[leftIdx];
            leftIdx++;
        } else {
            arr[arrIdx] = rightArr[rightIdx];
            rightIdx++;
        }
        arrIdx++;
    }

    //copy another array if one of them is exhausted
    while(leftIdx < leftArr.capacity()) {
        arr[arrIdx] = leftArr[leftIdx];
        leftIdx++;
        arrIdx++;
    }

    while(rightIdx < rightArr.capacity()) {
        arr[arrIdx] = rightArr[rightIdx];
        rightIdx++;
        arrIdx++;
    }

}

void SortAlgos :: divideArr(vector<int> &arr, int left, int right) {
    if(left >= right) {
        return;
    }
    int mid = left + (right - left) / 2;
    divideArr(arr, left, mid);
    divideArr(arr, mid+1, right);
    mergeArr(arr, left, mid, right);
}

void SortAlgos :: mergeSort(vector<int> &arr) {
    divideArr(arr, 0, arr.size() - 1);
}

int main() {
    vector<int> v{3,2,6,10,4,100,23,87};
    SortAlgos sortAlgo;
    sortAlgo.mergeSort(v);
    for(int i=0; i<v.size(); i++) {
        cout<<v[i]<<",";
    }
    return 0;
}
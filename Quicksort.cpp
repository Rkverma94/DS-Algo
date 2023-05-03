#include<bits/stdc++.h>
using namespace std;
class Quicksort {
    public :
        Quicksort(int* arr, int lower, int upper) {
            quicksortRec(arr, lower, upper);
        }
        void quicksortRec(int*, int, int);
        int partition(int*, int, int);
};

void Quicksort :: quicksortRec(int* arr, int lower, int upper) {
    cout<<lower<<" "<<upper<<endl;
    static int pass = 0;
    if(lower < upper) {
        int q = partition(arr, lower, upper);
        cout<<"q value = "<<q<<" pass = "<<pass++<<endl;
        cout<<"lower array is : "<<endl;
        for(int i=lower; i<q; i++) {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        quicksortRec(arr, lower, q-1);
        cout<<"upper array is : "<<endl;
        for(int i=q; i<upper; i++) {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        quicksortRec(arr, q+1, upper);
    }
}

int Quicksort :: partition(int* arr, int lower, int upper) {
    int pivot = arr[upper];
    int i = lower;
    int j = upper;
    cout<<"initial value of i and j are "<<i<<", "<<j<<endl;
    while(1) {
        cout<<"arr[j] > pivot = "<<(arr[j] > pivot)<<" arr[j] and pivot are "<<arr[j]<<" "<<pivot<<endl;
        while(arr[j] > pivot) {
            j = j - 1;
        }
        cout<<"value of j and arr[j] now are "<<j<<", "<<arr[j]<<endl;
        cout<<"arr[i] < pivot = "<<(arr[i] < pivot)<<" arr[i] and pivot are "<<arr[i]<<" "<<pivot<<endl;
        while(arr[i] < pivot) {
            i = i + 1;
        }
        cout<<"value of i are arr[i] now are "<<i<<", "<<arr[i]<<endl;
        if(i < j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            cout<<"after swapping contents of arr[i] and arr[j] are "<<arr[i]<<" "<<arr[j]<<endl;
        } else {
            return j;
        }
    }
}

int main() {
    int arr[8] = {17, 12, 6, 19, 23, 8, 5, 10};
    Quicksort qsort(arr, 0, 7);
    for(int i=0; i<8; i++) {
        cout<<arr[i]<<" ";
    }
    return 0;
}
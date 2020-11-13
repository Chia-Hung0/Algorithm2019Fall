// **************************************************************************
//  File       [sort_tool.cpp]
//  Author     [Yu-Hao Ho]
//  Synopsis   [The implementation of the SortTool Class]
//  Modify     [2019/9/6 Cheng-Yun Hsieh]
// **************************************************************************

#include "sort_tool.h"
#include<iostream>

// Constructor
SortTool::SortTool() {}

// Insertsion sort method
void SortTool::InsertionSort(vector<int>& data) {
    // Function : Insertion sort
    for(int i=1;i<data.size();i++){
        int j=i;
        while(data[j]<data[j-1]&&j>0){
            swap(data[j-1],data[j]);
            j--;
        }
    }
    // TODO : Please complete insertion sort code here
}

// Quick sort method
void SortTool::QuickSort(vector<int>& data){
    QuickSortSubVector(data, 0, data.size() - 1);
}
// Sort subvector (Quick sort)
void SortTool::QuickSortSubVector(vector<int>& data, int low, int high) {
    // Function : Quick sort subvector
    // TODO : Please complete QuickSortSubVector code here
    int P;
    if(high>low){
        P=Partition(data,low,high);
        QuickSortSubVector(data,low,P-1);
        QuickSortSubVector(data,P+1,high);
    }



    // Hint : recursively call itself
    //        Partition function is needed
}

int SortTool::Partition(vector<int>& data, int low, int high) {
    // Function : Partition the vector

    int x=data[high],i=low-1;
    for(int j=low;j<high;j++){
        if(data[j]<=x){
            i++;
            int value=data[i];
            data[i]=data[j];
            data[j]=value;
        }
    }
        data[high]=data[i+1];
        data[i+1]=x;
        return i+1;


    // TODO : Please complete the function
    // Hint : Textbook page 171
}

// Merge sort method
void SortTool::MergeSort(vector<int>& data){
    MergeSortSubVector(data, 0, data.size() - 1);
}

// Sort subvector (Merge sort)
void SortTool::MergeSortSubVector(vector<int>& data, int low, int high) {
    // Function : Merge sort subvector
    // TODO : Please complete MergeSortSubVector code here
    int middle;
    if(high>low){
        middle=(high+low)/2;
        MergeSortSubVector(data,low,middle);
        MergeSortSubVector(data,middle+1,high);
        Merge(data,low,middle,middle+1,high);
    }
    // Hint : recursively call itself
    //        Merge function is needed
}

// Merge
void SortTool::Merge(vector<int>& data, int low, int middle1, int middle2, int high) {
    // Function : Merge two sorted subvector
    int xl=middle1-low+1,yl=high-middle2+1;
    int x[xl],y[yl];
    for(int k=0;k<xl;k++){
            x[k]=data[low+k];
    }
    for(int k=0;k<yl;k++){
            y[k]=data[middle2+k];
    }
    int i=0,j=0;
    for(int k=low;k<=high;k++){
        if(j<yl&&i<xl){
            if(x[i]<=y[j]){
                data[k]=x[i];
                i++;
            }
            else if(x[i]>y[j]){
                data[k]=y[j];
                j++;
            }
        }
        else if(j==yl){
            data[k]=x[i];
            i++;
        }
        else if(i==xl){
            data[k]=y[j];
            j++;
        }


    }
    // TODO : Please complete the function
}

// Heap sort method
void SortTool::HeapSort(vector<int>& data) {
    // Build Max-Heap
    BuildMaxHeap(data);
    // 1. Swap data[0] which is max value and data[i] so that the max value will be in correct location
    // 2. Do max-heapify for data[0]
    for (int i = data.size() - 1; i >= 1; i--) {
        swap(data[0],data[i]);
        heapSize--;
        MaxHeapify(data,0);
    }
}

//Max heapify
void SortTool::MaxHeapify(vector<int>& data, int root) {
    // Function : Make tree with given root be a max-heap if both right and left sub-tree are max-heap
    int r=2*root+2,l=2*root+1,largest=root;
    if(l<=heapSize&&data[root]<data[l]){
        largest=l;
    }
    if(r<=heapSize&&data[r]>data[largest]){
        largest=r;
    }
    if(largest!=root){
        swap(data[root],data[largest]);
        MaxHeapify(data,largest);
    }

    // TODO : Please complete max-heapify code here
}

//Build max heap
void SortTool::BuildMaxHeap(vector<int>& data) {
    heapSize = data.size(); // initialize heap size
    for(int i=(heapSize/2-1);i>=0;i--){
        MaxHeapify(data,i);
    }
    // Function : Make input data become a max-heap
    // TODO : Please complete BuildMaxHeap code here
}

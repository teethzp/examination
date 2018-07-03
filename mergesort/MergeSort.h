//
// Created by teeth on 18-6-27.
//

#ifndef MYBISHI_MERGESORT_H
#define MYBISHI_MERGESORT_H

// 分治法，通过O(n)的时间把T(n)的问题变成两个T(n/2)的问题
// merge sort是典型的分治法，其时间复杂度是O(log n)
class MergeSort {
public:
    void merge(int A[],int size,int start,int end,int temp[]);
    void mergeSort(int A[], int size, int start, int end, int temp[]);
    void sortIntergers(int A[], int size);
};


#endif //MYBISHI_MERGESORT_H

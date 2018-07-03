//
// Created by teeth on 18-6-27.
//

#include "MergeSort.h"
void MergeSort::merge(int A[], int size, int start, int end, int temp[]) {
    int middle = (start + end) / 2;
    int leftIndex = start;
    int rightIndex = middle + 1;
    // 用来标记temp数组
    int index = leftIndex;
    while (leftIndex <= middle && rightIndex <= end) {
        if (A[leftIndex] < A[rightIndex]) {
            temp[index++] = A[leftIndex++];
        } else {
            temp[index++] = A[rightIndex++];
        }
    }

    while (leftIndex <= middle) {
        temp[index++] = A[leftIndex++];
    }

    while (rightIndex <= end) {
        temp[index++] = A[rightIndex++];
    }

    for (int i = 0; i <= end; i++) {
        A[i] = temp[i];
    }
}

void MergeSort::mergeSort(int A[], int size, int start, int end, int temp[]) {
    if (start >= end) {
        return;
    }

    mergeSort(A, size, start, (start + end) / 2, temp);
    mergeSort(A, size, (start + end) / 2 + 1, end, temp);
    merge(A, size, start, end, temp);
}

void MergeSort::sortIntergers(int A[], int size) {
    if (A == nullptr || size == 0) {
        return;
    }
    int temp[size];
    mergeSort(A, size, 0, size - 1, temp);
}
//
// Created by teeth on 18-7-3.
//

#include "RotatedSortedArray.h"

int SearchInRSA::TwiceBinaryDivide(int *A, int size, int target) {
    if (A == nullptr || size == 0) {
        return -1;
    }
    int start = 0;
    int end = size - 1;
    int mid;
    while (start + 1 < end) {
        mid = start + (end - start) / 2;
        if (A[mid] == target) {
            return mid;
        }
        if (A[start] < A[mid]) {
            if (A[start] <= target && target <= A[mid]) {
                end = mid;
            } else {
                start = mid;
            }
        } else {
            if (A[mid] <= target && target <= A[end]) {
                start = end;
            } else {
                end = mid;
            }
        }
    }
    if (A[start] == target) {
        return start;
    }
    if (A[end] == target) {
        return end;
    }
    return -1;
}
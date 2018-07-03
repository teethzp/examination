//
// Created by teeth on 18-6-27.
//

#ifndef MYBISHI_MERGESORTTEST_H
#define MYBISHI_MERGESORTTEST_H

#endif //MYBISHI_MERGESORTTEST_H

//
// Created by teeth on 18-6-27.
//
#include "MergeSort.h"
#include "iostream"
class MergeSortTest{
public:
    void Test();
};

void MergeSortTest::Test(){
    MergeSort so;
    int A[10] = {5, 4, 0, 8, 9, 6, 3, 1, 2, 7};
    so.sortIntergers(A, 10);
    for (int i = 0; i < 10; i++) {
        std::cout << A[i] << std::endl;
    }
}
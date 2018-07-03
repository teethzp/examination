//
// Created by teeth on 18-7-1.
//

#ifndef MYBISHI_SUBSETTEST_H
#define MYBISHI_SUBSETTEST_H

#endif //MYBISHI_SUBSETTEST_H

#include "SubsetIntergers.h"
#include <iostream>

class SubsetTest {
public:
    void Test();
};

void SubsetTest::Test() {
    int nums[]={1,3,2};
    vector<vector<int >> reslut;
    SubsetIntergers solu;
    int size = sizeof(nums) / sizeof(int);
    reslut = solu.Subset(nums, size);
    for (int i = 0; i < reslut.size(); i++) {
        for (int j = 0; j < reslut[i].size(); j++) {
            cout << reslut[i][j] << " ";
        }
        cout << "next" << endl;
    }
}
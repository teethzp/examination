//
// Created by teeth on 18-7-2.
//

#ifndef MYBISHI_FIRSTPOSITIONOFTARGETTEST_H
#define MYBISHI_FIRSTPOSITIONOFTARGETTEST_H

#endif //MYBISHI_FIRSTPOSITIONOFTARGETTEST_H

#include "FirstPositionOfTarget.h"
#include <iostream>

class FirstPositionOfTargetTest {
public:
    void Test();
};

void FirstPositionOfTargetTest::Test() {
    int nums[] = {1, 2, 3, 4, 5, 6, 7};
    int size = sizeof(nums) / sizeof(int);
    FirstPositionOfTarget so;
    int result = so.BinarySearch(nums, size, 7);
    std::cout << result << std::endl;
}
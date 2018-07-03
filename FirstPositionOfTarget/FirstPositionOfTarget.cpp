//
// Created by teeth on 18-7-1.
//

#include "FirstPositionOfTarget.h"

// 二分法简单，但是要注意细节，while中写成start+1<end（相邻时退出）判断时更简单，
int FirstPositionOfTarget::BinarySearch(int *nums, int size, int target) {
    if (nums == nullptr || size == 0) {
        return -1;
    }
    int start = 0, end = size - 1;
    // While循环里的条件：start+1<end表示中间至少空着一格时进行循环，即推出条件是相邻就退出。
    // While(start<end)，表示重合时退出。
    // start<end这样写要考虑的更多，写成start+1<end更无脑
    // 这里while循环的目的是缩小范围
    while (start + 1 < end) {
        int mid = start + (end - start) / 2;
        // 拿到mid后与target比较，有三种情况
        if (nums[mid] == target) {
            // return mid; // wrong
            // end=mid-1; // wrong 因为可能前一个不是目标
            end = mid;
        } else if (nums[mid] < target) {
            // start=mid+1; //right too
            start = mid;
        } else {
            // end=mid-1; //right too
            end = mid;
        }
    }
    if(nums[start]==target){
        return start;
    }
    if(nums[end]==target){
        return end;
    }
    return -1;
}
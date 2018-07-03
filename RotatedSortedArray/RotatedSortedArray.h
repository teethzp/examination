//
// Created by teeth on 18-7-3.
//

#ifndef MYBISHI_ROTATEDSORTEDARRAY_H
#define MYBISHI_ROTATEDSORTEDARRAY_H


// 大擂台比较：O(n)，比O(n)更快的就一定是O(log n)，O(log n)基本上就一定是二分法
// 二分法就需要去找这个xxoo的x或o，条件是什么是需要想的
// 34512 oooxx，如何去找一个条件，让345是o，12是x
class RotatedSortedArray {

};


#endif //MYBISHI_ROTATEDSORTEDARRAY_H


// 二分法中重点题
// 最简单的方法是二分两遍，先把最小的数O找到，这个数左右都是排序数组，再进行二分就知道是在左边还是右边
// 如果使用一次二分法，则手上有四个数：first、end、mid、target，根据这四个数的各种各样的关系，判断应该是去掉左边还是右边
class SearchInRSA {
public:
    int TwiceBinaryDivide(int A[], int size, int target);

};
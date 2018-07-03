//
// Created by teeth on 18-7-1.
//

#include <algorithm>
#include "SubsetIntergers.h"

// 时间复杂度下限：n*(2^n)
// 无重复数字
// DFS实现
vector<vector<int>> SubsetIntergers::Subset(int *nums, int size) {
    vector<vector<int>> result;
//    if (nums == nullptr) {
//        return result;
//    }
//    if(size==0){
//        vector<int> item;
//        result.push_back(item);
//        return result;
//    }
    sort(nums, nums + size - 1);
    vector<int> subset;
    Helper(subset, nums, size, 0, &result);
    return result;

}

// 递归三要素
// 1.递归的定义：在Nums中找到所有以subset开头的集合，并放到result中
void SubsetIntergers::Helper(vector<int> subset, int *nums, int size, int startIndex, vector<vector<int>> *results) {
    // 2.递归的拆解
    results->push_back(subset);
    for(int i=startIndex;i<size;i++){
        // [1]->[1,2]
        subset.push_back(nums[i]);
        // 寻找所有以[1,2]开头的集合，并扔到results
        Helper(subset,nums,size,i+1,results);
        // [1,2]->[1] 回溯
        subset.pop_back();
    }
    // 3.递归的出口
}

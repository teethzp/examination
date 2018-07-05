//
// Created by teethzp on 2018/7/5.
//

#ifndef MYBISHI_PERMUTATIONS_H
#define MYBISHI_PERMUTATIONS_H

#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

// 本题是给的nums没有重复数据的情况

class Permutations {
public:
    vector<vector<int>> permutationsInt(vector<int> nums);

private:
    void helper(vector<int> nums, vector<int> &permutation, unordered_set<int> &theset, vector<vector<int>> &results);
};

vector<vector<int>> Permutations::permutationsInt(vector<int> nums) {
    vector<vector<int>> result;
    if (nums.size() == 0) {
        return result;
    }
    vector<int> permutation;
    unordered_set<int> theset;
    helper(nums, permutation, theset, result);
    return result;
}

// 相比较subset，没有了startIndex，取而代之的是一个hashset，原来用一个整数就可以判断的事，现在用一个哈希表来判断
// 1.找到所有以permutation开头的排列
void Permutations::helper(vector<int> nums, vector<int> &permutation, unordered_set<int> &theset,
                          vector<vector<int>> &results) {
    // 3.递归的出口
    if (permutation.size() == nums.size()) {
        results.push_back(permutation);
        return;
    }

    // [3]=>[3,1],[3,2]...
    for (int i = 0; i < nums.size(); i++) {
        if (theset.find(nums[i]) != theset.end()) {
            continue;
        }
        permutation.push_back(nums[i]);
        theset.insert(nums[i]);
        helper(nums, permutation, theset, results);
        theset.erase(theset.find(nums[i]));
        permutation.pop_back();
    }

}

class PermutationsTest {
public:
    void Test();
};

void PermutationsTest::Test() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result;
    Permutations so;
    result = so.permutationsInt(nums);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}

#endif //MYBISHI_PERMUTATIONS_H

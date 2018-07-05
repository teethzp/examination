//
// Created by teethzp on 2018/7/5.
//

#ifndef MYBISHI_PERMUTATIONS2_H
#define MYBISHI_PERMUTATIONS2_H

#include <iostream>
#include <vector>

using namespace std;

// 输入数据有重复的情况
class Permutations2 {
public:
    vector<vector<int>> permuteation(vector<int> nums);

    void helper(vector<vector<int>> &result, vector<int> &list, vector<bool> &visited, vector<int> num);
};

vector<vector<int>> Permutations2::permuteation(vector<int> nums) {
    vector<vector<int>> result;
    if (nums.size() == 0) {
        return result;
    }
    vector<int> list;
    // 判断相对应的数是不是被取出来了
    vector<bool> visited;
    sort(nums.begin(), nums.end());
    helper(result, list, visited, nums);
    return result;
}

void Permutations2::helper(vector<vector<int>> &result, vector<int> &list, vector<bool> &visited, vector<int> num) {
    if (list.size() == num.size()) {
        result.push_back(list);
        return;
    }

    for (int i = 0; i < num.size(); i++) {
        if (visited[i] == 1) {
            continue;
        }
        // 如果我前面有个数，且我和我前面那个数是一样的，且前面那个数没用过，说明我跳过了一个2去取了下一个2
        // 这种情况要避免，所以continue，这样就没有重复了
        if (i != 0;num[i] == num[i - 1] && visited[i - 1] && visited[i - 1] == 0) {
            continue;
        }
        // [1,2]=>[1,2,3]
        list.push_back(num[i]);
        visited[i] = true;
        // 只是寻找list开头的所有的，而不是要把list改掉
        helper(result, list, visited, num);
        // 回溯 backtracking
        visited[i] = false;
        list.pop_back();
    }
}


#endif //MYBISHI_PERMUTATIONS2_H

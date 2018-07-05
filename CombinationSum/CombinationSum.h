//
// Created by teethzp on 2018/7/5.
//

#ifndef MYBISHI_COMBINATIONSUM_H
#define MYBISHI_COMBINATIONSUM_H

#include <vector>
#include <iostream>

using namespace std;

class CombinationSum {
public:
    vector<vector<int>> combinationsum(vector<int> candidate, int target);

private:
    // candidate:候选集合
    // startIndex:从哪开始找
    // combination:已经选好的组合
    // remainSum：离目标还差多少
    // result：结果
    void
    helper(vector<int> candidate, int startIndex, vector<int> &combination, int remainSum, vector<vector<int>> &result);
};


vector<vector<int>> CombinationSum::combinationsum(vector<int> candidate, int target) {
    // 与subset这道题不同的地方
    // 1.duplicate输入元素可重复，解决：dedup，去重；或者sort，然后重复的做下标记
    // 2.一个是求所有的子集，一个只需要一部分，sum=target=>curtSum==target   /target-curSum=0
    // 3.本题可重复取元素，subset是如何避免重复取元素的呢？递归时，startIndex是当前的下一个，所以本题startIndex就选择当前即可

    vector<vector<int>> result;
    if (candidate.size() == 0) {
        return result;
    }
    sort(candidate.begin(), candidate.end());
    vector<int> combination;
    helper(candidate, 0, combination, target, result);
    return result;
}

// 1.递归的定义
// 找到所有以combination开头的和为target的组合，丢到results里
void CombinationSum::helper(vector<int> candidate, int startIndex, vector<int> &combination, int remainSum,
                            vector<vector<int>> &result) {
    // 3.递归的出口
    if (remainSum == 0) {
        result.push_back(combination);
        return;
    }

    // 2.递归的拆解
    for (int i = startIndex; i < candidate.size(); i++) {
        // 见前面与subset不同点分析的第一点
        // 去重：当前数与上一个数一样，就跳过（当前数不是第一个数）
        if (i != 0 && candidate[i] == candidate[i - 1]) {
            continue;
        }
        // 如果要找的树已经比剩余的值大了，直接break
        if (candidate[i] > remainSum) {
            break;
        }
        // []=>[1]
        combination.push_back(candidate[i]);
        // 找到所有[1]开头的之后
        helper(candidate, i, combination, remainSum - candidate[i], result);
        // 回溯：去掉1，给2机会
        combination.pop_back();
    }

}

class CombinationSumTest {
public:
    void Test();
};

void CombinationSumTest::Test() {
    vector<int> data = {9, 8, 7, 6, 5, 4, 4, 4, 3};
    int target = 20;
    CombinationSum comsum;
    vector<vector<int>> results;
    results = comsum.combinationsum(data, target);
    for (int i = 0; i < results.size(); i++) {
        for (int j = 0; j < results[i].size(); j++) {
            cout << results[i][j] << " ";
        }
        cout << endl;
    }

}

#endif //MYBISHI_COMBINATIONSUM_H

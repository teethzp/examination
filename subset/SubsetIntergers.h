//
// Created by teeth on 18-7-1.
//

#ifndef MYBISHI_SUBSETINTERGERS_H
#define MYBISHI_SUBSETINTERGERS_H

#include <vector>

using namespace std;

// 本题nums中没有重复数据

class SubsetIntergers {
public:
    vector<vector<int>> Subset(int nums[], int size);

private:
    void Helper(vector<int> subset, int nums[], int size, int startIndex, vector<vector<int>> *results);
};


#endif //MYBISHI_SUBSETINTERGERS_H

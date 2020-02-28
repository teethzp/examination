#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 去掉数组中重复的元素，但是不保证元素原来的顺序
int deduplication(vector<int>& nums){
    int index1 = 0;
    int index2 = 1;

    if(nums.size() == 0){
        return 0;
    }else if(nums.size() == 1){
         return 1;
    }

    sort(nums.begin(), nums.end());

    for(; index2<nums.size();){
        if(nums[index1] == nums[index2]){
            index2++;
        }else{
            index1++;
            nums[index1] = nums[index2]; 
            index2++;
        }
    }

    for(int i = index1 - 1; i < nums.size(); i++){
        nums.pop_back();
    }

    return index1 + 1;
}

int main(int argc, char** argv){
    int num;

    vector<int> data = {3, 2, 3, 2, 2, 1, 9, 5, 5};
    num = deduplication(data);

    cout << "num:" << num <<endl;

    for(auto iter = data.begin(); iter != data.end(); iter++){
        cout << *iter << endl;
    }

    return 0;
}
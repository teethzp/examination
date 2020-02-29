#include <vector>
#include <iostream>

using namespace std;

vector<int> winsum(vector<int> data, int k){
    vector<int> result;
    int index1 = 0;
    int index2 = k -1;
    int sum = 0;

    if(data.size() < k || k < 1){
        return result;
    }

    for(; index2 < data.size(); index2++){
        for(int i = 0; i < k; i++){
            sum = sum + data[index1 + i];
        }
        result.push_back(sum);
        sum = 0;
        index1++;
    }

    return result;
}

int main(int argc, char **argv){
    vector<int> data = {1, 2, 7, 8, 5};
    vector<int> result;
    result = winsum(data, 3);

    for(auto iter = result.begin(); iter != result.end(); iter++){
        cout << *iter << endl;
    }

    return 0;
}
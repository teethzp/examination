//
// Created by teeth on 18-7-3.
//

#ifndef MYBISHI_BREADTHFIRST_H
#define MYBISHI_BREADTHFIRST_H


#include <vector>
#include <utility>
#include <unordered_set>
#include <queue>
#include <unordered_map>

using namespace std;

// Definition of undirected graph
struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;

    // 构造函数
    UndirectedGraphNode(int x) : label(x) {};
};


// 图上的BFS和树上的BFS区别：图中存在环，意味着同一个节点可能重复进入队列
// 判断一个节点也没要重复进入队列，需要什么数据结构？HashMap（HashSet）

class BreadthFirst {
    // 给出n个节点，标号分别从0到n-1并且给出一个无向边的列表（给出每条边的两个顶点），写一个函数来判断
    // 这个“无向”图是否是一棵树
    // pair需要#include <utility>
    bool ValidTree(int n, vector<pair<int, int>> &edges);

    // 克隆无向图
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node);
};


#endif //MYBISHI_BREADTHFIRST_H

//
// Created by teeth on 18-7-3.
//

#ifndef MYBISHI_TOPOLOGICALSORTING_H
#define MYBISHI_TOPOLOGICALSORTING_H

// 拓扑排序是个有向图，这里拓扑排序使用BFS
// 将入度为0的点丢到待学习队列中，然后1的入度减1变成0,2的入度-1变成1,再把入度为0的点丢到学习队列中
// 这个过程我们需要一个队列，待学习的点就放到这个队列中

#include <vector>
#include <map>
#include <queue>
#include <iostream>

using namespace std;

// 有向图的节点
struct DirectedGraphNode {
    int label;
    vector<DirectedGraphNode *> neighbors;

    // 构造函数
    DirectedGraphNode(int x) : label(x) {};
};


class TopologicalSorting {
public:
    vector<DirectedGraphNode *> topsort(vector<DirectedGraphNode *> graph);
};


// PS.不能被拓扑排序的情况：循环依赖
// 可以看看得到结果的size和条件的size是否一样，不一样说明有点没抠出来，出现了循环依赖

vector<DirectedGraphNode *> TopologicalSorting::topsort(vector<DirectedGraphNode *> graph) {
    // 排好序的结果
    vector<DirectedGraphNode *> result;
    // map存放的是节点的度（但是没有存放度为0的节点）
    map<DirectedGraphNode *, int> countrd;
    // 统计入度：一旦发现一个node指向邻居，则把邻居的度加1
    for (int i = 0; i < graph.size(); i++) {
        for (int j = 0; j < graph[i]->neighbors.size(); j++) {
            if (countrd.find(graph[i]->neighbors[j]) == countrd.end()) {
                countrd[graph[i]->neighbors[j]] = 1;
            } else {
                countrd[graph[i]->neighbors[j]] += 1;
            }
        }
    }

    // 存放带学习课程的队列
    queue<DirectedGraphNode *> qu;

    // 将没有先修课程的节点（即不在countrd中的节点）加入到待学习队列
    // 同时将该节点加入到返回结果中
    for (int i = 0; i < graph.size(); i++) {
        if (countrd.find(graph[i]) == countrd.end()) {
            qu.push(graph[i]);
            result.push_back(graph[i]);
        }
    }

    // 将从学习队列取出的节点的邻居的度减一，然后看看这个邻居的的度是否变成0了
    //如果是，则将其加入到学习队列中
    while (!qu.empty()) {
        DirectedGraphNode *nodeptr = qu.front();
        qu.pop();
        for (int i = 0; i < nodeptr->neighbors.size(); i++) {
            countrd[nodeptr->neighbors[i]] -= 1;
            if (countrd[nodeptr->neighbors[i]] == 0) {
                result.push_back(nodeptr->neighbors[i]);
                qu.push(nodeptr->neighbors[i]);
            }
        }
    }
    return result;
}

class TopologicalSortingTest {
public:
    void Test();
};

void TopologicalSortingTest::Test() {
    DirectedGraphNode root(0);
    DirectedGraphNode first(1);
    DirectedGraphNode second(2);
    DirectedGraphNode third(3);
    DirectedGraphNode four(4);
    DirectedGraphNode five(5);
    root.neighbors.push_back(&first);
    root.neighbors.push_back(&second);
    root.neighbors.push_back(&third);
    first.neighbors.push_back(&four);
    second.neighbors.push_back(&four);
    second.neighbors.push_back(&five);
    third.neighbors.push_back(&four);
    third.neighbors.push_back(&five);
    vector<DirectedGraphNode *> graph;
    graph.push_back(&root);
    graph.push_back(&first);
    graph.push_back(&second);
    graph.push_back(&third);
    graph.push_back(&four);
    graph.push_back(&five);

    TopologicalSorting so;
    vector<DirectedGraphNode *> result;
    result = so.topsort(graph);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i]->label << endl;
    }
}
#endif //MYBISHI_TOPOLOGICALSORTING_H

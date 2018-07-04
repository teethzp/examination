//
// Created by teeth on 18-7-3.
//

#include "BreadthFirst.h"

bool BreadthFirst::ValidTree(int n, vector<pair<int, int>> &edges) {
    // 表示这个图
    vector<unordered_set<int>> g(n, unordered_set<int>());
    //
    unordered_set<int> v;
    //
    queue<int> q;
    q.push(0);
    v.insert(0);
    // 初始化这个图：临接表的形式
    for (auto a:edges) {
        g[a.first].insert(a.second);
        g[a.second].insert(a.first);
    }
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        for (auto a:g[t]) {
            if (v.find(a) != v.end()) {
                return false;
            }
            v.insert(a);
            q.push(a);
            g[a].erase(t);
        }
    }
    return v.size() == n;
}


UndirectedGraphNode *BreadthFirst::cloneGraph(UndirectedGraphNode *node) {
    if (!node) {
        return nullptr;
    }

    UndirectedGraphNode *p1 = node;
    UndirectedGraphNode *p2 = new UndirectedGraphNode(node->label);
    unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> map;
    queue<UndirectedGraphNode *> q;
    q.push(node);
    map[node] = p2;

    while (!q.empty()) {
        p1 = q.front();
        p2 = map[p1];
        q.pop();
        for (int i = 0; i < p1->neighbors.size(); i++) {
            UndirectedGraphNode *nb = p1->neighbors[i];
            if (map.count(nb)) {
                p2->neighbors.push_back(map[nb]);
            } else {
                UndirectedGraphNode *temp = new UndirectedGraphNode(nb->label);
                p2->neighbors.push_back(temp);
                map[nb] = temp;
                q.push(nb);
            }
        }
    }
    return map[node];
}
















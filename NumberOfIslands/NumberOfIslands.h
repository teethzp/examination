//
// Created by teeth on 18-7-4.
//

#ifndef MYBISHI_NUMBEROFISLANDS_H
#define MYBISHI_NUMBEROFISLANDS_H

#include <vector>
#include <iostream>
#include <queue>

using namespace std;

// 可以用pair取代
struct Coordinate {
public:
    int x;
    int y;

    Coordinate(int x, int y) : x(x), y(y) {};
};

class NumberOfIslands {
public:
    int NumIslands(vector<vector<bool>> grid);

private:
    // 注意grid要传引用或指针
    void MarkByBFS(vector<vector<bool>> &grid, int x, int y);

    bool InBound(Coordinate coor, vector<vector<bool>> &grid);
};

// 判断点是否越界
bool NumberOfIslands::InBound(Coordinate coor, vector<vector<bool>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    return coor.x >= 0 && coor.x < n && coor.y >= 0 && coor.y < m;
}

void NumberOfIslands::MarkByBFS(vector<vector<bool>> &grid, int x, int y) {
    int directionX[] = {0, 1, -1, 0};
    int directionY[] = {1, 0, 0, -1};
    queue<Coordinate> qu;
    qu.push(Coordinate(x, y));
    grid[x][y] = false;
    while (!qu.empty()) {
        // 取出队列中的一个点
        Coordinate coor = qu.front();
        qu.pop();
        // 查看四个方向的点
        for (int i = 0; i < 4; i++) {
            Coordinate adj(coor.x + directionX[i], coor.y + directionY[i]);
            // 判断点有没有越界，越界了就跳出for循环
            if (!InBound(adj, grid)) {
                continue;
            }
            // 判断这个点能不能灌水，能灌水就灌水，并将其加入到队列中
            if (grid[adj.x][adj.y]) {
                grid[adj.x][adj.y] = false;
                qu.push(adj);
            }

        }
    }
}

int NumberOfIslands::NumIslands(vector<vector<bool>> grid) {
    // 可以直接用vector<vector<bool>> grid用来判断能否灌水了
    if (grid.size() == 0 || grid[0].size() == 0) {
        return 0;
    }
    // 行
    int n = grid.size();
    // 列
    int m = grid[0].size();
    int islands = 0;
    // 一个格子一个格子的做宽度优先搜索(可以灌水的格子才做)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j]) {
                MarkByBFS(grid, i, j);
                islands++;
            }
        }

    }
    return islands;
}

class NumberOfIslandsTest {
public:
    void Test();
};

void NumberOfIslandsTest::Test() {
    vector<vector<bool>> grid = {{1, 1, 0, 0, 0},
                                 {0, 1, 0, 0, 1},
                                 {0, 0, 0, 1, 1},
                                 {0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 1}};
    NumberOfIslands so;
    int count = so.NumIslands(grid);
    cout << "number of islands:" << count << endl;
}



#endif //MYBISHI_NUMBEROFISLANDS_H

//
// Created by teeth on 18-7-4.
//

#ifndef MYBISHI_ZOMBIEMATRIX_H
#define MYBISHI_ZOMBIEMATRIX_H


#include <vector>
#include <iostream>
#include <queue>

using namespace std;

// 最完整的宽度优先搜索是三层，最外层是While队列不空，第二层是for当前层的所有节点
// 第三层是从队列中拿出来的节点的所有邻居节点。
// 网格问题要注意下越界判断

class Coordinate2 {
public:
    int x;
    int y;

    Coordinate2(int x, int y) : x(x), y(y) {};
};

class ZombieMatrix {
public:
    int PEOPLE = 0;
    int ZOMBIE = 1;
    int WALL = 2;
    int deltaX[] = {1, 0, 0, -1};
    int deltaY[] = {0, 1, -1, 0};

    int Zombie(vector<vector<int>> grid);

private:
    bool IsPeople(Coordinate2 coor, vector<vector<int>> grid);
};

int ZombieMatrix::IsPeople(Coordinate2 coor, vector<vector<int>> grid) {
    int n = grid.size();
    int m = grid[0].size();
    if (coor.x < 0 || coor.x >= n) {
        return false;
    }
    if (coor.y < 0 || coor.y >= m) {
        return false;
    }
    return (grid[coor.x][coor.y] == PEOPLE);
}

int ZombieMatrix::Zombie(vector<vector<int>> grid) {
    if (grid.size() == 0 || grid[0].size() == 0) {
        return 0;
    }

    int n = grid.size();
    int m = grid[0].size();

    // 从僵尸来做宽度优先搜索
    // initialize the queue and count people
    int people = 0;
    queue<Coordinate2> qu;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == PEOPLE) {
                people++;
            } else if (grid[i][j] == ZOMBIE) {
                qu.push(Coordinate2(i, j));
            }
        }
    }

    if (people == 0) {
        return 0;
    }

    // bfs
    int days = 0;
    while (!qu.empty()) {
        days++;
        int size = qu.size();
        // 因为需要记录过来几天（即层级遍历中的几层）
        // 所以需要bfs三重循环中的中间那层层级遍历
        for (int i = 0; i < size; i++) {
            Coordinate2 zb = qu.front();
            qu.pop();
            for (int direction = 0; direction < 4; direction++) {
                Coordinate2 adj(zb.x + deltaX[direction], zb.y + deltaY[direction]);
                if (!IsPeople(adj, grid)) {
                    continue;
                }
                grid[adj.x][adj.y]=ZOMBIE;
                people--;
                if(people==0){
                    return days;
                }
                qu.push(adj);
            }
        }
    }
    // 无法全部感染
    return -1;

}

#endif //MYBISHI_ZOMBIEMATRIX_H

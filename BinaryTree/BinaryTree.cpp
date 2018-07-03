//
// Created by teeth on 18-7-3.
//

#include <iostream>
#include "BinaryTree.h"

void BinaryTree::InitializeTree() {
    theRoot.val = 1;
    two.val = 2;
    three.val = 3;
    four.val = 4;
    five.val = 5;
    theRoot.left = &two;
    theRoot.right = &three;
    two.left = &four;
    two.right = &five;
}

void BinaryTree::PreorderTraverse(TreeNode *root) {
    if (root == nullptr) {
        return;
    }
    preorder.push_back(root->val);
    PreorderTraverse(root->left);
    PreorderTraverse(root->right);
}

void BinaryTree::InorderTraverse(TreeNode *root) {
    if (root == nullptr) {
        return;
    }
    InorderTraverse(root->left);
    inorder.push_back(root->val);
    InorderTraverse(root->right);
}

void BinaryTree::PostorderTraverse(TreeNode *root) {
    if (root == nullptr) {
        return;
    }
    PostorderTraverse(root->left);
    PostorderTraverse(root->right);
    postorder.push_back(root->val);
}

int BinaryTree::MaxDepthByTraverse(TreeNode *root) {
    depth = 0;
    MaxDepthHelper(root, 1);
    return depth;
}

void BinaryTree::MaxDepthHelper(TreeNode *node, int curtDepth) {
    if (node == nullptr) {
        return;
    }
    if (curtDepth > depth) {
        depth = curtDepth;
    }
    MaxDepthHelper(node->left, curtDepth + 1);
    MaxDepthHelper(node->right, curtDepth + 1);
}

int BinaryTree::MaxDepthByDivideConquer(TreeNode *node) {
    if (node == nullptr) {
        return 0;
    }
    int left = MaxDepthByDivideConquer(node->left);
    int right = MaxDepthByDivideConquer(node->right);
    if (left >= right) {
        return left + 1;
    } else {
        return right + 1;
    }

}

vector<string> BinaryTree::AllPaths(TreeNode *root) {
    vector<string> paths;
    // 递归的出口
    if (root == nullptr) {
        return paths;
    }

    vector<string> leftPath = AllPaths(root->left);
    vector<string> rightPath = AllPaths(root->right);
    for (int i = 0; i < leftPath.size(); i++) {
        std::cout << "bb " << leftPath[i] << endl;
        paths.push_back(to_string(root->val) + "->" + leftPath[i]);
    }
    for (int i = 0; i < rightPath.size(); i++) {
        std::cout << "bb " << rightPath[i] << endl;
        paths.push_back(to_string(root->val) + "->" + rightPath[i]);

    }
    if (paths.size() == 0) {
        paths.push_back(to_string(root->val) + "");
    }
    return paths;
}


// BFS Key Points
// 1.使用队列作为主要结构.深度优先搜索非递归才用stack
// 2.是否需要分层，需要分层的算法比不需要分层的算法多一个循环
// 3.注意是size=queue.size() 不能直接for(int i=0;i<queue.size();i++)，因为for循环中会向queue中push下一层的节点
// 4.宽度优先搜索的时间复杂度：O(E)，E指所有的边，二叉树的点和边数目可以认为是一样（n个点，n-1条边）
vector<vector<int>> BinaryTree::LevelOrder(TreeNode *root) {
    vector<vector<int>> results;
    if (root == nullptr) {
        return results;
    }
    // 1.创建一个队列，把起始节点都放到里面去（第一层节点）
    queue<TreeNode *> qu;
    qu.push(root);

    // 2.while队列不空，处理队列中的节点，并扩展出新的节点
    while (!qu.empty()) {
        // for上一层的节点扩展下一层的节点
        vector<int> level;
        int size = qu.size();
        for (int i = 0; i < size; i++) {
            TreeNode *node = qu.front();
            // 需要把当前层的节点从队列中删除
            qu.pop();
            level.push_back(node->val);
            if (node->left != nullptr) {
                // 因为这里循环次数是根据之前的qu的size决定的，所以这里即使push了，并不影响for循环次数
                qu.push(node->left);
            }
            if (node->right != nullptr) {
                qu.push(node->right);
            }
        }
        results.push_back(level);
    }
    return results;
}













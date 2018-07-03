//
// Created by teeth on 18-7-3.
//

#ifndef MYBISHI_BINARYTREE_H
#define MYBISHI_BINARYTREE_H

#include<vector>
#include <string>
#include <queue>

using namespace std;


// 90%的二叉树问题都可以用分治法来解决（merger sort和quick sort这两种经典的分治法一定要熟练）
// 遇到二叉树的问题，就想想整棵树在该问题上的结果和左右儿子在该问题上的结果之间的联系是什么


// 二叉树遍历
// Preorder前序遍历：根、左、右
// Inorder中序遍历：左、根、右
// Postorder后序遍历：左、右、根

class TreeNode {
public:
    TreeNode() : val(0), left(nullptr), right(nullptr) {};

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    int val;
    TreeNode *left;
    TreeNode *right;


};

class BinaryTree {
public:
    vector<int> preorder;
    vector<int> inorder;
    vector<int> postorder;

    TreeNode theRoot;
    TreeNode two;
    TreeNode three;
    TreeNode four;
    TreeNode five;

    // 初始化一个二叉树
    void InitializeTree();

    // 遍历实现的前序遍历（一个人一个本子）
    void PreorderTraverse(TreeNode *root);

    // 遍历实现的中序遍历
    void InorderTraverse(TreeNode *root);

    // 遍历实现的后序遍历
    void PostorderTraverse(TreeNode *root);

    // 遍历实现求二叉树的最大深度Maximum Depth of Binary Tree
    int MaxDepthByTraverse(TreeNode *root);

    // helper的两个参数：这唯一的小人走到哪了，走到的这个地方的深度是多少
    void MaxDepthHelper(TreeNode *node, int curtDepth);

    // 递归实现求二叉树的最大深度
    // 利用整棵二叉树的最大深度和左右子树最大深度的关系：整棵二叉树的最大深度=左右子树最大深度+1
    int MaxDepthByDivideConquer(TreeNode *node);

    // 分治法求二叉树根节点到所有叶子节点的路径
    vector<string> AllPaths(TreeNode *root);

    // 二叉树上的宽度优先搜索：图（二叉树是特殊的图）的层级遍历
    vector<vector<int>> LevelOrder(TreeNode* root);

private:
    // 遍历求二叉树最大深度时需要的
    int depth;
};

// 二叉查找树
// 二叉查找树的基本性质：
// 定义上：1.左子树都比根节点小;2.右子树都不小于根节点。
// 效果上：1.中序遍历是不下降序列
// 注意：如果一棵树的中序遍历是不下降序列，不一定是BST，如所有节点都相等的情况

#endif //MYBISHI_BINARYTREE_H

#include <iostream>
#include "mergesort/MergeSortTest.h"
#include "subset/SubsetTest.h"
#include "FirstPositionOfTarget/FirstPositionOfTargetTest.h"
#include "RotatedSortedArray/RotatedSortedArray.h"
#include "BinaryTree/BinaryTree.h"

using namespace std;


int main() {
//    // 测试MergeSort
//    MergeSortTest test;
//    test.Test();

//    // 测试Subset
//    SubsetTest test;
//    test.Test();
//    return 0;

//      // 测试FirstPositionOfTarget
//    FirstPositionOfTargetTest test;
//    test.Test();

//    // 测试在不重复的RSA数组中查找
//    SearchInRSA so;
//    int A[] = {4, 5, 6, 7, 1, 2, 3};
//    int r = so.TwiceBinaryDivide(A, 7, 3);
//    cout << r << endl;

//    //测试二叉树前序遍历
//    BinaryTree b;
//    b.InitializeTree();
//    b.PreorderTraverse(&(b.theRoot));
//    for (int i = 0; i < b.preorder.size(); i++) {
//        cout << b.preorder[i] << endl;
//    }

//    //测试二叉树中序遍历
//    BinaryTree b;
//    b.InitializeTree();
//    b.InorderTraverse(&(b.theRoot));
//    for (int i = 0; i < b.inorder.size(); i++) {
//        cout << b.inorder[i] << endl;
//    }

//    //测试二叉树后序遍历
//    BinaryTree b;
//    b.InitializeTree();
//    b.PostorderTraverse(&(b.theRoot));
//    for (int i = 0; i < b.postorder.size(); i++) {
//        cout << b.postorder[i] << endl;
//    }

//    // 测试遍历实现的二叉树最大深度
//    BinaryTree b;
//    b.InitializeTree();
//    int d = b.MaxDepthByTraverse(&(b.theRoot));
//    cout << d << endl;

//    // 测试递归实现的二叉树最大深度
//    BinaryTree b;
//    b.InitializeTree();
//    int d = b.MaxDepthByDivideConquer(&(b.theRoot));
//    cout << d << endl;

    // 测试递归实现的查找二叉树所有路径
    BinaryTree b;
    b.InitializeTree();
    vector<string> paths;
    paths = b.AllPaths(&(b.theRoot));
    for (int i = 0; i < paths.size(); i++) {
        cout << paths[i] << endl;
    }

    // 测试二叉树层级遍历

}
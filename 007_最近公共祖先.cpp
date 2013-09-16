/*
 作者: Annie Kim, anniekim.pku[at]gmail.com
 时间: Sep 12, 2013
 题目: 最近公共祖先
 难度: Easy
 链接: http://www.itint5.com/oj/#7
 问题: 有一颗树，给定树中任意两个结点，计算出这两个结点的最近公共祖先。

 Solution: 先求出两个节点在树中所处的高度。最坏情况下时间复杂度O(n)。
*/

/*
// 节点定义
struct TreeNode {
    TreeNode *parent;
};
*/

// 返回node节点在树中所处的高度
int getHeight(TreeNode *node) {
    int height = 0;
    while (node) {
        height++;
        node = node->parent;
    }
    return height;
}

// 返回节点node1和node2的最近公共祖先
TreeNode *getLCA(TreeNode *node1, TreeNode *node2) {
    int height1 = getHeight(node1), height2 = getHeight(node2);
    if (height1 < height2) {
        swap(height1, height2);
        swap(node1, node2);
    }
    int diff = height1 - height2;
    while (diff--)
        node1 = node1->parent;
    while (node1 != node2) {
        node1 = node1->parent;
        node2 = node2->parent;
    }
    return node1;
}
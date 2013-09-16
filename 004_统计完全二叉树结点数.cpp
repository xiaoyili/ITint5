/*
 作者: Annie Kim, anniekim.pku[at]gmail.com
 时间: Sep 13, 2013
 题目: 统计完全二叉树结点数
 难度: Medium
 链接: http://www.itint5.com/oj/#4
 问题: 
 给定一棵完全二叉树的根结点，统计该树的结点总数。
 树结点类型名为TreeNode，您没必要知道该类型的定义，请使用下面的方法得到某个结点的左，右儿子结点，以及判断某结点是否为NULL。
 //获得结点node的左儿子结点
 TreeNode getLeftChildNode(TreeNode node);
 //获得结点node的右儿子结点
 TreeNode getRightChildNode(TreeNode node);
 //判断结点node是否为NULL
 int isNullNode(TreeNode node);

 Solution: 这里要充分利用完全二叉树的性质。
           根据左右子树的高度，可以判断出最后一层最右叶节点的位置，就可以进行二分。
           复杂度O(lgn^2)。
*/

// 树的高度，沿着左孩子
int getHeight(TreeNode node)
{
    int height = 0;
    while (!isNullNode(node)) {
        height++;
        node = getLeftChildNode(node);
    }
    return height;
}

// 高度为height的满二叉树节点个数
int count_perfect_binary_tree_nodes(int height)
{
    return (int)pow(2, height) - 1;
}

int count_complete_binary_tree_nodes(TreeNode root)
{
    int count = 0;
    while (!isNullNode(root))
    {
        int left = getHeight(getLeftChildNode(root));
        int right = getHeight(getRightChildNode(root));
        if (left == right)
        {
            count += count_perfect_binary_tree_nodes(left) + 1;
            root = getRightChildNode(root);
        }
        else
        {
            count += count_perfect_binary_tree_nodes(right) + 1;
            root = getLeftChildNode(root);
        }
    }
    return count;
}
/*
 作者: Annie Kim, anniekim.pku[at]gmail.com
 时间: Sep 21, 2013
 题目: 二叉树转换线索二叉树
 难度: Easy
 链接: http://www.itint5.com/oj/#27
 问题: 将一棵普通二叉树转换为一棵线索二叉树。
 说明：树结点除了包含left, right指针外，还包含isLeftThread和isRightThread，
       初始时isLeftThread和isRightThread都为false。对于left为null的结点，请将left设置为
       中序遍历该结点的前驱结点，并将isLeftThread设置为true。对于right为null的结点，
       请将right设置为中序遍历该结点的后继结点，并将isRightThread设置为true。
 提示：请尝试使用非递归算法。

 Solution: 递归算法写起来更简单，有点类似于“判断是否为二叉搜索树”。
           而非递归算法的写法类似于“Morris Traversal”，不知道有没有更简单的写法。
*/

/*树结点的定义(请不要在代码中定义该结构)
struct TreeNode {
  TreeNode *left, *right;
  bool isLeftThread, isRightThread;
}*/

/*-------------------------------------------------------------------------------------------
 方案一：递归。
*/
void convertToThreadedTree(TreeNode *node, TreeNode *pre, TreeNode *post) {
    if (!node) return;
    convertToThreadedTree(node->left, pre, node);
    convertToThreadedTree(node->right, node, post);
    if (!node->left) {
        node->left = pre;
        node->isLeftThread = true;
    }
    if (!node->right) {
        node->right = post;
        node->isRightThread = true;
    }
}

void convertToThreadedTree(TreeNode *root) {
    convertToThreadedTree(root, NULL, NULL);
}

/*-------------------------------------------------------------------------------------------
 方案二：非递归。
*/
void convertToThreadedTree(TreeNode *root) {
    TreeNode *cur = root;
    bool visited = false;
    while (cur)
    {
        if (!visited && cur->left && !cur->isLeftThread)
        {
            TreeNode *pre = cur->left;
            while (pre->right && !pre->isRightThread)
                pre = pre->right;
            pre->right = cur;
            pre->isRightThread = true;
        }
        if (!visited && cur->right && !cur->isRightThread)
        {
            TreeNode *post = cur->right;
            while (post->left && !post->isLeftThread)
                post = post->left;
            post->left = cur;
            post->isLeftThread = true;
        }
        if (!visited && cur->left && !cur->isLeftThread) {
            visited = false;
            cur = cur->left;
        } else {
            visited = cur->isRightThread;
            cur = cur->right;
        }
    }
}
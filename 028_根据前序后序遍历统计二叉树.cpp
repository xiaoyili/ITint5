/*
 作者: Annie Kim, anniekim.pku[at]gmail.com
 时间: Sep 21, 2013
 题目: 根据前序后序遍历统计二叉树
 难度: Easy
 链接: http://www.itint5.com/oj/#28
 问题: 
 对于包含n个结点的二叉树（树中结点编号从1到n），已知前序和后序遍历序列，
 我们知道不一定能唯一的恢复这棵树。请计算出满足条件的二叉树的总数。
 样例：
 前序遍历序列preorder：1 2
 后序遍历序列postorder：2 1
 一共有2棵满足条件的二叉树：
    1       1
   /         \
  2           2

 Solution: 递归和动态规划都可以完成。这题效率上来讲还是top-down的递归快一些。
*/

/*-------------------------------------------------------------------------------------------
 方案一：递归。
*/
int countValidTreesRe(vector<int>& preorder, int i, vector<int>& postorder, int j, int N) {
    if (N == 0) return 1;
    if (preorder[i] != postorder[j+N-1]) return -1;
    int count = 0;
    for (int k = 0; k < N; ++k)
    {
        int left = countValidTreesRe(preorder, i+1, postorder, j, k);
        if (left == -1) continue;
        int right = countValidTreesRe(preorder, i+1+k, postorder, j+k, N-1-k);
        if (right == -1) continue;
        count += left * right;
    }
    return count;
}

int countValidTrees(vector<int>& preorder, vector<int>& postorder) {
    if (preorder.size() != postorder.size()) return false;
    int N = preorder.size();
    return countValidTreesRe(preorder, 0, postorder, 0, N);
}

/*-------------------------------------------------------------------------------------------
 方案二：dp。
*/
int countValidTrees(vector<int>& preorder, vector<int>& postorder) {
    if (preorder.size() != postorder.size()) return false;
    int N = preorder.size();
    int dp[N+1][N+1][N+1];
    for (int k = 0; k <= N; ++k)
        for (int i = 0; i <= N-k; ++i)
            for (int j = 0; j <= N-k; ++j)
            {
                dp[k][i][j] = 1;
                if (k == 0) continue;
                if (preorder[i] != postorder[j+k-1]) {
                    dp[k][i][j] = -1;
                    continue;
                }
                dp[k][i][j] = 0;
                for (int l = 0; l < k; ++l)
                    if (dp[l][i+1][j] != -1 && dp[k-1-l][i+1+l][j+l] != -1)
                        dp[k][i][j] += dp[l][i+1][j] * dp[k-1-l][i+1+l][j+l];
            }
    return dp[N][0][0];
}
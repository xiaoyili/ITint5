/*
 作者: Annie Kim, anniekim.pku[at]gmail.com
 时间: Sep 21, 2013
 题目: 最大子矩阵和
 难度: Medium
 链接: http://www.itint5.com/oj/#39
 问题: 有一个n*m的二维整型数组矩阵matrix，计算它的最大子矩阵和（允许子矩阵为空）。
 提示：时间复杂度O(n^3)，可以先尝试完成最大连续子段和问题。
 题目来源：GeeksforGeeks
 
 Solution: 把多个行合并起来就回到了最大连续子断问题。
*/

int maxConsSum(const vector<int> &num) {
    int dp = 0, res = 0, N = num.size();
    for (int i = 0; i < N; ++i) {
        dp = max(num[i], dp + num[i]);
        res = max(dp, res);
    }
    return res;
}

int maxRectSum(vector<vector<int> > &matrix) {
    if (matrix.empty()) return 0;
    int N = matrix.size(), M = matrix[0].size();
    int res = 0;
    for (int i = 0; i < N; ++i) {
        vector<int> num(M, 0);
        for (int h = 1; h <= N-i; ++h) {
            for (int j = 0; j < M; ++j)
                num[j] += matrix[i+h-1][j];
            res = max(res, maxConsSum(num));
        }
    }
    return res;
}
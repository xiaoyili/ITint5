/*
 作者: Annie Kim, anniekim.pku[at]gmail.com
 时间: Sep 21, 2013
 题目: 有序矩阵搜索
 难度: Easy
 链接: http://www.itint5.com/oj/#38
 问题: 
 有一个n*m的2维矩阵matrix，矩阵每一行，每一列都是有序的（升序）。判断矩阵中是否存在元素target。
 提示：时间复杂度O(n+m)，空间复杂度O(1)。
 题目来源：CRACKING THE CODING INTERVIEW 9.6

 Solution: 从右上角或者左下角开始进行。
*/

bool exists(vector<vector<int> > &matrix, int target) {
    if(matrix.empty()) return false;
    int N = matrix.size(), M = matrix[0].size();
    int i = 0, j = M-1;
    while (i < N && j >= 0)
    {
        if (matrix[i][j] == target)
            return true;
        else if (matrix[i][j] < target)
            i++;
        else
            j--;
    }
    return false;
}
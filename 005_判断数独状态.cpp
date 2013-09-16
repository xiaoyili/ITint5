/*
 作者: Annie Kim, anniekim.pku[at]gmail.com
 时间: Sep 13, 2013
 题目: 判断数独状态
 难度: Easy
 链接: http://www.itint5.com/oj/#5
 问题: 
 写程序判断一个9*9的数字盘面是否为合法的数独。
 9*9的盘面按照Row-major order表示为一个81维的一维数组。
 提示：请直接在一维数组上操作，不要先将一维数组拷贝到9*9的二维数组。

 Solution: 参考leetcode题库中Valid Sudoku解法。
*/

int isValidSudoku(int arr[]) {
    const int N = 9;
    int row, col[N] = {0}, box[N] = {0};
    for (int i = 0; i < N; ++i)
    {
        row = 0;
        for (int j = 0; j < N; ++j)
        {
            int index = i * N + j;
            if (arr[index] < 1 || arr[index] > 9)
                return false;
            int bit = 1 << arr[index];
            int box_index = i/3*3 + j/3;

            if (row & bit || col[j] & bit || box[box_index] & bit)
                return false;

            row |= bit;
            col[j] |= bit;
            box[box_index] |= bit;
        }
    }
    return true;
}
/*
 作者: Annie Kim, anniekim.pku[at]gmail.com
 时间: Sep 12, 2013
 题目: 新手入门--元素累加
 难度: Easy
 链接: http://www.itint5.com/oj/#1
 问题: 有一个包含n个整数的数组arr，请计算出数组中所有元素之和。
       （假设中间结果以及最终结果都不会超出32位有符号整型的范围）。

 Solution: 累加。
*/

//返回arr中所有元素之和
//不需要main函数!
int arrSum(const vector<int> &arr) {
    int sum = 0, N = arr.size();
    for (int i = 0; i < N; ++i)
        sum += arr[i];
    return sum;
}
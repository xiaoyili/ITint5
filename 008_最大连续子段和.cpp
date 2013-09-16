/*
 作者: Annie Kim, anniekim.pku[at]gmail.com
 时间: Sep 15, 2013
 题目: 最大连续子段和
 难度: Easy
 链接: http://www.itint5.com/oj/#8
 问题: 
 有一个包含n个元素的数组arr，计算最大的子段和（允许空段）。

 Solution: 与leetcode中的Maximum Subarray类似（dp）。
*/

int maxConsSum(const vector<int> &arr) {
    int dp = 0;
    int res = 0;
    for (int i = 0; i < arr.size(); ++i) {
        dp = max(arr[i], dp + arr[i]);
        res = max(dp, res);
    }
    return res;
}
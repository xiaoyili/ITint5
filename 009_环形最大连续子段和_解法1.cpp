/*
 作者: Annie Kim, anniekim.pku[at]gmail.com
 时间: Sep 16, 2013
 题目: 环形最大连续子段和
 难度: Easy
 链接: http://www.itint5.com/oj/#9
 问题: 
 有一个包含n个元素的首尾相连的环形数组arr，计算最大的子段和（允许空段）。
 样例：数组[1, 3, -2, 6, -1]，最大子段和应该为9，对应的子段为[6, -1, 1, 3]。

 Solution: 1. 非环形的情况直接应用“最大连续子段和”的解法，最大值为M_1。
           2. 对于环形，求出“最小连续子段和”。用整个数组的和sum减去最小连续子段和则为环形最大值M_2。
           3. 返回M_1和M_2中较大者。
*/

// 最大连续子段和
int maxConsSum(const vector<int> &arr) {
    int dp = 0, res = 0;
    for (int i = 0; i < arr.size(); ++i) {
        dp = max(arr[i], dp + arr[i]);
        res = max(dp, res);
    }
    return res;
}

// 最小连续子段和
int minConsSum(const vector<int> &arr) {
    int dp = 0, res = 0;
    for (int i = 0; i < arr.size(); ++i) {
        dp = min(arr[i], dp + arr[i]);
        res = min(dp, res);
    }
    return res;
}

// 环形最大连续子段和
int maxConsSum2(const vector<int> &arr) {
    int N = arr.size();
    int sum = 0;
    for (int i = 0; i < N; ++i)
        sum += arr[i];
    int res = maxConsSum(arr); // 非环形
    res = max(res, sum - minConsSum(arr)); // 环形
    return res;
}
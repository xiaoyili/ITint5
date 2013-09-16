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
           2. 对于环形，分别计算出：
              a)对于i从0到N-1，计算arr[0]到arr[i]之和的最大值，保存在l2r[i]。
              b)对于i从N-1到0，计算arr[i]到arr[N-1]之和的最大值，保存在r2l[i]。
              最后，取l2r[i]+r2l[i+1]的最大值M_2。
           3. 返回M_1和M_2中较大者。
*/

int maxConsSum(const vector<int> &arr) {
    int dp = 0, res = 0;
    for (int i = 0; i < arr.size(); ++i) {
        dp = max(arr[i], dp + arr[i]);
        res = max(dp, res);
    }
    return res;
}

int maxConsSum2(const vector<int> &arr) {
    int N = arr.size();
    if (N == 0) return 0;
    int res = maxConsSum(arr); // 非环形

    int l2r[N], r2l[N];
    int sum = 0;
    for (int i = 0; i < N; ++i) {
        l2r[i] = i == 0 ? max(0, arr[i]) : max(l2r[i-1], sum + arr[i]);
        sum += arr[i];
    }
    sum = 0;
    for (int i = N-1; i >= 0; --i) {
        r2l[i] = i == N-1 ? max(0, arr[i]) : max(r2l[i+1], sum + arr[i]);
        sum += arr[i];
    }

    res = max(res, r2l[N-1]);
    for (int i = 0; i < N-1; ++i)
        res = max(res, l2r[i] + r2l[i+1]);
    return res;
}
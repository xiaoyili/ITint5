/*
 作者: Annie Kim, anniekim.pku[at]gmail.com
 时间: Sep 18, 2013
 题目: 交替字符串
 难度: Easy
 链接: http://www.itint5.com/oj/#17
 问题: 
 如果字符串str3能够由str1和str2中的字符按顺序交替形成，那么称str3为str1和str2的交替字符串。
 例如str1="abc"，str2="def"，那么"adbecf", "abcdef", "abdecf", "abcdef", "adefbc"等等都为str1和str2的交替字符串。
 
 更形式化的，str3的生成算法如下：
 str3=""
 while str1不为空 or str2不为空:
     把str1或str2的首字符加入到str3,并从str1或str2中删除相应的字符
 end

 给定str1, str2,和str3，判断str3是否为str1和str2的交替字符串。

 Solution: 跟LeetCode的Interleaving String相同。
*/

bool isInterleaving(string &str1, string &str2, string &str3) {
    int N = str1.size(), M = str2.size(), L = str3.size();
    if (N + M != L) return false;

    bool dp[N+1][M+1];
    for (int i = 1; i <= N; ++i)
        dp[i][0] = str1[i-1] == str3[i-1];
    for (int j = 1; j <= M; ++j)
        dp[0][j] = str2[j-1] == str3[j-1];

    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
            dp[i][j] = dp[i-1][j] && str1[i-1] == str3[i+j-1] || 
            dp[i][j-1] && str2[j-1] == str3[i+j-1];

    return dp[N][M];
}
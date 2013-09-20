/*
 作者: Annie Kim, anniekim.pku[at]gmail.com
 时间: Sep 20, 2013
 题目: 整数拼接
 难度: Easy
 链接: http://www.itint5.com/oj/#45
 问题: 
 数组nums中有n个非负整数（整数用字符串表示），将它们以一定的顺序拼接，得到最大的整数。
 样例：
 n=4
 nums: ["54", "546", "548", "60"]
 可以拼接得到的最大整数为"6054854654"，因此函数应该返回"6054854654"。

 Solution: 关键是比较函数。
*/

bool mycompare(string a, string b) {
    return a + b > b + a;
}

string biggestNum(vector<string> &nums) {
    int N = nums.size();
    sort(nums.begin(), nums.end(), mycompare);
    string res;
    for (int i = 0; i < N; ++i)
        res += nums[i];
    return res;
}
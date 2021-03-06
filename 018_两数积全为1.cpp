/*
 作者: Annie Kim, anniekim.pku[at]gmail.com
 时间: Sep 18, 2013
 题目: 两数积全为1
 难度: Medium
 链接: http://www.itint5.com/oj/#18
 问题: 
 给定一个非负整数a（不超过106），是否存在整数b，使得a和b的乘积全为1。
 如果存在，返回最小的乘积的位数。如果不存在，返回-1。
 样例：a=3，存在b=37，使得3*37=111，则函数应返回3（111的位数）。

 Solution: 该方案来自问答区。
           首先根据个位数字判断是否存在这样的数，其次根据模运算的性质避免大数运算。
*/

int findMinAllOne(int a) 
{
    int M[] = {0, 1, 0, 1, 0, 0, 0, 1, 0, 1};
    if (M[a % 10] == 0) return -1;

    int count = 1;
    for (int i = 1; i > 0; i %= a)
    {
        i = i * 10 + 1;
        count++;
    }
    return a == 1 ? 1 : count;
}
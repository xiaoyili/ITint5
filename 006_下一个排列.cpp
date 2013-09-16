/*
 作者: Annie Kim, anniekim.pku[at]gmail.com
 时间: Sep 12, 2013
 题目: 下一个排列
 难度: Easy
 链接: http://www.itint5.com/oj/#6
 问题: 给定一个包含n个整数的数组，计算出它的下一个排列（即C++ STL中的next_permutation函数）。

 Solution: 参考leetcode中next permutation一题。
*/

bool next_permutation(vector<int> &arr) {
    int index = arr.size() - 2;
    while (index >= 0 && arr[index] >= arr[index+1]) 
        index--;
    if (index < 0)
        return false;
    sort(arr.begin() + index + 1, arr.end());
    int replace = index + 1;
    while (arr[replace] <= arr[index])
        replace++;
    swap(arr[index], arr[replace]);
    return true;
}
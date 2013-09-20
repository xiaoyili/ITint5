/*
 作者: Annie Kim, anniekim.pku[at]gmail.com
 时间: Sep 20, 2013
 题目: 两有序数组的交和并
 难度: Easy
 链接: http://www.itint5.com/oj/#43
 问题: 
 有2个大小为n和m的有序数组（升序）a和b，实现2个函数arrayUnion和arrayIntersect计算
 它们的并集和交集，结果也必须有序。
 提示：时间复杂度O(n+m)，空间复杂度O(1)。

 Solution: ...
*/

vector<int> arrayUnion(vector<int> &a, vector<int> &b) {
    int N = a.size(), M = b.size();
    int i = 0, j = 0;
    vector<int> res(N+M);
    int k = 0;
    while (i < N || j < M)
    {
        int value;
        if (i == N) value = b[j++];
        else if (j == M) value = a[i++];
        else value = a[i] < b[j] ? a[i++] : b[j++];
        
        if (k == 0 || res[k-1] != value)
            res[k++] = value;
    }
    res.resize(k);
    return res;
}

vector<int> arrayIntersect(vector<int> &a, vector<int> &b) {
    int N = a.size(), M = b.size();
    int i = 0, j = 0;
    vector<int> res(min(N, M));
    int k = 0;
    while (i < N && j < M)
    {
        if (a[i] == b[j]) {
            if (k == 0 || res[k-1] != a[i])
                res[k++] = a[i];
            i++; j++;
        }
        else if (a[i] < b[j])
            i++;
        else
            j++;
    }
    res.resize(k);
    return res;
}
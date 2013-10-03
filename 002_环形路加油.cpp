/*
 作者: Annie Kim, anniekim.pku[at]gmail.com
 时间: Sep 13, 2013
 题目: 环形路加油
 难度: Medium
 链接: http://www.itint5.com/oj/#2
 问题: 
 有一个环形公路上有n个加油站，第i个加油站的油量为a[i]。
 假设有一辆邮箱体积无穷大的汽车，初始邮箱是空的，汽车从加油站i行驶到加油站i+1需耗油g[i]。
 问是否能够选出某个加油站作为起点，使汽车能够绕环形公路行驶一圈返回到该加油站。
 实现函数int selectGasStation(int a[], int g[], int n)。
 如果存在满足条件的加油站，返回该加油站的序号(0-based)。否则返回-1。
 提示：n可能达到106，O(n^2)的枚举算法会超出时间限制。

 Solution: 
           1. 从左往右遍历，记住油量和最少的位置，从其下一个位置出发。
           2. 开辟一个长度为N的数组v，记录a[i]-g[i]。
              从后往前遍历数组v。
              如果v[i]小于零，将其与v[i-1]合并，因为此时i不可能作为起点。
              如果v[i]不小于零，记入sum，并记录该位置pos（有可能作为起点）。
              最后，如果v[0]大于等于零，说明整个路段已经没有负的v[i]。返回0即可。
              如果v[0]+sum>=0，有满足条件的加油站，返回pos。
              否则，返回-1。
           3. 开辟一个长度为2*N-1的数组v，记录a[i]-g[i]（环转化为线性）。
              使用两个指针start和end。
              如果[start, end]区间和小于0，令start = end + 1并继续。
              直至找到长度为N的区间[start, end]，并且区间和大于等于0。找到返回start。
           以上三种方案的时间复杂度皆为O(N)。
*/

int selectGasStation_1(const vector<int> &a, const vector<int> &g) {
    int N = a.size();
    int res = 0, min = a[0] - g[0], sum = min;
    for (int i = 1; i < N; ++i)
    {
        sum += a[i] - g[i];
        if (sum < min) {
            min = sum;
            res = i;
        }
    }
    return sum >= 0 ? (res + 1) % N : -1;
}

int selectGasStation_2(const vector<int> &a, const vector<int> &g) {
    int N = a.size();
    int v[N];
    for (int i = 0; i < a.size(); ++i)
        v[i] = a[i] - g[i];
    int sum = 0, pos = -1;
    for (int i = N-1; i > 0; --i)
    {
        if (v[i] >= 0) {
            sum += v[i];
            pos = i;
        } else {
            v[i-1] += v[i];
        }
    }
    if (v[0] >= 0) return 0;
    else if (v[0] + sum >= 0) return pos;
    else return -1;
}

int selectGasStation_3(const vector<int> &a, const vector<int> &g) {
    int N = a.size();
    int v[2 * N];
    for (int i = 0; i < N; ++i)
    {
        v[i] = a[i] - g[i];
        v[i+N] = a[i] - g[i];
    }
    int sum = 0;
    for (int start = 0, end = 0; start <= N && end < 2 * N; end++)
    {
        if (sum + v[end] < 0) {
            start = end + 1;
            sum = 0;
        } else {
            if (end - start == N - 1) 
                return start;
            sum += v[end];
        }
    }
    return -1;
}
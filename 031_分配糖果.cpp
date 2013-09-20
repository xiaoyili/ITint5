/*
 作者: Annie Kim, anniekim.pku[at]gmail.com
 时间: Sep 20, 2013
 题目: 分配糖果
 难度: Easy
 链接: http://www.itint5.com/oj/#31
 问题: 
 有n个小朋友站成一排（编号从0到n-1)，每个小朋友有一个rating值，存放在ratings数组中。
 老师需要给他们分配糖果，每个小朋友至少需要一颗糖果，对于任意相邻的两个小朋友i和i+1，
 rating值大的必须比rating值小的分配的糖果多（rating相同的没必要分配一样多的糖果）。
 请计算最少需要多少颗糖果，才能完成上述分配。
 提示：本题存在O(n)的算法。
 来源：CareerCup和InterviewStreet。

 Solution: 两个方案。可以先尝试写O(n)空间，再看看O(1)空间可不可行。
           面试的时候也不要一上来写难度大的，容易慌，先写简单的再改进，这样思路也更清晰。
*/

/*
 方案 1：O(n)时间，O(n)空间。
         先每人分1个糖果。
         从左向右遍历一遍，如果右边比左边的rating大，就令右边的孩子比左边多一个糖果。
         从右向左遍历一遍，如果左边比右边的rating大，并且糖果数不满足要求，就令左边的孩子比右边多一个糖果。
*/
long long minimalCandies(vector<int> &ratings) {
    int N = ratings.size();
    int candy[N];
    for (int i = 0; i < N; ++i)
        candy[i] = 1;
    for (int i = 1; i < N; ++i)
        if (ratings[i] > ratings[i-1])
            candy[i] = candy[i-1] + 1;
    for (int i = N-2; i >= 0; --i)
        if (ratings[i] > ratings[i+1] && candy[i] <= candy[i+1])
            candy[i] = candy[i+1] + 1;
    long long res = 0;
    for (int i = 0; i < N; ++i)
        res += candy[i];
    return res;
}

/*
 方案 2：O(n)时间，O(1)空间。
         不需要记录每个孩子得到的糖果数目，只需要记录前一个孩子得到的糖果数last和
         当前孩子之前rating取极大值的孩子位置j，以及该位置上孩子的糖果数j_v。
         通过这个j和j_v，就可以判断需不要补糖果，以及补几颗。
*/
long long minimalCandies(vector<int> &ratings) {
    int N = ratings.size();
    if (N == 0) return 0;
    long long res = 1;
    int j = -1, j_v = N+1;
    int last = 1; 
    for (int i = 1; i < N; ++i)
    {
        if (ratings[i] >= ratings[i-1]) {
            last = ratings[i] == ratings[i-1] ? 1 : last + 1;
            res += last;
            j = i;
            j_v = last;
        } else {
            if (last == 1) {
                if (i - j >= j_v) {
                    res += (i - j + 1);
                    j_v++;
                } else {
                    res += i - j;
                }
            } else {
                last = 1;
                res++;
            }
        }
    }
    return res;
}
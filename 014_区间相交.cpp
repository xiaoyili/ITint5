/*
 作者: Annie Kim, anniekim.pku[at]gmail.com
 时间: Sep 17, 2013
 题目: 区间相交
 难度: Easy
 链接: http://www.itint5.com/oj/#14
 问题: 
 有n个左右端点都为整数的区间，判断每个区间是否有与其它某个区间相交（区间端点重合也算相交）。

 Solution: 按照区间左端点进行排序，并按照从小到大顺序进行遍历。
           遍历过程中记录目前为止的最大右端点。
           判断区间是否相交，就只需判断当前区间的左端点是否小于或等于最大右端点。
*/

/*
struct Interval {
    int start; //区间左端点
    int end;   //区间右端点
};
*/

bool compare(pair<int, Interval> a, pair<int, Interval> b) {
    return a.second.start < b.second.start;
}

// intervals包含n个区间
// 结果存放到isIntersected中(已分配空间,不需要push_back)
// isIntersected[i]表示第i个区间是否与其它区间相交
void intersected(vector<Interval> &intervals, vector<bool> &isIntersected) {
    int N = intervals.size();
    if (N == 0) return;

    pair<int, Interval> itvl[N];
    for (int i = 0; i < N; ++i)
        itvl[i] = make_pair(i, intervals[i]);
    sort(itvl, itvl + N, compare);
    
    int max_end = 0;
    isIntersected[itvl[0].first] = false;
    for (int i = 1; i < N; ++i)
    {
        if (itvl[i].second.start <= itvl[max_end].second.end)
            isIntersected[itvl[i].first] = isIntersected[itvl[max_end].first] = true;
        if (itvl[max_end].second.end < itvl[i].second.end)
            max_end = i;
    }
}
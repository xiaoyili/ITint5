/*
 作者: Annie Kim, anniekim.pku[at]gmail.com
 时间: Sep 21, 2013
 题目: 堆放积木
 难度: Medium
 链接: http://www.itint5.com/oj/#34
 问题: 
 有n块积木，每块积木有体积vol和重量weight两个属性，用二元组(vol, weight)表示。
 积木需要搭成竖直的塔状，上面积木的体积和重量必须都比它下面的积木小。问最多可以搭多少个积木。
 样例：
 有7个积木boxes:
    [(65, 100), (70, 150), (56, 90), (75, 190), (60, 95), (68, 110), (80, 12)]
 最多可以搭6个积木，从上到下分别为：
    (56, 90), (60, 95), (65, 100), (68, 110), (70, 150), (75, 190)
 所以函数应该返回6。
 题目来源：CRACKING THE CODING INTERVIEW 9.7

 Solution: 先按照vol进行排序，题目就变成了根据weight寻找最长严格递增子序列。
*/

/*积木的定义(请不要在代码中定义该结构)
struct Box {
  int vol, weight;
};*/
int mycompare(Box a, Box b) {
    if (a.vol == b.vol)
        return a.weight < b.weight;
    return a.vol < b.vol;
}
int maxBoxes(vector<Box> &boxes) {
    int N = boxes.size();
    if (N == 0) return 0;
    sort(boxes.begin(), boxes.end(), mycompare);
    int dp[N];
    int res = 1;
    for (int i = 0; i < N; ++i)
    {
        dp[i] = 1;
        for (int j = 0; j < i; ++j)
            if (boxes[i].vol > boxes[j].vol && boxes[i].weight > boxes[j].weight)
                dp[i] = max(dp[i], dp[j] + 1);
        res = max(res, dp[i]);
    }
    return res;
}
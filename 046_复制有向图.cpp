/*
 作者: Annie Kim, anniekim.pku[at]gmail.com
 时间: Sep 20, 2013
 题目: 复制有向图
 难度: Easy
 链接: http://www.itint5.com/oj/#46
 问题: 
 复制一个有向图。输入是有向图中的一个结点指针，返回复制的图中对应的结点指针。

 Solution: 我在facebook电面时也遇到过这个题目，deep copy一个graph。
*/

/*
有向图中结点的定义为：
struct GraphNode {
    int data;
    vector<GraphNode*> neighbors;
    GraphNode(int data) : data(data) {}
};
*/

/*
 方案 1：DFS。
*/
typedef unordered_map<GraphNode *, GraphNode *> MAP;

GraphNode *cloneGraphRe(GraphNode *node, MAP &exist) {
    if (!node) return NULL;
    if (exist.find(node) != exist.end())
        return exist[node];
    GraphNode *newNode = new GraphNode(node->data);
    exist[node] = newNode;
    for (int i = 0; i < node->neighbors.size(); ++i)
        newNode->neighbors.push_back(cloneGraphRe(node->neighbors[i], exist));
    return newNode;
}

GraphNode *cloneGraph(GraphNode *node) {
    MAP exist;
    return cloneGraphRe(node, exist);
}

/*
 方案 2：BFS。
*/
typedef unordered_map<GraphNode *, GraphNode *> MAP;

GraphNode *cloneGraph(GraphNode *node) {
    if (!node) return NULL;
    MAP exist;
    exist[node] = new GraphNode(node->data);
    queue<GraphNode *> q;
    q.push(node);
    while (!q.empty())
    {
        GraphNode *orig = q.front();
        GraphNode *newNode = exist[orig];
        q.pop();
        for (int i = 0; i < orig->neighbors.size(); ++i)
        {
            if (exist.find(orig->neighbors[i]) != exist.end()) {
                newNode->neighbors.push_back(exist[orig->neighbors[i]]);
                continue;
            }
            GraphNode *newNeighbor = new GraphNode(orig->neighbors[i]->data);
            newNode->neighbors.push_back(newNeighbor);
            exist[orig->neighbors[i]] = newNeighbor;
            q.push(orig->neighbors[i]);
        }
    }
    return exist[node];
}
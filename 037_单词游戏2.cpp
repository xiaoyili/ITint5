/*
 作者: Annie Kim, anniekim.pku[at]gmail.com
 时间: Sep 20, 2013
 题目: 单词游戏2
 难度: Medium
 链接: http://www.itint5.com/oj/#37
 问题: 
 一个n*m的字母网格grid，格子中的字母属于26个大写字母。选择某个格子作为起始点，
 每一步可以移动到上下左右相邻的格子中，这样遍历经过的字母形组成了单词（每个格子只能访问一次）。
 patterns包含k个单词，判断patterns是否有单词能在网格中找到。
 样例：
 n=3,m=4
 Grid:
 PACD
 BGHI
 MNDC
 对于patterns = ["E", "DCHGB", "ABC"]，返回true。
 对于patterns = ["E", "CIDCB", "ABC"]，返回false。

 Solution: 将所有的pattern建成一个trie。
           如果A是B的前缀，则只需要判断能否在网格中找到A就可以了，不需要找B。
*/

struct TrieNode {
    bool end;
    TrieNode *next[26];
    TrieNode() : end(false) {
        memset(next, NULL, sizeof(next));
    }
};
TrieNode *root = NULL;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void addTrie(const string &pattern)
{
    if (!root) root = new TrieNode();
    TrieNode *cur = root;
    for (int i = 0; i < pattern.size(); ++i)
    {
        if (cur->end == true) return;
        int c = pattern[i] - 'A';
        if (cur->next[c] == NULL)
            cur->next[c] = new TrieNode();
        cur = cur->next[c];
    }
    cur->end = true;
}

bool existsRe(vector<vector<char> > &grid, TrieNode *node, int i, int j, vector<vector<bool> > &visited) {
    if (!node || visited[i][j]) return false;
    if (node->end == true) return true;
    visited[i][j] = true;
    int N = grid.size(), M = grid[0].size();
    for (int k = 0; k < 4; ++k)
    {
        int x = i + dx[k], y = j + dy[k];
        if (x < 0 || x >= N || y < 0 || y >= M) continue;
        if (existsRe(grid, node->next[grid[x][y] - 'A'], x, y, visited)) 
            return true;
    }
    visited[i][j] = false;
    return false;
}

bool exists(vector<vector<char> > &grid, vector<string> &patterns) {
    if (grid.empty() || patterns.empty()) return false;
    for (int i = 0; i < patterns.size(); ++i)
        addTrie(patterns[i]);
    if (root->end) return true;
    int N = grid.size(), M = grid[0].size();
    vector<vector<bool> > visited(N, vector<bool>(M, false));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            if (existsRe(grid, root->next[grid[i][j] - 'A'], i, j, visited))
                return true;
    return false;
}
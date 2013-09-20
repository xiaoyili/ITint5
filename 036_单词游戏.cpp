/*
 作者: Annie Kim, anniekim.pku[at]gmail.com
 时间: Sep 20, 2013
 题目: 单词游戏
 难度: Easy
 链接: http://www.itint5.com/oj/#36
 问题: 
 一个n*m的字母网格grid，格子中的字母属于26个大写字母。
 选择某个格子作为起始点，每一步可以移动到上下左右相邻的格子中，这样遍历经过的字母组成了单词（每个格子只能访问一次）。
 判断是否能够在网格中找到给定的单词pattern。
 样例：
 n=3,m=4
 Grid:
 PACD
 BGHI
 MNDC
 对于pattern = "DCHGB"，返回true。
 对于pattern = "PBGNDC", 返回true。
 对于pattern = "CIDCB"，返回false。

 Solution: 和LeetCode中Word Search一题重复。DFS。
*/

bool existsRe(vector<vector<char> > &grid, string &pattern, 
              int start, int i, int j, vector<vector<bool> > &visited) {
    int N = grid.size(), M = grid[0].size();
    if (start == pattern.size()) return true;
    if (i < 0 || i >= N || j < 0 || j >= M) return false;
    if (grid[i][j] != pattern[start] || visited[i][j]) return false;
    
    visited[i][j] = true;
    if (existsRe(grid, pattern, start + 1, i-1, j, visited)) return true;
    if (existsRe(grid, pattern, start + 1, i+1, j, visited)) return true;
    if (existsRe(grid, pattern, start + 1, i, j-1, visited)) return true;
    if (existsRe(grid, pattern, start + 1, i, j+1, visited)) return true;
    visited[i][j] = false;
    return false;
}

bool exists(vector<vector<char> > &grid, string pattern) {
    if (grid.empty()) return false;
    if (pattern.empty()) return true;
    int N = grid.size(), M = grid[0].size();
    vector<vector<bool> > visited(N, vector<bool>(M, false));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            if (existsRe(grid, pattern, 0, i, j, visited))
                return true;
    return false;
}
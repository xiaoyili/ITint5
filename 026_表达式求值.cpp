/*
 作者: Annie Kim, anniekim.pku[at]gmail.com
 时间: Sep 19, 2013
 题目: 表达式求值
 难度: Easy
 链接: http://www.itint5.com/oj/#26
 问题: 
 给定一个表达式字符串，其中只包含非负整数，加法，减法以及乘法符号，例如7+3*4*5+2+4-3-1。
 请写程序计算该表达式的值。
 提示：可以尝试使用递归算法，程序将非常简洁易写，很适用于面试场合。

 Solution: 一开始写了逻辑复杂的，看了fabregas4的代码，才知道怎么简化。
           关键在于如何利用'n'来统一简化加减乘。
*/

/*---------------------------------------------------------
 方案一：递归。
*/
int getNumber(const string &expr, int &i) {
    int number = 0, N = expr.size();
    while (i < N && expr[i] >= '0' && expr[i] <= '9') {
        number = number * 10 + (expr[i] - '0');
        i++;
    }
    return number;
}

int evaluate(const string& expr, int i, int n) {
    n *= getNumber(expr, i);
    if (i == expr.size()) return n;
    if (expr[i] == '*') return evaluate(expr, i + 1, n);
    if (expr[i] == '+') return n + evaluate(expr, i + 1, 1);
    if (expr[i] == '-') return n + evaluate(expr, i + 1, -1);
}

//返回表达式expr的值
int evaluate(const string& expr) {
	return evaluate(expr, 0, 1);
}

/*---------------------------------------------------------
 方案二：迭代。‘getNumber’函数在方案一。
*/
//返回表达式expr的值
int evaluate(const string& expr) {
    int res = 0;
    int i = 0, N = expr.size();
    int n = 1;
    for (int i = 0; i < N; ++i)
    {
        int number = getNumber(expr, i);
        n *= number;
        if (i == N) res += n;
        else if (expr[i] == '+') {res += n; n = 1; }
        else if (expr[i] == '-') {res += n; n = -1; }
    }
    return res;
}
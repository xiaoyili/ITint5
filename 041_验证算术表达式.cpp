/*
 作者: Annie Kim, anniekim.pku[at]gmail.com
 时间: Sep 19, 2013
 题目: 验证算术表达式
 难度: Easy
 链接: http://www.itint5.com/oj/#41
 问题: 
 验证字符串expr是否为合法的算术表达式。expr中只包含：
 数字'0'-'9'。
 二元运算符'+', '-'。
 括号'(', ')'。
 样例：
 expr="1"  合法的表达式，返回true
 expr="10+(2-(31+(4)))"  合法的表达式，返回true
 expr="-1"  不合法的表达式，返回false
 expr="1+"  不合法的表达式，返回false
 提示：此题可使用表达式求值中类似的递归算法。

 Solution: stack. 整个代码写的有点乱。求更好的solution！
*/

/*
 'e' stands for empty,
 'n' stands for numbers,
 'o' stands for operators and
 '(' and ')' are stored as they are.
*/
stack<char> stk;

bool validNumber(const string& expr, int &i) {
    int j = i;
    bool isZero = expr[i] == '0';
    while (j < expr.size() && expr[j] >= '0' && expr[j] <= '9')
        j++;
    if (j == i || isZero && j - i > 1) return false;
    i = j - 1;
    return true;
}

char getTop() {
    if (stk.empty()) return 'e';
    else return stk.top();
}

bool validate(const string& expr) {

    int N = expr.size();
    for (int i = 0; i < N; ++i)
    {
        if (expr[i] == '+' || expr[i] == '-') {
            if (getTop() != 'n') return false;
            stk.push('o');
        }
        else if (expr[i] == '(') {
            if (getTop() == 'n') return false;
            stk.push('(');
        }
        else if (expr[i] == ')') {
            if (getTop() != 'n') return false;
            stk.pop();
            if (getTop() != '(') return false;
            stk.pop();
            if (getTop() == 'o') stk.pop();
            else stk.push('n');
        }
        else
        {
            if (!validNumber(expr, i)) return false;
            if (getTop() == 'o') stk.pop();
            else stk.push('n');
        }
    }
    return stk.empty() || stk.size() == 1 && stk.top() == 'n';
}
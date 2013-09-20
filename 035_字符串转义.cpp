/*
 作者: Annie Kim, anniekim.pku[at]gmail.com
 时间: Sep 20, 2013
 题目: 字符串转义
 难度: Easy
 链接: http://www.itint5.com/oj/#35
 问题: 请将字符串str中的空格全部转换为"%20"，str有足够的空间可以存放转换后的结果。
 提示：不要使用任何辅助空间。
 来源：CRACKING THE CODING INTERVIEW 1.5

 Solution: 从后往前copy。
*/

void escapeSpace(char *str) {
    if (!str) return;
    int N = strlen(str);
    int num_space = count(str, str + N, ' ');
    int j = N + num_space * 2;
    for (int i = N-1; i >= 0; --i)
    {
        if (str[i] == ' ') {
            j -= 3;
            strncpy(str+j, "%20", 3);
        } else {
            str[--j] = str[i];
        }
    }
}
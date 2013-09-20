/*
 作者: Annie Kim, anniekim.pku[at]gmail.com
 时间: Sep 19, 2013
 题目: Excel数转换
 难度: Easy
 链接: http://www.itint5.com/oj/#23
 问题: 
 Excel中的行列数用A~Z 26个字母表示，A, B, C, D, …, Z, AA, AB, …, AZ, BA, BB, … 
 分别表示10进制数1, 2, 3, 4, …, 26, 27, 28, …, 52, 53, 54…。
请实现2个函数decToExcel和excelToDec，将10进制数转换为Excel数，以及将Excel数转换为10进制数。

 Solution: ...
*/

#include <algorithm>
using namespace std;

const int BASE = 26;

//将十进制数转换为excel数
string decToExcel(int decNum) {
    string res;
    while (decNum) {
        decNum--;
        res.push_back(decNum % BASE + 'A');
        decNum /= BASE;
    }
    reverse(res.begin(), res.end());
    return res;
}

//将excel数转换为十进制数
int excelToDec(string excelNum) {
    int res = 0, N = excelNum.size();
    for (int i = 0; i < N; ++i)
        res = res * BASE + (excelNum[i] - 'A' + 1);
    return res;
}
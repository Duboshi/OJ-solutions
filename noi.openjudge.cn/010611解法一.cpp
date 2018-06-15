/*	NOI 010611 大整数减法 
 *	http://noi.openjudge.cn/ch0106/11/
 *	@author: Dubos（根据《CCF中学生计算机程序设计基础篇》P174例7.2修改）
 */ 
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int num1[205], num2[205], temp[205], result[205], len_num1, len_num2, len_result;

/*首先，把两个大整数按数位逆序写入数组，个位在num1[0]、num2[0]，十位在num1[1]、num2[1]...
	
	参数用数组指针和整数引用是为了可以改变函数外的数组值和整数值，如果直接用数组
	和整数做参数，则函数以外的数组和整数值不会受到影响。*/ 
void assign (int *num, int &len)
{
	int i; //数组序号
 	string s;
	cin >> s;
	len = s.length();
	for (i=0; i<len; i++)
		num[i] = s[i] - '0';
	reverse(num, num+len); //algorithms库函数，把数组前len位元素逆序 
}

int main ()
{
	int i; //数组序号 
	assign(num1, len_num1);
	assign(num2, len_num2); //将输入的两个大整数存入数组
	
	len_result = max(len_num1, len_num2);
	
	for (i=0; i<len_result; i++) //计算result数组各个数位的值
	{
		result[i] = num1[i] - num2[i] + temp[i];
		if (result[i]<0)
		{
			temp[i+1]--;
			result[i]+=10;
		}
	}
	while (result[len_result-1]==0 && len_result>1) //消除前导0，并至少保留1位 
		len_result--;
	
	for (i=len_result-1; i>=0; i--) //输出结果 
		cout<<result[i];
	
	return 0;
}

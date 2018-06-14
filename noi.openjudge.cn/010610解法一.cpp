/*	NOI 010610 大整数加法 
 *	http://noi.openjudge.cn/ch0106/10/
 *	@author: Dubos
 */ 
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int a1[205], b1[205], c1[205], result1[205], len_a1, len_b1, len_result1;

/*首先，把加数和被加数写入数组，个位在a[0]、b[0]，十位在a[1]、b[1]...
	
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
	assign(a1, len_a1);
	assign(b1, len_b1); //将输入的两个大整数存入数组
	
	len_result1 = max(len_a1, len_b1) + 1; //和的位数要足够大 
	
	for (i=0; i<len_result1; i++) //把result1数组各个数位的值填对 
	{
		result1[i] = a1[i] + b1[i] + c1[i];
		if (result1[i]>9)
		{
			c1[i+1] = result1[i]/10;
			result1[i] = result1[i]%10;
		}
	}
	while (result1[len_result1-1]==0) //消除前导0 
		len_result1--; 
		
	for (i=len_result1-1; i>=0; i--) //输出结果 
		cout<<result1[i];
	
	return 0;
}

/*	NOI 011347 大整数除法 
 *	http://noi.openjudge.cn/ch0113/47/
 *	@author: Dubos（根据《CCF基础篇》P176例7.4思路编写） 
 */
#include <algorithm> 
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;

int num1[205], num2[205], temp[205], result[205], len1, len2; //被除数num1，除数num2，余数temp，商result 
char s1[205], s2[205]; //被除数s1，除数s2

//main中需要调用的函数，具体函数定义在main之后。请从main函数开始读起，中间会介绍各个函数的作用 
void assign(int *num, int &len);
void newTemp(int i);
bool noSmallThan();
void bigMinus(); 

int main()
{
	int i, j;	//数组序号，下面常用
	
	//将大整数存入num1和num2数组，各数组第0序号元素用于储存位数，第1位开始存储个位、十位、百位...
	assign(num1, len1);
	assign(num2, len2);
	
	//从被除数的最高位开始，逐位求商
	for (i=len1; i>=1; i--) 
		{
			//temp(i) = temp(i+1)*10 + num1[i];
			//大整数乘以10，以及大整数加一位整数，用newTemp函数实现
			newTemp(i);
			
//			//检验新余数temp
//			cout<<"temp: ";
//			for (j=temp[0]; j>=1; j--)
//				cout<<temp[j];
//			cout<<endl;
			
			//result[i] = temp(i)/num2; temp[i] %= num2;
			//需要反复用大整数减法minus()实现：只要temp(i)不小于num2就一直temp(i) -= num2，另外每减一次result[i]都加一 
			while (noSmallThan()) //用noSmallThan函数判断temp(i)是否不小于num2
			{
				bigMinus();
//					//检验bigMinus: 
//					cout<<"temp: ";
//					for (j=temp[0]; j>=1; j--)
//						cout<<temp[j];
//					cout<<endl;
				result[i]++;
			}
			
//			//检验每位运算后商数
//			cout<<"result: ";
//			for (j=num1[0]; j>=1; j--)
//				cout<<result[j];
//			cout<<endl;
			
//			//检验运算后余数 
//			cout<<"temp: ";
//			for (j=temp[0]; j>=1; j--)
//				cout<<temp[j];
//			cout<<endl<<endl;
		}
	
	if (num1[0]<num2[0]) result[0]=1;
	else result[0] = num1[0]-num2[0]+1; //result最多有这么多位数：num1[0]-num2[0]+1
	while (result[result[0]]==0 && result[0]>1)
		result[0]--; //使result[0]显示确切的位数 
	for (i=result[0]; i>=1; i--) 
			cout<<result[i];
			
	return 0;
}

void assign(int *num, int &len)
{
	string s;
	cin >> s;
	len = s.length();
	for (int i=len; i>=1; i--)
		//s: 	0, 1, ... len-1; 依次存入 
		//num:	len, len-1, ... 2, 1. 
		num[i] = s[len-i] - '0';
	num[0] = len; //num1和num2的序号0元素都用于存储各自的位数，这个数字在这个问题中常用
}

void newTemp(int i)
{/*这个函数要得到的效果是：
	temp(i) = temp(i+1)*10 + num1[i]
	其中temp(i)指计算到num1[i]时的余数，而它是大整数，我们用temp数组处理它的
	乘10和加一位整数运算。
	 
最初计算到num1[len1]时，余数最多有1位，我们用temp[1]储存；
随后计算到num1[len1-1]时，余数最多有2位，我们用temp[1]至temp[2]储存；
... 
之后计算到num1[i+1]时，余数最多有len1-i位，我们用temp[1]至temp[len1-i]储存； 
所以计算到num1[i]位时，余数最多有len1+1-i位，我们用temp[1]至temp[len1+1-i]储存。

如何储存呢？ 
只需把前一步得到的余数temp[1]至temp[len1-i]挪到temp[2]至temp[len1+1-i]，并将
temp[1]赋值为num1[i]即可。

函数参数：int *temp用数组指针可以改变原数组的值，用int i不会改变原i的值。 */
	for (int j=len1-i; j>=1; j--)
		temp[j+1] = temp[j];
	temp[1] = num1[i];	
	temp[0]++;
	while (temp[0]>1 && temp[temp[0]]==0) temp[0]--; //记录temp位数可能发生的变化 
}

bool noSmallThan()
{/*这个函数用于判断temp所储存的大整数是否大于等于num2所储存的大整数，判断过程如下：
	如果 (temp位数 < num2位数)，return false;
	如果 (temp位数 > num2位数)，return true;
	如果 (temp位数 = num2位数)，从最高位开始比较，至第一个不同的数字得出结果； 
	return true;	
*/
	
	if (temp[0]<num2[0]) return false;
	if (temp[0]>num2[0]) return true;
	
	int i;
	for (i=temp[0]; i>=1; i--)
	{
		if (temp[i]<num2[i]) return false;
		if (temp[i]>num2[i]) return true;
	}
	return true;
}

void bigMinus()
{/*这个函数用于实现temp所储存的大整数减去num2所储存的大整数，并记录temp位数变化情况*/
	for (int i=1; i<=num2[0]; i++)
	{
		temp[i] -= num2[i];
		if (temp[i]<0)
		{
			temp[i] += 10;
			temp[i+1]--;
		}
	}
	while (temp[0]>1 && temp[temp[0]]==0) temp[0]--; //记录temp位数可能发生的变化 
}

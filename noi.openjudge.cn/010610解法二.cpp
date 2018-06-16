/*	NOI 010610 大整数加法 
 *	http://noi.openjudge.cn/ch0106/10/
 *	@author: Dubos（根据《程序设计导引及在线实践》P136例7.1修改） 
 */
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int num1[205], num2[205];
char s1[205], s2[205];

int main()
{
	scanf("%s", s1);
	scanf("%s", s2); 
	
	int i, j;	//数组序号 
	
	//将两个数字逆序储存到数组中，个位储存在序号0位置，十位在序号1位置... 
	int len1 = strlen(s1);
	j = 0;
	for(i=len1-1; i>=0; i--)
		num1[j++] = s1[i] - '0';
		
	int len2 = strlen(s2);
	j = 0;
	for(i=len2-1; i>=0; i--)
		num2[j++] = s2[i] - '0';
		
	int len = max(len1, len2) + 1; //这是结果所需的最多位数
		
	//计算和与进位，结果存储在an1中
	for(i=0; i<len; i++)
	{
		num1[i]+=num2[i];
		if(num1[i]>=10)
		{
			num1[i]-=10;
			num1[i+1]++;
		}
	}
	
	bool check = false; //是否可以逐位将数字输出，最开始为false，因为可能开始是0
	for(i=len; i>=0; i--) //输出 
	{
		if(check) //3. 首个非0值输出之后，bStartOutput变为真，正常输出 
			printf("%d", num1[i]);
		else 			//1. 从这里开始 
			if(num1[i])	//2. 遇到首个非0值才开始输出 
			{
				printf("%d", num1[i]);
				check = true;
			}
	}
	if(!check) printf("%d", 0); //输入0， 0，则输出0 
		
	return 0;
}

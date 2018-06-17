/*	NOI 011309 大整数乘法
 *	http://noi.openjudge.cn/ch0113/09/
 *	@author: Dubos
 */
#include <cstdio>
#include <cstring>

using namespace std;

int num1[205], num2[205], result[410];
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
		
	int len = len1 + len2;
		
	//计算乘积，暂时不进位，结果存储在result中
	for (i=0; i<len1; i++)
		for (j=0; j<len2; j++)
			result[i+j] += num1[i] * num2[j];
			
	//进位
	for (i=0; i<len; i++)
		if (result[i]>9)
		{
			result[i+1] += result[i]/10;
			result[i] %= 10;
		}
	
	bool check = false; //判断是否可以直接输出数字，最初为false，因为可能是0
	for(i=len; i>=0; i--)
	{
		if(check) //3. 首个非0值输出之后，bStartOutput变为真，正常输出 
			printf("%d", result[i]);
		else 			//1. 从这里开始，因为check最初为false
			if(result[i])	//2. 遇到首个非0值才开始输出 
			{
				printf("%d", result[i]);
				check = true;
			}
	}
	if(!check) printf("%d", 0); //输入0， 0，则输出0 
		
	return 0;
}

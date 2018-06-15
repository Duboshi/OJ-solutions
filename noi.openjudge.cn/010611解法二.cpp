/*	NOI 010611 大整数减法 
 *	http://noi.openjudge.cn/ch0106/11/
 *	@author: Dubos
 */
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int an1[210];
int an2[210];
char szLine1[210];
char szLine2[210];

int main()
{
	scanf("%s", szLine1);
	scanf("%s", szLine2); 
	
	int i, j;	//数组序号 
	
	//将两个数字逆序储存到数组中，个位储存在序号0位置，十位在序号1位置... 
	int nLen1 = strlen(szLine1);
	j = 0;
	for(i=nLen1-1; i>=0; i--)
		an1[j++] = szLine1[i] - '0';
		
	int nLen2 = strlen(szLine2);
	j = 0;
	for(i=nLen2-1; i>=0; i--)
		an2[j++] = szLine2[i] - '0';
		
	int len = max(nLen1, nLen2);//algorithm库函数
		
	//计算差与退位（借位），结果存储在an1中
	for(i=0; i<len; i++)
	{
		an1[i]-=an2[i];
		if(an1[i]<0)
		{
			an1[i]+=10;
			an1[i+1]--;
		}
	}
	
	bool bStartOutput = false;
	for(i=len; i>=0; i--) //输出 
	{
		if(bStartOutput) //3. 首个非0值输出之后，bStartOutput变为真，正常输出 
			printf("%d", an1[i]);
		else 			//1. 从这里开始 
			if(an1[i])	//2. 遇到首个非0值才开始输出 
			{
				printf("%d", an1[i]);
				bStartOutput = true;
			}
	}
	if(!bStartOutput) printf("%d", 0); //输入0， 0，则输出0 
		
	return 0;
}

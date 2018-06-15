/*	NOI 010610 大整数加法 
 *	http://noi.openjudge.cn/ch0106/10/
 *	@author: Dubos（根据《程序设计导引及在线实践》P136例7.1修改） 
 */
#include <cstdio>
#include <cstring>
#define MAX_LEN 200

int an1[MAX_LEN+10];
int an2[MAX_LEN+10];
char szLine1[MAX_LEN+10];
char szLine2[MAX_LEN+10];

int main()
{
	scanf("%s", szLine1);
	scanf("%s", szLine2); 
	
	int i, j;	//数组序号 
	
	memset(an1, 0, 210);
	memset(an2, 0, 210);
	
	//将两个数字逆序储存到数组中，个位储存在序号0位置，十位在序号1位置... 
	int nLen1 = strlen(szLine1);
	j = 0;
	for(i=nLen1-1; i>=0; i--)
		an1[j++] = szLine1[i] - '0';
		
	int nLen2 = strlen(szLine2);
	j = 0;
	for(i=nLen2-1; i>=0; i--)
		an2[j++] = szLine2[i] - '0';
		
	//计算和与进位，结果存储在an1中
	for(i=0; i<MAX_LEN; i++)
	{
		an1[i]+=an2[i];
		if(an1[i]>=10)
		{
			an1[i]-=10;
			an1[i+1]++;
		}
	}
	
	bool bStartOutput = false;
	for(i=MAX_LEN; i>=0; i--) //输出 
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

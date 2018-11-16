|题目名|*Common Subsequence*|  
|---|---|  
|**题源**|Southeastern Europe 2003|  
|**OJ**|[POJ 1458](http://poj.org/problem?id=1458)([vjudge](https://vjudge.net/problem/POJ-1458))|  
|**标签**|动态规划普及组，LCS|  
|**难度**|普及组简单题|  

#### 题目
#### 分析 
#### 答案
```cpp
/*
	POJ 1458 Common Subsequence
	
	POJ 1458没说两个字符串的长度；
	UVA 10405条件是长度不超过1000；
	Luogu P1439条件是长度不超过100000。 
	
	《算法基础与在线实践》P143
	这题我想了半天用滚动数组，发现过程比较复杂，而且滚动数组对n=1000000也没什么用，
	所以就不滚了。 
*/

#include <cstdio>
#include <cstring>
using namespace std;

const int MAX_N = 1010;
char s1[MAX_N], s2[MAX_N];
int LCS[MAX_N][MAX_N]; 

int main()
{
	while (scanf("%s%s", s1+1, s2+1) > 0)
	{
		int len1=strlen(s1+1), len2=strlen(s2+1);
		memset(LCS, 0, sizeof(LCS));
	
		for (int i=1; i<=len1; ++i)
			for (int j=1; j<=len2; ++j)
				if (s1[i] == s2[j])
					LCS[i][j] = LCS[i-1][j-1] + 1;
				else
					LCS[i][j] = (LCS[i][j-1] > LCS[i-1][j]) ? LCS[i][j-1] : LCS[i-1][j];

		printf("%d\n", LCS[len1][len2]);
	}
	
	return 0;
}
```

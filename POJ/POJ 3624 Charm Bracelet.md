|题目名|*Charm Bracelet*|  
|---|---|  
|**题源**|USACO 2007 December Silver: Charm Bracelet|  
|**OJ**|[POJ 3624](http://poj.org/problem?id=3624)([vjudge](https://vjudge.net/problem/POJ-3624)), [洛谷 P2871](https://www.luogu.org/problemnew/show/P2871)|  
|**标签**|动态规划，背包|  
|**难度**|普及组简单题|  

#### 题目
#### 分析 
#### 答案
```cpp
/*
    USACO 2007 December Silver: Charm Bracelet
    POJ 3624
    Luogu P2871
    Author: Dubos

    《算法基础与在线实践》P146例题7.5

    “可以先考虑处理第N种物品，看看处理过后，剩下的问题是否和原问题相同且规模变小，
    这样也许就能形成递推。”
*/

#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX_N = 10 + 3402;
const int MAX_W = 10 + 12880; 
int W [MAX_N], D [MAX_N];	//W[i]为第i件物品的重量，D[i]为第i件物品的价值 
int dp [MAX_W];	//dp[i][j]为选至（含）第i件物品、总体积不超过j时的最大价值，dp []为对应滚动数组

int main()
{
	//输入 
	int N, M;
	scanf("%d%d", &N, &M);
	for (int i=1; i<=N; ++i)
		scanf("%d%d", &W[i], &D[i]);

	//dp []初始化赋值，即先为第1个物品赋值dp [] 
	for (int j=0; j<=M; ++j)
		if (W[1] <= j)
			dp[j] = D[1];
		else
			dp[j] = 0;
	
	//递推与滚动数组：从第2个商品开始滚动至第N个 
	for (int i=2; i<=N; ++i)
		for (int j=M; j>=0; --j)
			if (j-W[i] >= 0)
				dp[j] = max(dp[j], dp[j-W[i]] + D[i]);
			 
	printf("%d", dp[M]);
		
	return 0;
}
```

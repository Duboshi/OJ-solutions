|题目名|*LIS*|  
|---|---|  
|**题源**||  
|**OJ**|[AtCoder 2827](https://chokudai_s001.contest.atcoder.jp/tasks/chokudai_S001_h)([vjudge](https://vjudge.net/problem/AtCoder-2827),[Luogu](https://www.luogu.org/problemnew/show/AT2827))|  
|**标签**|动态规划，二分查找|  
|**难度**|普及组中档题/提高组简单题|  

#### 题目
#### 分析 
#### 答案
```cpp
/* 
	AtCoder 2827 LIS
	
	POJ 2533中1 <= N <= 1000；
	AtCoder 2827中 1<= N <= 100 000;
	 
	《挑战程序设计竞赛》P65 
	本解法为O(nlogn)版本，适用于AtCoder 2827 
*/

#include <algorithm> 
#include <cstdio>

using namespace std;

const int INF = 0x3f3f3f3f;
const int MAX_N = 100010;
int n, temp, b[MAX_N], minEnd[MAX_N];
//b数组用于存储原数列，minEnd[i]表示所有长度为i的上升子序列中末尾元素值最小的那个值 

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; ++i)
		scanf("%d", &b[i]);
	
	//minEnd[1] ~ minEnd[n]初始化赋值为INF
	fill(minEnd+1, minEnd+n+1, INF);
	
	//对于每个b[i]，都在minEnd[1] ~ minEnd[n]中查找首个大于等于b[i]的元素，并将其重新赋值为b[i]；
	//这样做会使minEnd[i]表示所有长度为i的上升子序列中末尾元素值最小的那个值； 
	//并使minEnd中除了INF之外的元素将会是升序的；
	//使用二分查找是本解法复杂度为O(nlogn)的原因。
	for (int i=1; i<=n; ++i)
		*lower_bound(minEnd+1, minEnd+n+1, b[i]) = b[i];
	
	//minEnd数组中数值小于INF的最大元素的序号，就是LIS长度
	int ans = lower_bound(minEnd+1, minEnd+n+1, INF) - (minEnd+1);
	printf("%d", ans); 
			
	return 0;
}
```

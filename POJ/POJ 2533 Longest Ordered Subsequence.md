|题目名|*Longest Ordered Subsequence*|  
|---|---|  
|**题源**|Northeastern Europe 2002, Far-Eastern Subregion|  
|**OJ**|[POJ 2533](http://poj.org/problem?id=2533)([vjudge](https://vjudge.net/problem/POJ-2533))|  
|**标签**|动态规划，二分查找|  
|**难度**|普及组中档题/提高组简单题|  

#### 题目
#### 分析 
本题需要会使用O(n^2)和O(nlogn)两种解法来做
#### 答案
1. O(n^2)解法  
	```cpp
	/*
		POJ 2533 Longest Ordered Subsequence

		POJ 2533中1 <= N <= 1000；
		AtCoder 2827中 1<= N <= 100 000;

		《算法基础与在线实践》P141
		本解法为O(n^2)版本，不适用于AtCoder 2827那么大的数据范围 
	*/ 

	#include <cstdio> 

	using namespace std;

	const int MAX_N = 100010;
	int n, temp, b[MAX_N], maxLen[MAX_N];
	//b数组用于存储原数列，maxLen[i]表示以b[i]为结尾的局部LIS长度

	int main()
	{
		scanf("%d", &n);
		for (int i=1; i<=n; ++i)
			scanf("%d", &b[i]);

		//为maxLen[]的n个元素赋值，即以b[i]为结尾的各个“局部”LIS的长度
		maxLen[1] = 1;
		for (int i=2; i<=n; ++i)
		{
			for (int j=1; j<i; ++j)
			{
				temp = 1;
				if (b[j]<b[i] && temp < maxLen[j])
					temp = maxLen[j];
			}

			if (temp!=1) maxLen[i] = temp+1;
			else maxLen[i] = 1;
			//printf("maxLen[%d] = %d\n", i, maxLen[i]);
		}

		int ans = 0;
		for (int i=1; i<=n; ++i)
			if (ans<maxLen[i])
				ans = maxLen[i];

		printf("%d", ans);

		return 0;
	}
	```

2. O(nlogn)解法  
	```cpp
	/* 
	POJ 2533 Longest Ordered Subsequence
	
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

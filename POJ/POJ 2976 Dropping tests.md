|题目名|*POJ 2976 Dropping tests*|  
|---|---|  
|**题源**|Stanford Local 2005|  
|**OJ**|[POJ 2976](http://poj.org/problem?id=2976)([vjudge](https://vjudge.net/problem/POJ-2976))|  
|**标签**|二分，贪心|  
|**难度**|普及组简单题，或普及组中档题/提高组简单题|  

#### 题目
#### 分析 
#### 答案
```cpp
/*
	POJ 2976 Dropping tests
	《挑战程序设计竞赛》 P143（最大化平均值）书后习题
	@author dubos
*/

#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX_N = 1010;
int n, k, i, a[MAX_N], b[MAX_N];
double upper, lower, mid, c[MAX_N], sum; //c[i]用于存储a[i] - x*b[i]值

//检验drop k tests之后剩余的(n-k)次测试，也是正确率最高的(n-k)次测试，
//能否达到均值为x的正确率，即(a[n-1]-x*b[n-1])+...+(a[k]-x*b[k]) >= 0
bool check(double x)
{
	for (i=0; i<n; ++i)
		c[i] = a[i] - x*b[i];
	sort(c, c+n);
		
	sum = 0;
	for (i=n-1; i>=k; --i)
		sum += c[i];
		
	return sum>=0;
}

int main ()
{
	scanf("%d%d", &n, &k);
	while (n!=0)
	{
		for (i=0; i<n; ++i)
			scanf("%d", &a[i]);
		for (i=0; i<n; ++i)
			scanf("%d", &b[i]);

		upper = 1;
		lower = 0;
		for (int i=0; i<100; ++i)
		{
			mid = (upper+lower) / 2;
			if (check(mid))
				lower = mid;
			else
				upper = mid;
		}
		printf("%.0f\n", mid*100);
		scanf("%d%d", &n, &k);
	}
	
	return 0;	
}
```

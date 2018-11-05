|题目名|*POJ 1163 The Triangle*|  
|---|---|  
|**题源**|IOI 1994|  
|**OJ**|[POJ 1163](http://poj.org/problem?id=1163)([vjudge](https://vjudge.net/problem/POJ-1163)), [Luogu P1216](https://www.luogu.org/problem/show?pid=P1216), [百练 1163](http://bailian.openjudge.cn/practice/1163/)|  
|**标签**|动态规划|  
|**难度**|普及组简单题|  

#### 题目
#### 分析 
#### 答案
* 记忆化搜索
```cpp
/* 	
@author 杜博识Dubos dubos@foxmail.com

	POJ 1163 The Triangle数字三角形
	
	《算法基础与在线实践》 P134 
	
	解法思路：
	tri[i][j]用于记录数字三角形中第i行第j列的元素； 
	sum[i][j]记录从tri[i][j]最下面一行的最佳路径和，sum[i][j] = max(sum[i+1][j]+tri[i][j], sum[i+1][j+1]+tri[i][j])；
	但如果单纯用递归，会因为重复计算产生O(2^N)时间复杂度，所以我们建立了sum[i][j]数组来存储每次计算的结果，从而将复杂度降至O(N^2)，
		这种做法被称为【记忆化搜索】；
	本题目标是求sum[1][1]。
*/

#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX_N = 102;
int N, tri[MAX_N][MAX_N], sum[MAX_N][MAX_N];

int main() {
	scanf("%d", &N);
	for (int i=1; i<=N; ++i)
		for (int j=1; j<=i; ++j)
			scanf("%d", &tri[i][j]);
		
	for (int j=1; j<=N; ++j)
		sum[N][j] = tri[N][j];
	
	for (int i=N-1; i>=1; --i)
		for (int j=1; j<=i; ++j)
			if (sum[i+1][j]<sum[i+1][j+1])
				sum[i][j] = sum[i+1][j+1] + tri[i][j];
			else
				sum[i][j] = sum[i+1][j] + tri[i][j];
	
	printf("%d", sum[1][1]);
	return 0;
}

```

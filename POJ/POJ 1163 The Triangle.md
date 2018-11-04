|题目名|POJ 1163 The Triangle|  
|---|---|  
|**题源**||  
|**OJ**|[]()|  
|**标签**||  
|**难度**||  

#### 题目
#### 分析 
#### 答案
```cpp
/* 	
@author 杜博识Dubos dubos@foxmail.com
/*	
	POJ 1163 The Triangle数字三角形
	
	《算法基础与在线实践》 P134 
	
	递归解法思路：
	tri[i][j]用于记录数字三角形中第i行第j列的元素； 
	sum[i][j]记录从tri[i][j]最下面一行的最佳路径和；
	sum[i][j] = max(sum[i+1][j]+tri[i][j], sum[i+1][j+1]+tri[i][j])；
	本题求sum[1][1]。
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

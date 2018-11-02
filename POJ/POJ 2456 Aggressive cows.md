|题目名|《Aggressive cows 》|  
|---|---|  
|**题源**|USACO 2005 February Gold|  
|**OJ**|[POJ 2456](http://poj.org/problem?id=2456), [白练](http://bailian.openjudge.cn/practice/2456/), [vjudge](https://vjudge.net/problem/POJ-2456)|  
|**标签**|二分，最大化最小值|  
|**难度**|普及组中档题/提高组简单题|  

#### 题目
#### 分析 
#### 答案
```cpp
//POJ 2456 Aggressive cows（最大化最小值）
//《挑战程序设计竞赛》 P143 

#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX_N = 100000;
int N, C, x[MAX_N]; //N个牛舍，M头牛

//判断整数d是否符合条件：任意两牛之间的间距都不小于d 
bool check (int N, int C, int d) {
	//pre是前一头牛的牛舍序号，把第一头牛放入x[0]的牛舍，所以pre初始值为0 
	int pre=0;
	
	//之后，如果第i头牛放入了牛舍x[pre]的话, 第i+1头牛就要放入满足x[crt]-x[pre] >= d的最小x[crt]中
	//对剩余M-1头牛以此进行判断，看能否安置在满足上述条件的牛舍中 
	for (int i=1; i<=C-1; ++i) {
		int crt = pre+1;	//crt用于记录当前这头牛被放置的牛舍序号，至少是pre+1
		
		//因为要找满足x[crt]-x[pre] >= d的最小x[crt]，所以只要x[crt]-x[pre] < d就crt++看下一个牛舍 
		while (crt<N && x[crt]-x[pre]<d) {
			crt++;
		}
		
		//一旦满足x[crt]-x[pre] >= d或者crt >= N就停下来，这是加入crt == N，说明牛舍不够用，因为牛舍
		//只有x[0] ~ x[N-1]这么多，所以return false 
		if (crt==N)
			return false;
		
		//对这头牛的判断完毕，将pre赋值为crt，以便下一头牛判断 
		pre = crt;
	}
	
	//如果前面一直都没return false，就return true 
	return true;
}

int main() {
	//输入，将N个牛舍的位置记录在x[0] ~ x[N-1]中，然后对牛舍位置x进行排序 
	scanf("%d%d", &N, &C);
	for (int i=0; i<N; ++i)
		scanf("%d\n", &x[i]);
	sort(x, x+N);
	
	//间距下限是0，上限是x[N-1]-x[0]，我们在上下限之间寻找一个合适的答案。
	//为了下面二分查找时条件为upper-lower>1，取upper = x[N-1]-x[0]+1，否则x[N-1]-x[0]有可能为1，无法大于1 
	int lower = 0, upper = x[N-1]-x[0]+1;
	
	//二分查找，如果upper-lower=1就停下来，这时候的lower值就是答案 
	while (upper-lower>1) {
		int mid = (upper+lower)/2;
		
		//如果中间值mid满足条件，则查找比mid更大的值，lower=mid
		//如果中间值mid不满足条件，则查找比mid更小的值，upper=mid 
		if (check(N, C, mid))
			lower=mid;
		else
			upper=mid;
	}
	
	//lower是答案，输出 
	printf("%d", lower);
}
```

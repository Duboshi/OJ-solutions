|题目名|*Common Subsequence*|  
|---|---|  
|**题源**||  
|**OJ**|[UVa 10405]()([vjudge](https://vjudge.net/problem/UVA-10405))|  
|**标签**|字符串，动态规划，LCS|  
|**难度**|普及组简单题|  

#### 题目
#### 分析 
#### 答案
```cpp
/* 	
/*
    UVA 10405 Common Subsequence
    Author: Dubos

    POJ 1458没说两个字符串的长度；
    UVA 10405条件是长度不超过1000，这道题尤其要注意输入不能用scanf，因为它遇见空格会停；
    Luogu P1439条件是长度不超过100000。 
    
    《算法基础与在线实践》P143
    这题我想了半天用滚动数组，发现过程比较复杂，而且滚动数组对n=1000000也没什么用，
    所以就不滚了。
*/

#include <cstdio>
#include <iostream>
#include <cstring>
#define MAX_N 10+1000
using namespace std;

char a[MAX_N], b[MAX_N];
int LCS[MAX_N][MAX_N];

int main()
{

    while(cin.getline(a+1, MAX_N) && cin.getline(b+1, MAX_N))
//	while (scanf("%s%s", s1+1, s2+1) > 0)不行，因为scanf遇见空格就停止了 
    {
        int len1=strlen(a+1), len2=strlen(b+1);
        memset(LCS, 0, sizeof(LCS));
    
        for (int i=1; i<=len1; ++i)
            for (int j=1; j<=len2; ++j)
                if (a[i] == b[j])
                    LCS[i][j] = LCS[i-1][j-1] + 1;
                else
                    LCS[i][j] = (LCS[i][j-1] > LCS[i-1][j]) ? LCS[i][j-1] : LCS[i-1][j];

        printf("%d\n", LCS[len1][len2]);
    }
    
    return 0;
}
```

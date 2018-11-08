|题目名|*POJ 1328 Radar Installation*|  
|---|---|  
|**题源**|Beijing 2002|  
|**OJ**|[POJ 1328]()([vjudge](https://vjudge.net/problem/POJ-1328)), [UVa 1193](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3634)([vjudge](https://vjudge.net/problem/UVA-1193))|  
|**标签**|贪心|  
|**难度**||  

#### 题目
#### 分析 
本题可以转化为贪心经典问题中的“区间选点问题”，详见《算法竞赛入门经典》P232-233. 区间相关问题的两个关键是**区间包含**和**排序扫描**。本题中的线段无论是按照左端点还是右端点排序都是可以的，详见下文代码。
#### 答案
1. 左端点排序解法  
  ```cpp
  /*
    POJ 1328 Radar Installation
    UVa 1193 Radar Installation

    与下述题目仅有输入输出格式的差别：
    Luogu P1325 雷达安装 

    基于《算法基础与在线实践》P114题解改写（按照线段的左端点排序） 
    @author Dubos
  */

  #include <cstdio>
  #include <iostream>
  #include <algorithm>
  #include <cmath>
  using namespace std;

  //线段两端
  struct Node
  {
    double left, right;
  };

  int n, d; //n是小岛数量，d是雷达覆盖半径
  const int MAX_N = 1010;
  Node s [MAX_N]; //小岛数组，最多1000个小岛

  //其实无论是比较左侧还是右侧端点都可以（当然之后的贪心策略有所不同） 
  //我先写一个按照左侧端点排序的版本，再写一个按照右侧端点排序的版本 

  //比较左侧端点 
  bool operator < (const Node &a, const Node &b)
  {
    return a.left < b.left;
  }

  int Solve()
  {	
    //将所有小岛形成的线段按左端点排序
    sort(s, s+n);

    int ans = 1;				//ans是Solve的函数结果，即所需雷达数量
    double now = s[0].right;	//now用于记录排序扫描进行到的位置，最初在s[0]右端点 

    //对s[0]后续的(n-1)个小岛遍历，贪心策略如下： 
    for (int i=1; i<n; ++i)
    {
      //若下一个线段与（now所在的）当前线段有交集，则无需加入新雷达
      //注意：如果下一个线段被当前线段完全包含，则将now的位置移至下一个线段右端点 
      if(s[i].left <= now) 
        now = min(now, s[i].right);

      //若下一个线段与当前线段没有交集，则需新加入一个雷达，并将now移至下一个线段右端点 
      else
      {
        ++ans;
        now = s[i].right;
      }
    }
    return ans;
  }

  int main()
  {
    int x, y;		//坐标 
    bool solvable;	//题目是否可解（如果有小岛距离海岸线太远，无法覆盖，就不可解） 
    int cse = 0;	//输入case的数量（case是关键词，不能用作变量名） 

    scanf("%d%d", &n, &d);
    while (n!=0 && d!=0)
    {
      ++cse;

      solvable = true;
      for (int i=0; i<n; ++i)
      {
        scanf("%d%d", &x, &y);
        if (y>d)
          solvable = false;	//有小岛距离海岸线太远，无法被覆盖
        else
        {
          s[i].left = x - sqrt(d*d - y*y);
          s[i].right = x + sqrt(d*d - y*y);
        }
      }

      if(solvable)
        printf("Case %d: %d\n", cse, Solve());
      else
        printf("Case %d: -1\n", cse);

      scanf("%d%d", &n, &d);
    } 
  }		
  ```  
2. 右端点排序解法  
   ```cpp
 /*
（按照线段的右端点排序） 
	@author Dubos
*/

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

//线段两端
struct Node
{
	double left, right;
};

int n, d; //n是小岛数量，d是雷达覆盖半径
const int MAX_N = 1010;
Node s [MAX_N]; //小岛数组，最多1000个小岛

//其实无论是比较左侧还是右侧端点都可以（当然之后的贪心策略有所不同）
//这里要写一个按照右侧端点排序的版本

//比较右侧端点 
bool operator < (const Node &a, const Node &b)
{
	return a.right < b.right;
}

int Solve()
{	
	//将所有小岛形成的线段按右端点排序
	sort(s, s+n);
	
	int ans = 1;				//ans是Solve的函数结果，即所需雷达数量
	double now = s[0].right;	//now用于记录排序扫描进行到的位置，最初在s[0]右端点 
	
	//对s[0]后续的(n-1)个小岛遍历，贪心策略如下： 
	for (int i=1; i<n; ++i)
	{
		//若下一个线段与（now所在的）当前线段有交集，则无需加入新雷达
		//注意：如果下一个线段完全包含当前线段，则不改变now的位置，相当于忽略下一个线段 
		if(s[i].left <= now) 
			now = min(now, s[i].right);
			
		//若下一个线段与当前线段没有交集，则需新加入一个雷达，并将now移至下一个线段右端点 
		else
		{
			++ans;
			now = s[i].right;
		}
	}
	return ans;
}

int main()
{
	int x, y;		//坐标 
	bool solvable;	//题目是否可解（如果有小岛距离海岸线太远，无法覆盖，就不可解） 
	int cse = 0;	//输入case的数量（case是关键词，不能用作变量名） 
	
	scanf("%d%d", &n, &d);
	while (n!=0 && d!=0)
	{
		++cse;
	
		solvable = true;
		for (int i=0; i<n; ++i)
		{
			scanf("%d%d", &x, &y);
			if (y>d)
				solvable = false;	//有小岛距离海岸线太远，无法被覆盖
			else
			{
				s[i].left = x - sqrt(d*d - y*y);
				s[i].right = x + sqrt(d*d - y*y);
			}
		}
		
		if(solvable)
			printf("Case %d: %d\n", cse, Solve());
		else
			printf("Case %d: -1\n", cse);
	
		scanf("%d%d", &n, &d);
	}
}
   ```

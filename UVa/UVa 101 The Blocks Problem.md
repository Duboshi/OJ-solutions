|题目名|*The Blocks Problem*|  
|---|---|  
|**题源**|UVa 101|  
|**OJ**|[UVa 101](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=3&page=show_problem&problem=37)|  
|**标签**|向量|  
|**难度**|普及组简单题|  

#### 题目  
题面简译：  
> 计算机科学中的很多领域都使用简单的对象进行研究，例如人工智能规划和机器人领域就曾使用机器手臂来搬木块。在这道题你要建立一个有指令和条件限制的木块环境，并且让机器手臂按照特定的指令行事。  
初始化条件是n个木块摆在桌子上，序号是0、1、2、...、n-1，按顺序排列（原题有示意图）。可供执行的命令有5个：

>> move a onto b  
>>> 咋回事儿  

>> move a over b  
>>> 咋回事儿  

>> pile a onto b  
>>> 咋回事儿  

>> pile a over b  
>>> 咋回事儿  

>> quit  
>>> 咋回事儿  


#### 分析  
* 本题是模拟题，难度较低，只要顺着main函数的执行顺序看各个注释即可  

#### 答案  
```cpp
/* 	
@author 杜博识Dubos dubos@foxmail.com
UVa 101 The Blocks Problem 
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n, i;
vector <int> pile [25];
//0 ~ n-1每个位置都是一个pile [25]，可以放最多 0<n<25 个木块
//而这样的pile有n个，n值不确定，所以用向量，向量的元素是pile 
																				//？？？为什么不用二维向量呢
void find_block(int a, int &p, int &h);
void clear_above(int p, int h);
void pile_onto(int pa, int h, int pb);
void print(); 

int main()
{		
	int a, b;
	string s1, s2;
	//a和b是题目要求的两个木块编号
	//s1将会被赋值"move"、"pile"或者"quit"，s2将会被赋值"onto"或者"over"
	cin>>n;
	
	//先把各个木块放入初始位置
	for (i=0; i<n; ++i)
		pile[i].push_back(i);
	
	//按照指令和题意进行模拟 
	while (cin>>s1 && s1!="quit")
	{
		cin >>a >>s2 >>b;
		int pa, pb, ha, hb;
		//pa, pb记录a和b所在的pile，ha和hb记录a和b在各自pile中的高度height 
		 
		find_block(a, pa, ha);
		find_block(b, pb, hb);
		//找到木块a所在的pile和height，由于pa和ha是find_block函数的引用参数，
		//所以调用find_block之后会改变pa和ha的值。对b同理。 
		
		//Any command in which a = b or in which a and b are in the same stack 
		//of blocks is an illegal command. All illegal commands should be ignored.
		if (a==b || pa==pb)
			continue;
		
		//如果输入move a onto b或者move a over b，就要把a头上的木块全放回初始位 
		if (s1=="move")
			clear_above(pa, ha);
			
		//如果输入move a onto b或者pile a onto b，就要把b头上的木块全放回初始位 
		if (s2=="onto")
			clear_above(pb, hb);
			
		//无论如何，然后把a及其头上的木块（如果还有的话）放到b所在的pile上去 
		pile_onto(pa, ha, pb);
	}
	
	print();
	return 0;
}

//寻找木块a和b所在的pile和height 
//int &p和int &h引用参数可以为调用函数的实际变量赋值，见第37-38行 
void find_block(int a, int &p, int &h) 
{
	for (p=0; p<n; ++p)
		for (h=0; h<pile[p].size(); ++h)
			if (pile[p][h]==a)
				return; 
}

//将序号为p的pile中高度为h以上的木块都放回各自初始位置 
void clear_above(int p, int h)
{
	for (i=h+1; i<pile[p].size(); ++i)
	{
		int temp = pile[p][i];
		pile[temp].push_back(temp);
	}
	pile[p].resize(h+1);	//p只保留0 ~ h一共h+1个木块 
}

//把序号为pa的pile中高度h及以上的木块一起搬到序号为pb的pile顶部 
void pile_onto(int pa, int h, int pb)
{
	for (i=h; i<pile[pa].size(); ++i)
		pile[pb].push_back(pile[pa][i]);
	pile[pa].resize(h);	//pa只保留0 ~ h-1一共h个木块 
}

void print()
{
	int p, h;
	for (p=0; p<n; ++p)
	{
		cout <<p <<":";
		for (h=0; h<pile[p].size(); ++h)
			cout <<" " <<pile[p][h];
		cout <<endl;
	}
}
```

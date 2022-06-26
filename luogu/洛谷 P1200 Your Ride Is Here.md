|题目名|Your ride is here|  
|---|---|  
|**题源**|USACO Training 1.1|  
|**OJ**|[洛谷 P1200](https://www.luogu.org/problemnew/show/P1200)|  
|**标签**|字符串|  
|**难度**|普及组简单题|  

#### 分析 
* 本题用于学习输入输出，以及字符串的储存和读取。'答案一'和'答案二'比较常见，'答案三'相对次要。
#### 答案一

```cpp
/*
	Luogu P1200 Your ride is here
	Author: Dubos
*/

#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    string comet, team;
    int cm=1, tm=1;
	cin >> comet >> team;
    
    for(int i=0; i<comet.length(); i++)
        cm *= comet[i] - 'A' + 1;
    for(int i=0; i<team.length(); i++)
        tm *= team[i] - 'A' + 1;
    
    if(cm%47 == tm%47)
        cout << "GO";
    else
        cout << "STAY";

	return 0;
}

```
#### 答案二

```cpp
/*
	Luogu P1200 Your ride is here
	Author: Dubos
*/

#include <cstdio>
using namespace std;

int main()
{
    int cm=1, tm=1;
    char comet[7], team[7];
    scanf("%s\n %s", &comet, &team);
    
    for(int i=0; comet[i]!='\0'; i++)
            cm *= comet[i] - 'A' + 1;
    for(int i=0; team[i] != '\0'; i++)
            tm *= team[i] - 'A' + 1;
    
    if(cm%47 == tm%47)
        printf("GO");
    else
        printf("STAY");

	return 0;
}
```
#### 答案三

```cpp
/*
	Luogu P1200 Your ride is here
	Author: Dubos
*/

#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    int cm=1, tm=1;
    
    char c = getchar();
    while(c!='\n') {
        cm *= c - 'A' + 1;
        c = getchar();
    }
    
    c = getchar();  
    while(c!='\n') {
        tm *= c - 'A' + 1;
        c = getchar();
    }
    
    if(cm%47 == tm%47)
        cout << "GO";
    else
        cout << "STAY";

	return 0;
}
```

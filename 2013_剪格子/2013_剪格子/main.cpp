//
//  main.cpp
//  2013_剪格子
//
//  Created by VachelChen on 2020/2/2.
//  Copyright © 2020 VachelChen. All rights reserved.
//
//
//标题：剪格子
//
//    如图p1.jpg所示，3 x 3 的格子中填写了一些整数。
//
//    我们沿着图中的红色线剪开，得到两个部分，每个部分的数字和都是60。
//
//    本题的要求就是请你编程判定：对给定的m x n 的格子中的整数，是否可以分割为两个部分，使得这两个区域的数字和相等。
//    如果存在多种解答，请输出包含左上角格子的那个区域包含的格子的最小数目。
//    如果无法分割，则输出 0
//
//程序输入输出格式要求：
//程序先读入两个整数 m n 用空格分割 (m,n<10)
//表示表格的宽度和高度
//接下来是n行，每行m个正整数，用空格分开。每个整数不大于10000
//程序输出：在所有解中，包含左上角的分割区可能包含的最小的格子数目。
//
//
//例如：
//用户输入：
//3 3
//10 1 52
//20 30 1
//1 2 3
//
//则程序输出：
//3
//
//再例如：
//用户输入：
//4 3
//1 1 1 1
//1 30 80 2
//1 1 1 100
//
//则程序输出：
//10
//
//(参见p2.jpg)
//
//
//资源约定：
//峰值内存消耗 < 64M
//CPU消耗  < 5000ms
//
//
//请严格按要求输出，不要画蛇添足地打印类似：“请您输入...” 的多余内容。
//
//所有代码放在同一个源文件中，调试通过后，拷贝提交该源码。
//
//注意: main函数需要返回0
//注意: 只使用ANSI C/ANSI C++ 标准，不要调用依赖于编译环境或操作系统的特殊函数。
//注意: 所有依赖的函数必须明确地在源文件中 #include <xxx>， 不能通过工程设置而省略常用头文件。
//
//提交时，注意选择所期望的编译器类型。

  


#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
int a[10][10];
int visit[10][10]={0};
int total=0;
bool flag=false;
int ans[100];
int ansindex = 0;

void dfs(int x,int y,int value,int kuai){
    visit[x][y]=1;
    value=value+a[x][y];
    //cout<<a[x][y]<<"\t value:"<<value<<endl;
    if(value == total/2){
        ans[ansindex++] = kuai;
        flag = true;
    }
    if(x<n-1 && value+a[x+1][y]<=total/2 && !visit[x+1][y])      dfs(x+1,y,value,kuai+1);
    if(y<m-1 && value+a[x][y+1]<=total/2 && !visit[x][y+1])      dfs(x,y+1,value,kuai+1);
    if(y>0   && value+a[x][y-1]<=total/2 && !visit[x][y-1])      dfs(x,y-1,value,kuai+1);
    if(x>0   && value+a[x-1][y]<=total/2 && !visit[x-1][y])      dfs(x-1,y,value,kuai+1);
    visit[x][y]=0;
}

int main(int argc, const char * argv[]) {

    cin>>m>>n;
    
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            cin>>a[i][j];
            total = total+a[i][j];
        }
    dfs(0, 0, 0, 1);
    sort(ans, ans+ansindex);
    if(!flag)    cout<<"0"<<endl;
    else         cout<<ans[0]<<endl;
    return 0;
}

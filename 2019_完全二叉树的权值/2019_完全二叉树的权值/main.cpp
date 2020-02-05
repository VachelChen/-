//
//  main.cpp
//  2019_完全二叉树的权值
//
//  Created by VachelChen on 2020/2/4.
//  Copyright © 2020 VachelChen. All rights reserved.
//

/*
试题F: 完全二叉树的权值
第十届蓝桥杯大赛软件类省赛C/C++大学A组
试题F: 完全二叉树的权值
时间限制: 1.0s 内存限制: 256.0MB 本题总分：15 分
【问题描述】
给定一棵包含N 个节点的完全二叉树，树上每个节点都有一个权值，按从
上到下、从左到右的顺序依次是A1, A2, …AN，如下图所示：
现在小明要把相同深度的节点的权值加在一起，他想知道哪个深度的节点
权值之和最大？如果有多个深度的权值和同为最大，请你输出其中最小的深度。
注：根的深度是1。
【输入格式】
第一行包含一个整数N。
第二行包含N 个整数A1, A2, … AN 。
【输出格式】
输出一个整数代表答案。
【样例输入】
7
1 6 5 4 3 2 1
【样例输出】
2
【评测用例规模与约定】
对于所有评测用例，1 <= N <=100000，-100000<= Ai<=100000。
*/

#include <iostream>
#include <queue>
#include <map>
#include <cmath>
using namespace std;

struct tree{
    int id;
    int value;
    int left,right;
    int parent;
}t[100001];

int n;
queue <tree>  q;
map <int,int> m;

void bfs(){
    int deep=1;
    q.push(t[1]);
    while(!q.empty()){
        tree temp = q.front();  q.pop();
        
        //cout<<deep<<" "<<pow(2.0, deep*1.0)-1<<" "<<temp.id<<" "<< (pow(2.0, deep*1.0)-1<temp.id) <<endl;
        if(pow(2.0, deep*1.0)-1<temp.id)
            deep++;
        
        m[deep]+=temp.value;
        
        if(temp.left)   q.push(t[temp.left]) ;
        if(temp.right)  q.push(t[temp.right]);
    }
}

int main(int argc, const char * argv[]) {

    cin >> n;
    for(int i = 1;i <= n;i++){
        t[i].id = i;
        cin>>t[i].value;
        if(i == 1)
            t[i].parent = 0;
        else
            t[i].parent = i/2;
        
        if(i*2 <= n)
            t[i].left = i*2;
        else
            t[i].left = 0;
        
        if(i*2+1 <= n)
            t[i].right = i*2+1;
        else
            t[i].right = 0;
    }
    
    bfs();
    
    
    
    int quanmax=0;
    for(int i=1;i<=log2(n+1);i++){
        quanmax=max(m[i],quanmax);
    }
    
    for(int i=1;pow(2.0, i*1.0)-1<=n;i++){
        if(m[i] == quanmax){
            cout<<i<<endl;
            break;
        }
    }
    
    return 0;
}

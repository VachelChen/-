//
//  main.cpp
//  2019_外面店优先级
//
//  Created by VachelChen on 2020/2/5.
//  Copyright © 2020 VachelChen. All rights reserved.
//
/*
 试题G: 外卖店优先级
 时间限制: 1.0s 内存限制: 256.0MB 本题总分：20 分
 【问题描述】
 “饱了么”外卖系统中维护着N 家外卖店，编号1 ~ N。每家外卖店都有
 一个优先级，初始时(0 时刻) 优先级都为0。
 每经过1 个时间单位，如果外卖店没有订单，则优先级会减少1，最低减
 到0；而如果外卖店有订单，则优先级不减反加，每有一单优先级加2。
 如果某家外卖店某时刻优先级大于5，则会被系统加入优先缓存中；如果
 优先级小于等于3，则会被清除出优先缓存。
 给定T 时刻以内的M 条订单信息，请你计算T 时刻时有多少外卖店在优
 先缓存中。
 【输入格式】
 第一行包含3 个整数N、M 和T。
 以下M 行每行包含两个整数ts 和id，表示ts 时刻编号id 的外卖店收到
 一个订单。
 【输出格式】
 输出一个整数代表答案。
 【样例输入】
 2 6 6
 1 1
 5 2
 3 1
 6 2
 2 1
 6 2
 【样例输出】
 1
 【样例解释】
 6 时刻时，1 号店优先级降到3，被移除出优先缓存；2 号店优先级升到6，
 加入优先缓存。所以是有1 家店(2 号) 在优先缓存中。
 【评测用例规模与约定】
 对于80% 的评测用例，1 <= N; M; T <=10000。
 对于所有评测用例，1 <=N; M; T <=100000，1 <=ts <=T，1 <=id <=N。
 */

#include <iostream>
#include <cstring>
#include <sstream>
using namespace std;

string dingdan[10001];
int yxj[10001];

string i2s(int x,string str){
    stringstream ss;
    ss << x;
    ss >> str;
    return str;
}

int main(int argc, const char * argv[]) {
    int n,m,t;
    cin>>n; cin>>m; cin>>t;
    for(int i=0;i<m;i++){
        int x;
        string y;
        cin>>x; cin>>y;
        dingdan[x].append(y);
    }
    
    memset(yxj,0,sizeof(yxj));
    int ram=0;
    
    for(int i=1;i<=t;i++){
        for (int j=1; j<=n; j++) {
            string str;
            if(dingdan[i].find(i2s(j,str))!=string::npos){
                yxj[j]+=2;
                if(yxj[j] > 5){
                    ram++;
                }
            }
            else{
                if(yxj[j] == 3){
                    ram--;
                }
                yxj[j]=(yxj[j]>0?yxj[j]-1:0);
            }
        }
    }
    
    cout<<ram<<endl;
    
    return 0;
}

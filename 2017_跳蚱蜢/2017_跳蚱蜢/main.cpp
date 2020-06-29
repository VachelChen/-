//
//  main.cpp
//  2017_跳蚱蜢
//
//  Created by VachelChen on 2020/2/24.
//  Copyright © 2020 VachelChen. All rights reserved.
//
#include <iostream>
#include <queue>
using namespace std;
 
int d[4]={-2,-1,1,2};
 
int state[9];
int zp;//空盘位置
int visited[876543211]={0};
 
queue<int> q;
queue<int> cnt;
 
void setState(int num){
    for(int i=8;i>=0;i--){
        if(num%10==0)
            zp=i;
        state[i]=num%10;
        num/=10;
    }
}
 
int getVal(){
    int num=0;
    for(int i=0;i<9;i++)
        num=num*10+state[i];
    return num;
}
 
bool extend(){
    int num=q.front();
    if(num==87654321){
        return false;
    }
    if(visited[num])
        return true;
    visited[num]=true;
    setState(num);
    for(int i=0;i<4;i++){
        state[zp]=state[(zp+d[i]+9)%9];
        state[(zp+d[i]+9)%9]=0;
        q.push(getVal());
        cnt.push(cnt.front()+1);
        setState(num);
    }
    return true;
}
 
int main(){
    setState(12345678);
    q.push(12345678);
    cnt.push(0);
    while(extend() && !cnt.empty()){
        q.pop();
        cnt.pop();
    }
    cout<<cnt.front()<<endl;
    return 0;
}


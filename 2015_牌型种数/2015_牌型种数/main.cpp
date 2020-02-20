//
//  main.cpp
//  2015_牌型种数
//
//  Created by VachelChen on 2020/2/20.
//  Copyright © 2020 VachelChen. All rights reserved.
//


/*
 小明被劫持到X赌城，被迫与其他3人玩牌。
 一副扑克牌（去掉大小王牌，共52张），均匀发给4个人，每个人13张。
 这时，小明脑子里突然冒出一个问题：
 如果不考虑花色，只考虑点数，也不考虑自己得到的牌的先后顺序，自己手里能拿到的初始牌型组合一共有多少种呢？
 */

//模拟
#include <iostream>
using namespace std;

int ans=0;

void dfs(int cur,int all){
    if(cur>13 || all>13)    return ;
    if(all == 13)   {
        ans++;
        return ;
    }
    
    for(int i=0;i<5;i++){
        dfs(cur+1,all+i);
    }
}

int main(int argc, const char * argv[]) {
    dfs(0,0);
    cout<<ans<<endl;
    return 0;
}

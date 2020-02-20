//
//  main.cpp
//  2015_垒骰子
//
//  Created by VachelChen on 2020/2/20.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

const long long MOD = 1000000007;
int repel[7][7];
int back[7];
int n,m;
long long ans=0;

long long fastPower(int a,int b){
    int subans = 1;
    while(b!=0){
        if((b & 1) == 1)
            subans = (subans*a)%MOD;
        b>>=1;
        a = (a * a)%MOD;
    }
    return subans;
}

void dfs(int up,int num){
    
    if(num == n)    {
        ans+=fastPower(4,n);
        return ;
    }
    
    for(int i=1;i<=6;i++){
        if(repel[up][i])
            continue;
        else
            dfs(back[i],num+1);
    }
        
}

int main(int argc, const char * argv[]) {
    cin>>n>>m;
    memset(repel,0,sizeof(repel));
    
    back[1] = 4;
    back[4] = 1;
    back[2] = 5;
    back[5] = 2;
    back[3] = 6;
    back[6] = 3;
    
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        repel[a][b] = 1;
        repel[b][a] = 1;
    }
    for(int i=1;i<=6;i++)
        dfs(i,1);
    
    cout<<ans<<endl;
    return 0;
}

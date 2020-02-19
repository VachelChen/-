//
//  main.cpp
//  2014_地宫夺宝
//
//  Created by VachelChen on 2020/2/18.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#include <cstring>

using namespace std;

long long cache[50][50][14][13];
int value[50][50];

int n,m,k;
const int MOD = 1000000007;

long long dfs(int x,int y,int maxValue,int num){
    
    if(cache[x][y][maxValue+1][num] != -1)   {
        return cache[x][y][maxValue+1][num];
    }
    
    if (x == n || y == m || num > k)    return 0;
    
    long long ans=0;
    
    if(x == n-1 && y == m-1 )  {
        if(num == k || (num == k-1 && maxValue<value[x][y])){
            ans++;
            if(ans>MOD)
                ans=ans%MOD;
        }
        return ans;
    }
    
    //cout<<maxValue<<" "<<value[x][y]<<endl;
    if(maxValue<value[x][y]){
        ans+=dfs(x+1, y, value[x][y], num+1);
        ans+=dfs(x, y+1, value[x][y], num+1);
    }
    ans+=dfs(x+1, y, maxValue, num);
    ans+=dfs(x, y+1, maxValue, num);
    
    cache[x][y][maxValue+1][num] = ans % MOD;
    return cache[x][y][maxValue+1][num];
}

int main(int argc, const char * argv[]) {
    
    cin>>n>>m>>k;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin>>value[i][j];
        }
    }
    memset(cache,-1,sizeof(cache));
    cout<<dfs(0,0,-1,0)<<endl;
    return 0;
}

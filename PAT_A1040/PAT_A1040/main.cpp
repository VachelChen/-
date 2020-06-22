//
//  main.cpp
//  PAT_A1040
//
//  Created by VachelChen on 2020/6/22.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;

int dp[1010][1010];

int main(int argc, const char * argv[]) {
    string x;
    getline(cin,x);
    int ans = 1;
    memset(dp, 0, sizeof(dp));
    
    //初始化dp,确定边界
    for (int i=0; i<x.size(); i++) {
        dp[i][i] = 1;
        if (i<x.size()-1 && x[i] == x[i+1]) {
            dp[i][i+1] = 1;
            ans = 2;
        }
    }
    
    //递归方程
    for (int i=3; i<=x.size(); i++) {
        for (int j=0; j+i-1<x.size(); j++) {
            int r = j + i -1;
            if (x[j] == x[r] && dp[j+1][r-1] == 1) {
                dp[j][r] = 1;
                ans = i;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}

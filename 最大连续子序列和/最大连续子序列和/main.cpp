//
//  main.cpp
//  最大连续子序列和
//
//  Created by VachelChen on 2020/5/5.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 10000;
int a[maxn];
int dp[maxn];

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    for (int i = 0 ; i < n; i++) {
        cin >> a[i];
    }
    
    //动态规划过程
    dp[0] = a[0];
    int ans = dp[0];
    
    for (int i = 1 ; i < n; i++) {
        dp[i] = dp[i-1] > 0?(dp[i-1]+a[i]):a[i];
        if(ans < dp[i])
            ans = dp[i];
    }
    cout<<ans<<endl;
    return 0;
}

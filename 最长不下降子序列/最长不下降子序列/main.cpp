//
//  main.cpp
//  最长不下降子序列
//
//  Created by VachelChen on 2020/5/5.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
using namespace std;

const int maxn = 1000;
int a[maxn];
int dp[maxn];

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    //动态规划
    int ans = 1;
    for (int i=0; i<n; i++) {
        dp[i] = 1;
        for (int j=0; j<i; j++) {
            if (a[i] >= a[j] && (dp[j] + 1 > dp[i])) {
                dp[i] = dp[j]+1;
            }
        }
        ans = max(ans,dp[i]);
    }
    cout<<ans<<endl;
    return 0;
}

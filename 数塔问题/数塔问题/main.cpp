//
//  main.cpp
//  数塔问题
//
//  Created by VachelChen on 2020/5/5.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
using namespace std;

const int maxn = 510;
int math[maxn][maxn];
int dp[maxn][maxn];
int n;

int main(int argc, const char * argv[]) {
    cin >> n;
    for (int i=0; i<n; i++) {
        for(int j=0; j<=i;j++){
            cin >> math[i][j];
        }
    }
    
    for (int j=0; j<n; j++) {
        dp[n-1][j] = math[n-1][j];
    }
    
    for (int i=n-2; i>=0; i--) {
        for(int j=0; j<=i;j++){
            dp[i][j] = max(dp[i+1][j],dp[i+1][j+1])+math[i][j];
        }
    }
    
    cout<<dp[0][0]<<endl;
    
    return 0;
}

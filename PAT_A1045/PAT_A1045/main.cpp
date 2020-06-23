//
//  main.cpp
//  PAT_A1045
//
//  Created by VachelChen on 2020/6/23.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;

int n,m,l;
int color[210];
int allcolor[10010];

int dp[210][10010];

int main(int argc, const char * argv[]) {
    memset(dp, 0, sizeof(dp));
    scanf("%d",&n);
    scanf("%d",&m);
    for (int i=1; i<=m; i++) {
        scanf("%d",&color[i]);
    }
    scanf("%d",&l);
    for (int i=1; i<=l; i++) {
        scanf("%d",&allcolor[i]);
    }
    for (int i=1; i<=m; i++) {
        for (int j=1; j<=l; j++) {
            if (color[i] == allcolor[j]) {
                dp[i][j] = dp[i][j-1]+1;
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    cout<<dp[m][l]<<endl;
    return 0;
}

//
//  main.cpp
//  LCS问题尝试解决
//
//  Created by VachelChen on 2020/2/21.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;

int dp[20][20];

int main(int argc, const char * argv[]) {
    string a,b;
    cin>>a>>b;
    memset(dp, 0, sizeof(dp));
    for(int i=1;i<=a.size();i++)
        for(int j=1;j<=b.size();j++){
            if(a[i-1] == b[j-1]){
                dp[i][j] = 1+dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    cout<<dp[a.size()][b.size()]<<endl;
    return 0;
}

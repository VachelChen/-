//
//  main.cpp
//  2016_密码脱落
//
//  Created by VachelChen on 2020/2/21.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
using namespace std;

int dp[1000][1000];

int main(int argc, const char * argv[]) {
    string a,b;
    cin>>a;
    b=a;
    reverse(b.begin(),b.end());
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
    cout<<a.size()-dp[a.size()][b.size()]<<endl;
    return 0;
}

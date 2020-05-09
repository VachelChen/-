//
//  main.cpp
//  PAT_A1007
//
//  Created by VachelChen on 2020/5/8.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 10010;
int a[maxn];
int dp[maxn];

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    //dp
    fill(dp,dp+n,0);
    dp[0] = a[0];
    for (int i=1; i<n; i++) {
        if(dp[i-1]>0){
            dp[i] = dp[i-1]+a[i];
        }
        else{
            dp[i] = a[i];
        }
    }
    int maxans = dp[0];
    for(int i=0; i<n; i++){
        maxans = max(maxans,dp[i]);
    }
    
    int minTail = a[n-1];
    int index=0;
    for(int i=0; i<n; i++){
        if(dp[i] == maxans){
            minTail = a[i];
            index = i;
            break;
        }
    }
    
    int minHead = a[0];
    for(int i=0; i<=index; i++){
        if(dp[i] == a[i]){
            minHead = a[i];
        }
    }
    
    if(maxans<0){
        maxans = 0;
        minHead = a[0];
        minTail = a[n-1];
    }
    cout<<maxans<<" "<<minHead<<" "<<minTail<<endl;
    return 0;
}

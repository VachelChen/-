//
//  main.cpp
//  2017_包子凑数
//
//  Created by VachelChen on 2020/2/26.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
int a[100];
bool flag = false;
bool dp[10000];

int gcd(int a,int b){
    return a%b == 0?b:gcd(b,a%b);
}

int main(){
    int maxn;
    memset(dp, 0, sizeof(dp));
    dp[0] = true;
    cin>>n;
    for(int i=1;i<=n;i++){
        
        cin>>a[i];
        if(i == 1)  maxn = a[i];
        else
            maxn = gcd(maxn,a[i]);
        
        for(int j=0;j<10000;j++)
            if(dp[j])   dp[j+a[i]] = true;
        
        //if(a[i] == 1)   flag = true;
    }
    
//    if(flag){
//        cout<<"0"<<endl;
//        return 0;
//    }
    
    if(maxn != 1){
        cout<<"INF"<<endl;
        return 0;
    }
    
    int ans = 0;
    for(int j=0;j<10000;j++)
            if(!dp[j])   ans++;
    
    cout<<ans<<endl;
    return 0;
}

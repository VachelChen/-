//
//  main.cpp
//  2014_波动数列
//
//  Created by VachelChen on 2020/2/19.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;
long long n,s,a,b;

long long ans=0;

void dfs(long long x,long long y,long long num){
    //cout<<"到:"<<x<<"还剩下"<<y<<endl;

    if(y==0){
        //cout<<"得一个答案"<<endl;
        if(num == s){
            ans++;
            if(ans>100000007)   ans = ans%100000007;
        }
            
        return;
    }
  
    dfs(x+a,y-1,num+x+a);
    dfs(x-b,y-1,num+x-b);
    
}

int main(int argc, const char * argv[]) {
    
    cin >> n >> s >> a >> b;
    for (long long i = (s-n*(n-1)*a/2)/n; i <= (s+n*(n-1)*b/2)/n+1; i++) {
        dfs(i,n-1,0);
    }
    cout<<ans<<endl;
    return 0;
}

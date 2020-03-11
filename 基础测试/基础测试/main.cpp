//
//  main.cpp
//  基础测试
//
//  Created by VachelChen on 2020/2/29.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#include <map>
#include <algorithm>
#include <queue>
using namespace std;

int workOut(int n,int p){
    int ans = 0;
    int op = p;
    while( n/p>=1 ){
        ans += n/p;
        p = p * op;
    }
    return ans;
}

int cal(int n,int p){
    int ans = 0;
    while(n){
        ans += n/p;
        n /= p;
    }
    return ans;
}

int main(){
    int n,p;
    cin >> n >> p;
    cout<<workOut(n,p)<<endl;
    cout<<cal(n,p)<<endl;;
    return 0;
}

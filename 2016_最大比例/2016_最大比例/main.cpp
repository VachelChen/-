//
//  main.cpp
//  2016_最大比例
//
//  Created by VachelChen on 2020/2/21.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

int n;
long long x[100];

bool cmp(int a,int b){
    return a>b;
}

long long gcd(long long a,long long b){
    return a%b==0?b:gcd(b, a%b);
}

int main(int argc, const char * argv[]) {
    cin>>n;
    long long a=0,b=0;
    for(int i=0;i<n;i++)
        cin>>x[i];
    sort(x,x+n,cmp);
    int minRatio=1;
    for(int i=1;i<n;i++){
        if((x[i]*1.0)/(x[i-1]*1.0)<minRatio){
            minRatio = min((x[i]*1.0)/(x[i-1]*1.0),minRatio*1.0);
            a = x[i];
            b = x[i-1];
        }
    }
    
    long long y = gcd(a,b);
    
    cout<<b/y<<"/"<<a/y<<endl;
    
    return 0;
}

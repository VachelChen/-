//
//  main.cpp
//  2014_斐波那契
//
//  Created by VachelChen on 2020/2/19.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
using namespace std;

long long f[10000000];

int main(int argc, const char * argv[]) {
    long long n,m,p;
    long long ans=2;
    f[1]=1;f[2]=1;
    cin>>n;
    cin>>m;
    cin>>p;
    for (long long i=3; i<=max(n,m); i++) {
        f[i]=f[i-1]+f[i-2];
        ans+=f[i];
    }
    ans = ans % f[m];
    ans = ans % p;
    cout<<ans<<endl;
    return 0;
}

//
//  main.cpp
//  PAT_A1008
//
//  Created by VachelChen on 2020/5/10.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

const int maxn = 10010;
int a[maxn];
int b[maxn];
int ans=0;
int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    a[0]=0;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    for (int i=0; i<n; i++) {
        b[i] = a[i]-a[i+1];
    }
    for (int i=0; i<n; i++) {
        if(b[i]<0){
            ans += (b[i])*(-1)*6;
        }
        else if(b[i]>0){
            ans += (b[i])*4;
        }
    }
    cout<<ans+n*5<<endl;
    return 0;
}

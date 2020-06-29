//
//  main.cpp
//  PAT_A1067
//
//  Created by VachelChen on 2020/6/29.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>

using namespace std;

bool mark[100005];
int a[100005];

int give(int x){
    int r=0;
    bool have = false;
    for (; !mark[x]; r++) {
        if (x == 0) {
            have = true;
        }
        mark[x] = true;
        x = a[x];
    }
    return have?(r-1):((r<=1)?0:(r+1));
}

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        scanf("%d",&a[i]);
    }
    int ans = 0;
    for (int i=0; i<n; i++) {
        ans += give(a[i]);
    }
    printf("%d\n",ans);
    return 0;
}

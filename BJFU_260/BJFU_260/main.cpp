//
//  main.cpp
//  BJFU_260
//
//  Created by VachelChen on 2020/8/24.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#define maxm 100
#define maxn 100
#define maxnum 10000
using namespace std;


int main(int argc, const char * argv[]) {
    int m,n;
    while (cin >> m >> n ) {
        if(!m || !n)    break;
        int a[maxm][maxn];
        int num[maxnum];
        bool flag = false;
        memset(num, 0, sizeof(num));
        int i,j;
        for (i=0; i<m; i++) {
            for (j=0; j<n; j++) {
                cin >> a[i][j];
                num[a[i][j]]++;
                if (num[a[i][j]]>1) {
                    flag = true;
                }
            }
        }
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    
    return 0;
}

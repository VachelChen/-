//
//  main.cpp
//  PAT_1054
//
//  Created by VachelChen on 2020/6/25.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#include <map>
using namespace std;

int a[810][610];
map<int,int> ma;

int main(int argc, const char * argv[]) {
    int m,n;
    scanf("%d %d",&m,&n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d",&a[n][m]);
            ma[a[n][m]]++;
        }
    }
    int ans = 0;
    for (map<int,int> :: iterator it = ma.begin(); it != ma.end(); it++) {
        if (it->second > ans && it->second > n*m/2) {
            ans = it->first;
        }
    }
    cout<<ans<<endl;
    return 0;
}

//
//  main.cpp
//  PAT_A1063
//
//  Created by VachelChen on 2020/6/28.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    scanf("%d",&n);
    vector<set<int>> v(n+1);
    for (int i=1; i<=n; i++) {
        int m;
        scanf("%d",&m);
        for (int j=0; j<m; j++) {
            int s;
            scanf("%d",&s);
            v[i].insert(s);
        }
    }
    int k;
    scanf("%d",&k);
    for (int i=0; i<k; i++) {
        int x,y;
        scanf("%d %d",&x,&y);
        int nc = 0,nt = (int)v[y].size();
        for (auto it = v[x].begin();it != v[x].end(); it++) {
            if (v[y].find(*it) == v[y].end()) {
                nt++;
            }
            else
                nc++;
        }
        double ans = (double)nc/nt * 100;
        printf("%.1f%%\n",ans);
        
    }
    return 0;
}

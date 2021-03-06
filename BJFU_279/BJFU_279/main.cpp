//
//  main.cpp
//  BJFU_279
//
//  Created by VachelChen on 2020/9/7.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#define maxn 100
using namespace std;

typedef struct {
    int vexnum,arcnum;
    int vex[maxn];
    int arc[maxn][maxn];
}graph;

int main(int argc, const char * argv[]) {
    int n,m;
    while (cin >> n >> m) {
        if(!n && !m)    break;
        graph g;
        g.vexnum = n;
        g.arcnum = m;
        fill(g.vex, g.vex+maxn, 0);
        fill(g.arc[0], g.arc[0]+maxn*maxn, 0);
        for (int i=1; i<=m+1; i++) {
            int x,y;
            cin >> x >> y;
            g.arc[x][y] = 1;
            g.arc[y][x] = 1;
        }
        for (int i=0; i<=n; i++) {
            g.arc[i][0] = i;
            g.arc[0][i] = i;
        }
        for (int i=0; i<=n; i++) {
            int j;
            for (j=0; j<n; j++) {
                cout<<g.arc[i][j]<<" ";
            }
            cout<<g.arc[i][j]<<endl;
        }
    }
    return 0;
}

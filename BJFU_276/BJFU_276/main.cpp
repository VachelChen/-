//
//  main.cpp
//  BJFU_276
//
//  Created by VachelChen on 2020/9/6.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#define maxn 100
using namespace std;

typedef struct {
    int vernum,arcnum;
    int Ver[maxn];
    int Arc[maxn][maxn];
}graph;


int main(int argc, const char * argv[]) {
    int n,m;
    while (cin >> n >> m) {
        if(!n && !m)  break;
        graph g;
        g.vernum = n;
        g.arcnum = m;
        fill(g.Ver, g.Ver+maxn, 0);
        for (int i=1; i<=n; i++) {
            g.Ver[i] = i;
        }
        fill(g.Arc[0], g.Arc[0]+maxn*maxn, 0);
        for (int j=1; j<=m; j++) {
            int x,y;
            cin >> x >> y;
            g.Arc[x][y] = 1;
            g.Arc[y][x] = 1;
        }
        int numNode;
        cin >> numNode;
        g.vernum++;
        g.Ver[g.vernum] = numNode;
        for (int i=1; i<=g.vernum; i++) {
            g.Arc[0][i] = g.Ver[i];
            g.Arc[i][0] = g.Ver[i];
        }
        for (int i=0; i<=g.vernum; i++) {
            int j;
            for (j=0; j<g.vernum; j++) {
                cout<<g.Arc[i][j]<<" ";
            }
            cout<<g.Arc[i][j]<<endl;
        }
    }
    return 0;
}

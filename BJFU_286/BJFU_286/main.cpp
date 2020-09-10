//
//  main.cpp
//  BJFU_286
//
//  Created by VachelChen on 2020/9/9.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#define maxn 100
using namespace std;

typedef struct{
    int vernum;
    int ver[maxn];
    int arc[maxn][maxn];
}graph;

int main(int argc, const char * argv[]) {
    int n,m;
    while (cin >> n >> m) {
        if(!n && !m)    break;
        graph g;
        g.vernum = n;
        fill(g.ver, g.ver+maxn, 0);
        fill(g.arc[0], g.arc[0]+maxn*maxn, 0);
        for (int i=1; i<=n; i++) {
            g.ver[i] = i;
        }
        for (int j=1; j<=m; j++) {
            int x,y;
            cin >> x >> y;
            g.arc[x][y] = 1;
            g.arc[y][x] = 1;
        }
        int newNode;
        cin >> newNode;
        for (int i=1; i<g.vernum; i++) {
            if (i >= newNode) {
                g.ver[i] = g.ver[i+1];
            }
        }
        g.vernum--;
        for (int i=1; i<=g.vernum; i++) {
            g.arc[i][0] = g.ver[i];
            g.arc[0][i] = g.ver[i];
        }
        for (int i=0; i<=g.vernum; i++) {
            int j;
            for (j=0; j<g.vernum; j++) {
                cout<<g.arc[i][j]<<" ";
            }
            cout<<g.arc[i][j]<<endl;
        }
    }
    return 0;
}

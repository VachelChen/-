//
//  main.cpp
//  BJFU_283
//
//  Created by VachelChen on 2020/9/9.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#define maxn 100
#define INF 10000
using namespace std;

typedef struct{
    int vernum,arcnum;
    int vertex[maxn];
    int arc[maxn][maxn];
}graph;

int d[maxn];
bool visit[maxn];

int main(int argc, const char * argv[]) {
    int n,m;
    while (cin >> n >> m) {
        if(!n && !m)    break;
        graph g;
        g.vernum = n;
        g.arcnum = m;
        fill(g.vertex,g.vertex+maxn,0);
        fill(g.arc[0],g.arc[0]+maxn*maxn,0);
        for (int i=1; i<=n; i++) {
            g.vertex[i] = i;
        }
        for (int i=1; i<=m; i++) {
            int x,y,z;
            cin >> x >> y >> z;
            g.arc[x][y] = z;
            g.arc[y][x] = z;
        }
        int search;
        cin >> search;
        
        //dj
        fill(visit, visit+maxn, false);
        fill(d, d+maxn, INF);
        d[search] = 0;
        for (int i=1; i<=n; i++) {
            int u = -1;
            int MIN = INF;
            for (int j=1; j<=n; j++) {
                if (!visit[j] && d[j]<MIN) {
                    u = j;
                    MIN = d[j];
                }
            }
            if(u == -1) break;
            visit[u] = true;
            for (int v=1; v<=n; v++) {
                if (!visit[v] && g.arc[v][u] && g.arc[v][u]+d[u]<d[v]) {
                    d[v] = g.arc[v][u]+d[u];
                }
            }
        }
        int ansMax = d[1];
        int ansMaxIndex = 1;
        for (int i=1; i<=n; i++) {
            if (ansMax < d[i]) {
                ansMax = d[i];
                ansMaxIndex = i;
            }
            
        }
        cout<<ansMaxIndex<<endl<<ansMax<<endl;
    }
    return 0;
}

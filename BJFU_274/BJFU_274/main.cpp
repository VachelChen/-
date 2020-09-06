//
//  main.cpp
//  BJFU_274
//
//  Created by VachelChen on 2020/9/5.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#define maxn 100
#define INF 32675
using namespace std;

typedef struct {
    int Person[maxn];
    bool relation[maxn][maxn];
    int pnum,snum;
}graph;

int d[maxn];
bool visit[maxn];
double ans[maxn];

int main(int argc, const char * argv[]) {
    int n,m;
    while (cin >> n >> m) {
        if(!n && !m) break;
        graph g;
        g.pnum = n; g.snum = m;
        fill(g.relation[0],g.relation[0]+maxn*maxn,false);
        for (int i=1; i<=n; i++) {
            g.Person[i] = i;
        }
        for (int i=0; i<m; i++) {
            int s,e;
            cin >> s >> e;
            g.relation[s][e] = 1;
            g.relation[e][s] = 1;
        }
        
        //dj
        for (int i=1; i<=n; i++) {
            fill(visit, visit+maxn, false);
            fill(d, d+maxn, INF);
            d[i] = 0;
            for (int x = 1; x<=n; x++) {
                int u = -1;
                int MIN = INF;
                for (int j=1; j<=n; j++) {
                    if(!visit[j] && d[j]<MIN){
                        u = j;
                        MIN = d[j];
                    }
                }
                if(u == -1) break;
                visit[u] = true;
                for (int v=1; v<=n; v++) {
                    if (!visit[v] && g.relation[u][v] && d[u]+1<d[v]) {
                        d[v] = d[u]+1;
                    }
                }
            }
            int num=0;
            for (int x=1; x<=n; x++) {
                if(d[x]<=6) num++;
            }
            ans[i] = 1.0*num/n*100.00;
        }
        
        //show
        for (int i=1; i<=n; i++) {
            printf("%d: %.2f%%\n",i,ans[i]);
        }
    }
    return 0;
}

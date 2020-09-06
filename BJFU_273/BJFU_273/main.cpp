//
//  main.cpp
//  BJFU_273
//
//  Created by VachelChen on 2020/9/5.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#include <cstring>
#define Maxn 100
#define INF 10000
using namespace std;

int d[Maxn];
bool visit[Maxn];
int ans_start_Index,ans_end_Index;
int ans=INF;
int pre[Maxn];

typedef struct {
    char Vertex[Maxn];
    int Side[Maxn][Maxn];
    int v,s;
}graph;

int findIndex(graph g,char c){
    for (int i=0; i<g.v; i++) {
        if (g.Vertex[i] == c) {
            return i;
        }
    }
    return -1;
}

void dj(int start,graph g){
    d[start] = 0;
    for (int i=0; i<g.v; i++) {
        int u=-1,MIN = INF;
        for (int j=0; j<g.v; j++) {
            if (!visit[j] && d[j]<MIN) {
                u = j;
                MIN = d[j];
            }
        }
        if(u == -1) return ;
        visit[u] = true;
        for (int v=0; v<g.v; v++) {
            if (g.Side[u][v]!=INF && !visit[v] && g.Side[u][v]+d[u] < d[v]) {
                d[v] = g.Side[u][v]+d[u];
                pre[v] = u;
                if (v == ans_end_Index) {
                    ans = d[v];
                }
            }
        }
    }
}



int main(int argc, const char * argv[]) {
    int n,m;
    while (cin>>n>>m) {
        if(n == 0 && m == 0)    break;
        //init
        graph g;
        fill(g.Side[0],g.Side[0]+Maxn*Maxn,INF);
        g.v = n;
        g.s = m;
        for (int i=0; i<n; i++) {
            cin >> g.Vertex[i];
        }
        for (int i=0; i<m; i++) {
            char start,end;
            int road;
            cin >> start >> end >> road;
            int start_index,end_index;
            start_index = findIndex(g,start);
            end_index = findIndex(g,end);
            g.Side[start_index][end_index] = road;
        }
        char ans_start,ans_end;
        cin >> ans_start >> ans_end;
        
        ans_start_Index = findIndex(g,ans_start);
        ans_end_Index = findIndex(g,ans_end);
        
        //dj
        fill(pre,pre+Maxn,-1);
        fill(d, d+Maxn, INF);
        memset(visit, 0, sizeof(visit));
        dj(ans_start_Index,g);
        cout<<ans<<endl;
        char path[Maxn];
        int pathnum=0;
        path[pathnum] = g.Vertex[ans_end_Index];
        while (ans_end_Index != -1) {
            pathnum++;
            path[pathnum] = g.Vertex[pre[ans_end_Index]];
            ans_end_Index = pre[ans_end_Index];
        }
        int k;
        for (k=pathnum-1; k>0; k--) {
            cout<<path[k]<<" ";
        }
        cout<<path[k]<<endl;
    }
    return 0;
}

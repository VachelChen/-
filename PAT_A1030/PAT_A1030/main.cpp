//
//  main.cpp
//  PAT_A1030
//
//  Created by VachelChen on 2020/5/3.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

const int INF = 1000000000;
const int maxn = 510;
int n,m,s,d;
int g[maxn][maxn];
int w[maxn][maxn];
int dij[maxn];
bool visit[maxn];
int pre[maxn];
int cost[maxn];

void dijkstra(){
    fill(dij,dij+maxn,INF);
    dij[s] = 0;
    pre[s] = -1;
    cost[s] = 0;
    for (int i = 0; i < n; i++) {
        int u = -1,MIN = INF;
        for(int j = 0;j < n; j++){
            if(!visit[j] && dij[j]<MIN){
                u = j;
                MIN = dij[j];
            }
        }
        
        if(u == -1) return;
        visit[u] = true;
        for(int j = 0;j < n; j++){
            if(g[u][j]>0 && !visit[j]){
                if(dij[u]+g[u][j] < dij[j]){
                    dij[j] = dij[u]+g[u][j];
                    pre[j] = u;
                    cost[j] = cost[u]+w[u][j];
                }
                else if(dij[u]+g[u][j] == dij[j]){
                    if(cost[j]>cost[u]+w[u][j]){
                        pre[j] = u;
                        cost[j] = cost[u]+w[u][j];
                    }
                }
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    cin >> n >> m >> s >> d;
    memset(g, 0, sizeof(g));
    memset(w, 0, sizeof(w));
    memset(pre, -1, sizeof(pre));
    memset(visit, 0, sizeof(visit));
    for (int i = 0; i < m; i++) {
        int a,b;
        cin >> a >> b;
        cin >> g[a][b];
        g[b][a] = g[a][b];
        cin >> w[a][b];
        w[b][a] = w[a][b];
    }
    dijkstra();
    stack<int> st;
    int x = d;
    while(x!= s){
        x = pre[x];
        st.push(x);
    }
    if(!st.empty()){
        cout<<st.top();
        st.pop();
    }
    while(!st.empty()){
        cout<<" "<<st.top();
        st.pop();
    }
    cout<<" "<<d<<" "<<dij[d]<<" "<<cost[d]<<endl;;
    
    return 0;
}

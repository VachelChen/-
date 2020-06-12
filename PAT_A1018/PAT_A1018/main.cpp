//
//  main.cpp
//  PAT_A1018
//
//  Created by VachelChen on 2020/6/12.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 9999999;

int c,n,s,m;

int weight[510];
int road[510][510];

int d[510];
bool vis[510]={false};
int minNeed = INF, minBack = INF;

vector<int> pre[510];   //相当于靠直接前驱的关系建立了临接表
vector<int> path,temppath;

void dfs(int x){
    temppath.push_back(x);
    if (!x) {
        int need = 0,back = 0;
        for (int i=(int)temppath.size()-1; i>=0; i--) {
            int id = temppath[i];
            if (weight[id]>0) {
                back+= weight[id];
            }
            else{
                if (back > (0-weight[id])) {
                    back += weight[id];
                }else{
                    need += ((0-weight[id])-back);
                    back = 0;
                }
            }
        }
        if (need < minNeed) {
            minNeed = need;
            minBack = back;
            path = temppath;
        }else if(need == minNeed && back <minBack){
            minBack = back;
            path = temppath;
        }
        temppath.pop_back();
        return;
    }
    for (int i=0; i<pre[x].size(); i++) {
        dfs(pre[x][i]);
    }
    temppath.pop_back();
}

int main(int argc, const char * argv[]) {
    fill(road[0],road[0]+510*510,INF);  //二维数组的初始化
    fill(d, d+510, INF);
    cin >> c >> n >> s >> m;
    for (int i=1; i<=n; i++) {
        cin >> weight[i];
        weight[i] = weight[i] - c/2;
    }
    for (int i=0; i<m; i++) {
        int x,y,t;
        cin >> x >> y >> t;
        road[x][y] = t;
        road[y][x] = t;
    }
    d[0] = 0;
    for (int i=0; i<=n; i++) {
        int u = -1,minn = INF;
        for (int j=0; j<=n; j++) {
            if (!vis[j] && d[j] < minn) {
                u = j;
                minn = d[j];
            }
        }
        if(u == -1) break;
        vis[u] = true;
        for (int v=0; v<=n; v++) {
            if (!vis[v] && road[u][v]!=INF) {
                if (d[u]+road[u][v] < d[v]) {
                    d[v] = d[u]+road[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                }
                else if(d[v] == d[u]+road[u][v]){
                    pre[v].push_back(u);
                }
            }
        }
    }
    dfs(s);
    cout<<minNeed<<" 0";
    for (int i = (int)path.size()-2; i>=0; i--) {
        cout<<"->"<<path[i];
    }
    cout<<" "<<minBack<<endl;
    return 0;
}

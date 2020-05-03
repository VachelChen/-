//
//  main.cpp
//  PAT_A1003
//
//  Created by VachelChen on 2020/5/2.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 510;
const int INF = 1000000000;

struct city{
    int id;
    int val;
}c[maxn];

int n,m,c1,c2;
int G[maxn][maxn];
bool visit[maxn] = {false};
int d[maxn];
int t[maxn];
int num[maxn];

bool flag = false;

void Dijkstra(){
    fill(d,d+maxn,INF);
    memset(num, 0, sizeof(num));
    memset(t, 0, sizeof(t));
    d[c1] = 0;
    t[c1] = c[c1].val;
    num[c1] = 1;
    for(int i=0; i<n; i++){
        int u = -1,MIN = INF;
        for(int j = 0;j<n;j++){
            if(!visit[j] && d[j]<MIN){
                u = j;
                MIN = d[j];
            }
        }
        
        if(u == -1) return;
        visit[u] = true;
        
        for(int j=0; j<n; j++){
            if(!visit[j] && G[u][j]!=0){
                if(d[u] + G[u][j] < d[j]){
                    d[j] = d[u] + G[u][j];
                    t[j] = t[u] + c[j].val;
                    num[j] = num[u];
                }
                else if(d[u] + G[u][j] == d[j]){
                    if(t[j] < t[u] + c[j].val){
                        t[j] = t[u] + c[j].val;
                    }
                    num[j] += num[u];
                }
            }
        }
        
    }
}

int main(int argc, const char * argv[]) {
    cin >> n >> m >> c1 >> c2;
    for (int i=0; i<n; i++) {
        c[i].id = i;
        cin >> c[i].val;
    }
    //fill(G[0],G[0]+maxn*maxn,INF);
    for(int i=0; i<m; i++){
        int s,d,weight;
        cin >> s >> d >> weight;
        G[s][d] = weight;
        G[d][s] = weight;
    }
    Dijkstra();
    cout<<num[c2]<<" "<<t[c2]<<endl;
    return 0;
}

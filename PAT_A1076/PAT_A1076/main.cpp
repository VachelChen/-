//
//  main.cpp
//  PAT_A1076
//
//  Created by VachelChen on 2020/4/28.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <queue>
#include <set>
#include <map>
#include <vector>
using namespace std;

const int maxv =1010;
struct node{
    int id;
    int layer;
};
vector<node> g[maxv];
bool inq[maxv] = {false};

int BFS(int s,int L){
    int num = 0;
    queue<node> q;
    node start;
    start.id = s;
    start.layer = 0;
    q.push(start);
    inq[start.id] = true;
    while (!q.empty()) {
        node topnode = q.front();
        q.pop();
        int u = topnode.id;
        for(int i=0;i<g[u].size();i++){
            node next = g[u][i];
            next.layer = topnode.layer+1;
            if (inq[next.id] == false && next.layer <= L) {
                q.push(next);
                inq[next.id] = true;
                num++;
            }
        }
    }
    return num;
}

int main(){
    node user;
    int n,L,numF,idF;
    cin >> n >> L;
    for(int i=1;i<=n;i++){
        user.id = i;
        cin >> numF;
        for(int j = 0; j< numF; j++){
            cin >> idF;
            g[idF].push_back(user);
        }
    }
    int query,s;
    cin >> query;
    for(int i=0;i<query;i++){
        memset(inq, false, sizeof(inq));
        cin >> s;
        cout<<BFS(s, L)<<endl;
    }
}

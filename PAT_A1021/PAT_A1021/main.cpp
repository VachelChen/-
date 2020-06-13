//
//  main.cpp
//  PAT_A1021
//
//  Created by VachelChen on 2020/6/13.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
const int maxn = 10010;
int n;
//树是稀疏图，最好用临阶表存储
vector<int> v[maxn];
bool visit[maxn]={false};
int father[maxn];
bool isRoot[maxn]={false};
int roadnum[maxn];
int highttree[maxn];
int treehight[maxn];

void init(){
    for (int i=1; i<=n; i++) {
        father[i] = i;
    }
}

int find(int x){
    while (x != father[x]) {
        x = father[x];
    }
    return x;
}

void Union(int x,int y){
    int a = find(x);
    int b = find(y);
    if (a != b) {
        father[a] = b;
    }
}

queue<int> q;
int bfs(int x){
    q.push(x);
    treehight[x]=1;
    int ans = 1;
    visit[x] = true;
    while (!q.empty()) {
        int y = q.front();
        q.pop();
        for (int i=0; i<v[y].size(); i++) {
            if (!visit[v[y][i]]) {
                q.push(v[y][i]);
                treehight[v[y][i]] = treehight[y]+1;
                ans = max(ans,treehight[v[y][i]]);
                visit[v[y][i]] = true;
            }
        }
    }
    return ans;
}

int main(int argc, const char * argv[]) {
    fill(roadnum,roadnum+maxn,0);
    cin >> n;
    init();
    for (int i=0; i<n-1; i++) {
        int x,y;
        cin >> x >> y;
        roadnum[x]++;   roadnum[y]++;
        v[x].push_back(y);
        v[y].push_back(x);
        Union(x, y);
    }
    for (int i=1; i<=n; i++) {
        isRoot[find(i)] = true;
    }
    int k=0;
    for (int i=1; i<=n; i++) {
        if(isRoot[i])   k++;
    }
    if (k != 1) {
        cout<<"Error: "<<k<<" components"<<endl;
    }
    else{
        int highest=0;
        for (int i=1; i<=n; i++) {
            if(roadnum[i] == 1){
                while (!q.empty()) {
                    q.pop();
                }
                fill(treehight,treehight+maxn,0);
                fill(visit,visit+maxn,false);
                highttree[i] = bfs(i);
                highest = max(highttree[i], highest);
            }
        }
        for (int i=1; i<=n; i++) {
            if (highttree[i] == highest) {
                cout<<i<<endl;
            }
        }
    }
    return 0;
}

//
//  main.cpp
//  PAT_A1004
//
//  Created by VachelChen on 2020/5/7.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int allLevel[100];

struct node{
    int kids;
    int level;
    int child[100];
    node(){
        kids = 0;
        level = 0;
        fill(child,child+100,0);
    }
}n[100];

queue<node> q;
int N,M,maxLevel=0;

void bfs(){
    fill(allLevel,allLevel+100,0);
    q.push(n[1]);
    while (!q.empty()) {
        node temp = q.front();
        q.pop();
        for (int i=0; i<temp.kids; i++) {
            n[temp.child[i]].level = temp.level+1;
            maxLevel = max(maxLevel,temp.level+1);
            q.push(n[temp.child[i]]);
        }
    }
}


int main(int argc, const char * argv[]) {
    cin >> N >> M;
    for (int i = 1; i<=M; i++) {
        int id;
        cin >> id;
        cin >> n[id].kids;
        for (int j = 0; j<n[id].kids; j++) {
            cin >> n[id].child[j];
        }
    }
    bfs();
    int ans = 0;
    for (int i = 0; i<N; i++) {
        for (int j = 1; j<=N; j++) {
            if(n[j].level == i && n[j].kids == 0){
                ans ++ ;
            }
        }
        if (i == 0) {
            cout<<ans;
            ans = 0;
        }
        else{
            cout<<" "<<ans;
            ans = 0;
        }
        
        if(i >= maxLevel)  break;
    }
    cout<<endl;
    return 0;
}

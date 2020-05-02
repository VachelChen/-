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
using namespace std;

int N,L,pn;
bool G[1010][1010];
struct node{
    int s;
    int deep;
};
queue <node> q;
map <int,int> m;
set <int> s;
int ans;

void BFS(){

    while (!q.empty()) {
        
        node temp = q.front();
        q.pop();
        if (temp.deep>L) {
            break;
        }
        int temps = temp.s;
        int cnt = 0;
        for (int i=1; i<=N; i++) {
            //if(cnt == m[i]) break;
            if(G[temps][i]){
                cnt++;
                if(s.find(i) == s.end()){
                    ans++;
                    node newx;
                    newx.s = i;
                    newx.deep = temp.deep+1;
                    q.push(newx);
                    s.insert(i);
                }
                
            }
        }
    }
    
}

int main(int argc, const char * argv[]) {
    cin>>N>>L;
    for (int i=1; i<=N; i++) {
        int f;
        cin >>f;
        m[i] = f;
        for(int j=0;j<f;j++){
            int n;
            cin >> n;
            G[n][i] = true;
        }
    }
    cin >> pn;
    for (int i=0; i<pn; i++) {
        while (!q.empty()) {
            q.pop();
        }
        while (!s.empty()) {
            s.clear();
        }
        ans = 0;
        int x;
        cin >> x;
        s.insert(x);
        node nodex;
        nodex.s = x;
        nodex.deep = 1;
        q.push(nodex);
        BFS();
        cout<<ans<<endl;
    }
    
    return 0;
}

//
//  main.cpp
//  BJFU_285
//
//  Created by VachelChen on 2020/9/9.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#define maxn 100
#define INF 10000
using namespace std;

typedef struct node{
    char data;
    node *next;
}node,*linklist;

typedef struct {
    int vernum,arcnum;
    linklist v[maxn];
}graph;

int find(graph g,char x){
    for (int i=1; i<=g.vernum; i++) {
        if (g.v[i]->data == x) {
            return i;
        }
    }
    return 0;
}


int main(int argc, const char * argv[]) {
    int n,m,k;
    while (cin >> n >> m >> k) {
        if(!n && !m && !k)  break;
        graph g;
        g.vernum = n;
        g.arcnum = m;
        for (int i=1; i<=n; i++) {
            g.v[i] = new node;
            char c;
            cin >> c;
            g.v[i]->data = c;
            g.v[i]->next = NULL;
        }
        for (int j=1; j<=m; j++) {
            char a,b;
            cin >> a >> b;
            int x,y;
            x = find(g,a);
            y = find(g,b);
            linklist p;
            p = new node;
            p->data = a;
            p->next = g.v[y]->next;
            g.v[y]->next = p;
            
            linklist q;
            q = new node;
            q->data = b;
            q->next = g.v[x]->next;
            g.v[x]->next = q;
        }
        char a,b;
        cin >> a >> b;
        int x,y;
        x = find(g,a);
        y = find(g,b);
        //dfs
        int top=0;
        int Stack[maxn];
        bool visit[maxn];
        fill(visit,visit+maxn,false);
        Stack[top++] = x;
        linklist t;
        bool flag = false;
        int ans=1;
        while (top>0 && !flag) {
            t = g.v[Stack[top-1]]->next;
            char p = '.';
            while (t) {
                if (!visit[find(g,t->data)]) {
                    p = t->data;
                    if (p == b && ans == k) {
                        flag = true;
                        break;
                    }
                }
                t = t->next;
            }
            if (p == '.') {
                top--;
                ans = 1;
            }
            else{
                visit[find(g,p)] = true;
                Stack[top++] = find(g,p);
                ans++;
            }
        }
        if(flag)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}

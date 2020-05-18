//
//  main.cpp
//  PAT_A1013
//
//  Created by VachelChen on 2020/5/18.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 1024;
int n,m,k;
bool a[maxn][maxn];
int vis[maxn];

void visit(int x){
    vis[x] = 1;
    for(int i=1;i<=n;++i){
        if(a[x][i] && !vis[i])
            visit(i);
    }

}

int bfs(int x){
    memset(vis, 0, sizeof(vis));
    int cnt = -1;
    vis[x] = 1;
    for (int i=1; i<=n; i++) {
        if(!vis[i]){
            visit(i);
            cnt++;
        }
    }
    return cnt;
}

int main(int argc, const char * argv[]) {

    scanf("%d %d %d",&n,&m,&k);
    //cin >> n >> m >> k;

    for (int i=0; i<m; i++) {
        int x,y;
        //cin >> x >> y;
        scanf("%d %d",&x,&y);
        a[x][y] = 1;
        a[y][x] = 1;
    }
    
    for (int i=0; i<k; i++) {
        int x;
        //cin >> x;
        scanf("%d",&x);
        cout<<bfs(x)<<endl;
    }
    
    
    return 0;
}

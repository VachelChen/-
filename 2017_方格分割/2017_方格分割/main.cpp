//
//  main.cpp
//  2017_方格分割
//
//  Created by VachelChen on 2020/2/26.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;

int visit[7][7];
int ans = 0;

void dfs(int x,int y){
    if(visit[x][y]) return;
    
    if(x == 0 || x == 6 || y == 0 || y == 6){
        ans++;
        return;
    }
    
    visit[x][y] = 1;
    visit[6-x][6-y] = 1;
    
    dfs(x+1, y);
    dfs(x,y+1);
    dfs(x-1,y);
    dfs(x,y-1);
    
    visit[x][y] = 0;
    visit[6-x][6-y] = 0;
}

int main(int argc, const char * argv[]) {
    memset(visit,0,sizeof(visit));
    dfs(3, 3);
    cout<<ans/4<<endl;
    return 0;
}

//
//  main.cpp
//  2017_迷宫
//
//  Created by VachelChen on 2020/2/24.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

char direction[11][11];
int visit[11][11];
bool walkOut;

void dfs(int x,int y){
    visit[x][y] = 1;
    if(direction[x][y] == 'U' && x == 0)    walkOut=true;
    if(direction[x][y] == 'L' && y == 0)    walkOut=true;
    if(direction[x][y] == 'R' && y == 10)    walkOut=true;
    if(direction[x][y] == 'D' && x == 10)    walkOut=true;
    
    if(direction[x][y] == 'U' && !visit[x-1][y])  dfs(x-1, y);
    if(direction[x][y] == 'L' && !visit[x][y-1])  dfs(x, y-1);
    if(direction[x][y] == 'R' && !visit[x][y+1])  dfs(x, y+1);
    if(direction[x][y] == 'D' && !visit[x+1][y])  dfs(x+1, y);
}

int main(int argc, const char * argv[]) {
    
    memset(direction,0,sizeof(direction));
        
    for(int i=1;i<11;i++)
        for(int j=1;j<11;j++){
            char x;
            cin>>x;
            direction[i][j] = x;
        }
    
    int ans=0;
            
    for(int i=1;i<11;i++){
        for(int j=1;j<11;j++){
            memset(visit,0,sizeof(visit));
            walkOut = false;
            dfs(i,j);
            if(walkOut)
                ans++;
        }
    }
    
    cout<<ans<<endl;
    return 0;
}

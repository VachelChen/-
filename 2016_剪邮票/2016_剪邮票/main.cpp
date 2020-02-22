//
//  main.cpp
//  2016_剪邮票
//
//  Created by VachelChen on 2020/2/21.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <algorithm>
#include <sstream>
#include <vector>
using namespace std;

int a[3][4];
int visit[3][4];
int num;
bool flag;
vector<string> v;

string i2s(int x){
    stringstream ss;
    string s;
    ss << x;
    ss >> s;
    return s;
}

void dfs(int x,int y){
    
    visit[x][y] = 1;
    num++;
    if(num == 5){
        flag = true;
        return ;
    }
    
    if(x<2 && !visit[x+1][y] && a[x+1][y]) dfs(x+1, y);
    if(x>0 && !visit[x-1][y] && a[x-1][y]) dfs(x-1, y);
    if(y<3 && !visit[x][y+1] && a[x][y+1]) dfs(x, y+1);
    if(y>0 && !visit[x][y-1] && a[x][y-1]) dfs(x, y-1);
    
}

int main(int argc, const char * argv[]) {
    
    int value[12]={0,0,0,0,0,0,0,1,1,1,1,1};
    int ans=0;
    
    do{
        int n=0;
        memset(visit, 0, sizeof(visit));
        
        for(int x=0;x<3;x++){
            for(int y=0;y<4;y++){
                a[x][y] = value[n++];
            }
        }
        
        bool doubleJump = false;
        
        for(int x=0;x<3;x++){
            for(int y=0;y<4;y++){
                if(a[x][y] == 1){
                    flag = false;
                    num = 0;
                    dfs(x,y);
                    doubleJump = true;
                    break;
                }
            }
            if(doubleJump)  break;
        }
        
        if(flag){
            ans++;
        }
    }while(next_permutation(value,value+12));
    
    cout<<ans<<endl;
    return 0;
}

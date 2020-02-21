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
vector<string> v;

string i2s(int x){
    stringstream ss;
    string s;
    ss << x;
    ss >> s;
    return s;
}

void dfs(int x,int y,int num,string five){
    
    visit[x][y] = 1;

    if(num == 5){
        sort(five.begin(),five.end());
        int i;
        for(i=0;i<v.size();i++){
            if(v[i].find(five) != string::npos ){
                break;
            }
        }
        if(i == v.size()){
            v.push_back(five);
        }
        return ;
    }
    
    if(x<2 && !visit[x+1][y]) dfs(x+1, y, num+1, five.append(i2s(a[x+1][y])));
    if(x>0 && !visit[x-1][y]) dfs(x-1, y, num+1, five.append(i2s(a[x-1][y])));
    if(y<3 && !visit[x][y+1]) dfs(x, y+1, num+1, five.append(i2s(a[x][y+1])));
    if(y>0 && !visit[x][y-1]) dfs(x, y-1, num+1, five.append(i2s(a[x][y-1])));
    
    visit[x][y]=0;
}

int main(int argc, const char * argv[]) {
    

    int n=1;
    for(int x=1;x<3;x++){
        for(int y=0;y<4;y++){
            a[x][y]=n++;
        }
    }
    
    for(int x=1;x<3;x++){
        for(int y=0;y<4;y++){
            memset(visit, 0, sizeof(visit));
            dfs(x,y,1,i2s(a[x][y]));
        }
    }
    cout<<v.size()<<endl;
    return 0;
}

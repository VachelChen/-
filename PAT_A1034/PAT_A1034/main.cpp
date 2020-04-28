//
//  main.cpp
//  PAT_A1034
//
//  Created by VachelChen on 2020/3/30.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;

int g[2010][2010];
map<string, int> m;
map<int, string> versem;
map<string, int> weight;
map<string, int> Gang;

int n,k;
bool visit[2020];

void DFS(int x,int& head,int& number,int& totalcall){
    visit[x] = true;
    if(weight[versem[x]]>weight[versem[head]])
        head = x;
    number++;
    
    for(int i=1;i<=n;i++){
        if(g[x][i]>0){
            totalcall += g[x][i];
            g[x][i] = g[i][x] = 0;
            if(visit[i] == false){
                DFS(i, head, number, totalcall);
            }
        }
    }
}


int main(){
    memset(g, 0, sizeof(g));
    memset(visit, 0, sizeof(visit));
    cin >> n >> k;
    
    int index=1;
    for (int i=0; i<n; i++) {
        string a,b;
        int w;
        cin >> a >> b >> w;
        weight[a] += w;
        weight[b] += w;
        if(!m[a]){
            m[a]=index++;
            versem[m[a]]=a;
        }
        if(!m[b]){
            m[b]=index++;
            versem[m[b]]=b;
        }
        g[m[a]][m[b]] += w;
        g[m[b]][m[a]] = g[m[a]][m[b]];
    }
    
    for(int i=1;i<=n;i++){
        if(visit[i] == false){
            int head=i,number=0,total = 0;
            DFS(i, head, number, total);
            if(number>2 && total >k){
                Gang[versem[head]] = number;
            }
        }
    }
    
    cout<<Gang.size()<<endl;
    for(map<string,int>::iterator it = Gang.begin();it!=Gang.end();it++){
        cout<<it->first<<" "<<it->second<<endl;
    }
//    cout<<weight["AAA"]<<m["BBB"]<<m["CCC"]<<m["DDD"]<<endl;
    
    return 0;
}



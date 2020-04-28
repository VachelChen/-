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

int g[1000][1000];

int main(){
    memset(g, 0, sizeof(g));
    int n,k;
    cin >> n >> k;
    map<string, int> m;
    int index=1;
    for (int i=0; i<n; i++) {
        string a,b;
        int w;
        cin >> a >> b >> w;
        if(m.find(a)!=m.end())
            m[a]=index++;
        if(m.find(b)!=m.end())
            m[b]=index++;
        g[m[a]][m[b]]+=w;
        g[m[b]][m[a]] = g[m[a]][m[b]];
    }
    cout<<"c"<<endl;
    return 0;
}



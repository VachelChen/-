//
//  main.cpp
//  基础测试
//
//  Created by VachelChen on 2020/2/29.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#include <map>
using namespace std;

map <int, int> m;

int main(){
    int n;
    cin >> n;
    while(n--){
        int x,y;
        cin>>x>>y;
        m[x] += y;
    }
    int maxn = 1;
    for(int i=2;i<m.size();i++){
        if(m[i]>m[maxn])
            maxn = i;
    }
    cout<<maxn<<" "<<m[maxn]<<endl;
    return 0;
}

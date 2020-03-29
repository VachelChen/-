//
//  main.cpp
//  好朋友
//
//  Created by VachelChen on 2020/3/29.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
using namespace std;

const int maxn = 110;
int father[maxn];

int findFather(int x){
    if(x == father[x])  return x;
    else{
        int F = findFather(father[x]);
        father[x] = F;
        return F;
    }
}

int main(int argc, const char * argv[]) {
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        father[i] = i;
    int a,b;
    for (int i=0; i<m; i++) {
        cin>>a>>b;
        int x = findFather(a);
        int y = findFather(b);
        if(x != y){
            father[x] = y;
        }
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        if(father[i] == i){
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}

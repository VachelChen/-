//
//  main.cpp
//  2017_分巧克力
//
//  Created by VachelChen on 2020/2/27.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

struct chocolate{
    int h;
    int w;
    int maxSide;
    int kind[1000];
//    void in(){
//        memset(kind,0,sizeof(kind));
//    }
}c[1000];

int n,k;
int allMaxSide=1;

int findMax(){
    for(int j=allMaxSide;j>=1;j--){
        int total = 0;
        for(int i=0;i<n;i++){
            if(c[i].kind[j]){
                total += c[i].kind[j];
            }
        }
        if(total >= k){
            return j;
        }
    }
    return 1;
}

int main(int argc, const char * argv[]) {
    
    cin>>n>>k;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        c[i].h = x;
        c[i].w = y;
        c[i].maxSide = min(x,y);
        allMaxSide = max(allMaxSide,c[i].maxSide);
        //c[i].in();
        for(int j=1;j<=min(x,y);j++){
            c[i].kind[j] = (x/j) * (y/j);
        }
    }
    cout<<findMax()<<endl;
    return 0;
}

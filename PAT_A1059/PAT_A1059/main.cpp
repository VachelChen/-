//
//  main.cpp
//  PAT_A1059
//
//  Created by VachelChen on 2020/3/7.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

struct factor{
    int x,cnt;
}f[10];

const int MAXN = 10000000;
int p[MAXN];
int pNum = 0;
int fNum = 0;

bool judgePrime(int x){
    for(int i=2;i<=sqrt(x);i++){
        if(x%i == 0)
            return false;
    }
    return true;
}

int main(int argc, const char * argv[]) {
    int n,m;
    cin >> n;
    if(n == 1){
        cout<<"1=1"<<endl;
        return 0;
    }
    m = n;
    for(int i=2;i<=sqrt(n);i++){
        if(judgePrime(i)){
            p[pNum++] = i;
        }
    }
    for(int i=0;i<pNum;i++){
        if(n % p[i] == 0){
            f[fNum].x = p[i];
            f[fNum].cnt = 0;
            while (n % p[i] == 0) {
                f[fNum].cnt++;
                n = n / p[i];
            }
            fNum++;
        }
    }
    if(n!=1){
        f[fNum].x = n;
        f[fNum].cnt = 1;
        fNum++;
    }
    
    cout<<m<<"=";
    if(f[0].cnt != 1)   cout<<f[0].x<<"^"<<f[0].cnt;
    else cout<<f[0].x;
    
    for (int i=1; i<fNum; i++) {
        if(f[i].cnt != 1)   cout<<"*"<<f[i].x<<"^"<<f[i].cnt;
        else cout<<"*"<<f[i].x;
    }
    cout<<endl;
    return 0;
}

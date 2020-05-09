//
//  main.cpp
//  PAT_A1006
//
//  Created by VachelChen on 2020/5/8.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 10010;
int n;

struct record{
    string s;
    int signTime;
    int outTime;
}r[maxn];

bool cmp1(record a,record b){
    return a.signTime<b.signTime;
}

bool cmp2(record a,record b){
    return a.outTime>b.outTime;
}

int main(int argc, const char * argv[]) {
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> r[i].s;
        string a,b;
        cin >> a;
        cin >> b;
        r[i].signTime = (a[0]-'0')*100000+(a[1]-'0')*10000+
                        (a[3]-'0')*1000+(a[4]-'0')*100+
                        (a[6]-'0')*10+(a[7]-'0');
        
        r[i].outTime =  (b[0]-'0')*100000+(b[1]-'0')*10000+
                        (b[3]-'0')*1000+(b[4]-'0')*100+
                        (b[6]-'0')*10+(b[7]-'0');
    }
    sort(r, r+n, cmp1);
    cout<<r[0].s<<" ";
    sort(r, r+n, cmp2);
    cout<<r[0].s<<endl;
    return 0;
}

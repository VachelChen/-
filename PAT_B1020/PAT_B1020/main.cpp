//
//  main.cpp
//  PAT_B1020
//
//  Created by VachelChen on 2020/3/3.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

map <double,double> m;

bool cmp(double x,double y){
    return x>y;
}
double all[1001];
double allValue[501];

int main(int argc, const char * argv[]) {
    int n,d;
    cin>>n>>d;
    for(int i=0;i<n;i++)
        cin>>all[i];
    for(int i=0;i<n;i++){
        double x;
        cin>>x;
        if(x == 0) {
            allValue[i] = 0;
            m[allValue[i]] = all[i];
            continue;
        }
        allValue[i] = (x*1.0)/all[i];
        m[allValue[i]] = all[i];
    }
    sort(allValue,allValue+n,cmp);
    
    double ans=0;
    for(int i=0;i<n;i++){
        if(d>m[allValue[i]]){
            ans += m[allValue[i]]*allValue[i];
            d -= m[allValue[i]];
        }
        else{
            ans += d*allValue[i];
            break;
        }
    }
    printf("%.2lf\n",ans);
    return 0;
}

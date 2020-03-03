//
//  main.cpp
//  PAT_B1020
//
//  Created by VachelChen on 2020/3/3.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int n,d;
    cin>>n>>d;
    int all[1000];
    double allValue[100];
    for(int i=0;i<n;i++)
        cin>>all[i];
    for(int i=0;i<n;i++){
        double x;
        cin>>x;
        allValue[i] = (x*1.0)/all[i];
    }
    
    return 0;
}

//
//  main.cpp
//  PAT_A1060
//
//  Created by VachelChen on 2020/3/14.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    string a,b;
    cin>> n >> a >> b;
    string ansa,ansb;
    for(int i=0;i<n;i++){
        ansa[i] = a[i];
        ansb[i] = b[i];
    }
    if (ansa == ansb)
        cout<<"YES"<<" ";
    else
        cout<<"NO"<<" ";
    cout<<"0."<<ansa<<"*10^"<<a.size()<<" 0."<<ansb<<"*10^"<<b.size()<<endl;
    return 0;
}

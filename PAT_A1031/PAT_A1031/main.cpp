//
//  main.cpp
//  PAT_A1031
//
//  Created by VachelChen on 2020/6/18.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main(int argc, const char * argv[]) {
    string x;
    cin >> x;
    int n1,n2,maxn=0;
    
    for (n2=3; n2<=x.size(); n2++) {
        if ((x.size()+2-n2)%2 == 0) {
            if (max(((int)x.size()+2-n2)/2,maxn)<=n2) {
                maxn = max(((int)x.size()+2-n2)/2,maxn);
            }
        }
    }
    n1 = maxn;
    n2 = (int)x.size()+2-2*n1;
    for (int j=0; j<n1-1; j++) {
        cout<<x[j];
        for (int i=0; i<n2-2; i++) {
            cout<<" ";
        }
        cout<<x[x.size()-1-j]<<endl;
    }
    for (int i=n1-1; i<n1-1+n2; i++) {
        cout<<x[i];
    }
    cout<<endl;
    return 0;
}

//
//  main.cpp
//  PAT_A1041
//
//  Created by VachelChen on 2020/6/22.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#include <map>
using namespace std;

map<int,int> m;
int a[110000];

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        a[i] = x;
        m[x]++;
    }
    int j;
    for (j=0; j<n; j++) {
        if (m[a[j]]==1) {
            cout<<a[j]<<endl;
            return 0;
        }
    }
    cout<<"None"<<endl;
    return 0;
}

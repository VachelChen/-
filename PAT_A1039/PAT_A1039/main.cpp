//
//  main.cpp
//  PAT_A1039
//
//  Created by VachelChen on 2020/6/22.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#include <map>
#include <set>
using namespace std;

map<string, set<int>> m;

int n,k;
int main(int argc, const char * argv[]) {
    cin >> n >> k;
    for (int i=0; i<k; i++) {
        int id,num;
        cin >> id >> num;
        string x;
        for (int j=0; j<num; j++) {
            cin >> x;
            m[x].insert(id);
        }
    }
    for (int i=0; i<n; i++) {
        string y;
        cin >> y;
        cout<<y<<" "<<m[y].size();
        for (set<int> ::iterator it = m[y].begin();it!=m[y].end();it++) {
            cout<<" "<<*it;
        }
        cout<<endl;
    }
    return 0;
}

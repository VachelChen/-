//
//  main.cpp
//  PAT_A1051
//
//  Created by VachelChen on 2020/6/24.
//  Copyright © 2020 VachelChen. All rights reserved.
//
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main() {
    int m, n, k;
    scanf("%d %d %d", &m, &n, &k);
    vector<int> v;
    stack<int> s;
    for(int i = 0; i < k; i++) {
        v.clear();
        while (!s.empty()) {
            s.pop();
        }
        for (int j=0; j<n; j++) {
            int x;
            scanf("%d",&x);
            v.push_back(x);
        }
        int index = 0;
        bool flag = true;
        for (int j=1; j<=n; j++) {
            s.push(j);
            if (s.size() > m) {
                flag = false;
            }
            while (s.top() == v[index]) {
                index++;
                s.pop();
                if (s.empty()) {
                    break;
                }
            }
        }
        if (s.empty()&&flag) {
            cout<<"YES"<<endl;
        }
        else
            cout<<"NO"<<endl;
    }
    return 0;
}

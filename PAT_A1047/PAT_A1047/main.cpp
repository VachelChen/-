//
//  main.cpp
//  PAT_A1047
//
//  Created by VachelChen on 2020/6/24.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int n,k;
char name[40010][5];
vector<int> course[2510];

bool cmp1(int a, int b) {
    return strcmp(name[a], name[b]) < 0;
}

int main(int argc, const char * argv[]) {
    scanf("%d %d",&n,&k);
    for (int i=0; i<n; i++) {
        scanf("%s",name[i]);
        int num;
        cin >> num;
        for (int j=0; j<num; j++) {
            int x;
            cin >> x;
            course[x].push_back(i);
        }
    }
    
    for (int i=1; i <= k; i++) {
        cout<<i<<" "<<course[i].size()<<endl;
        sort(course[i].begin(), course[i].end(), cmp1);
        for (int j=0;j<course[i].size(); j++) {
            printf("%s\n", name[course[i][j]]);
        }
    }
    return 0;
}

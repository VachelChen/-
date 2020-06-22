//
//  main.cpp
//  PAT_A1025
//
//  Created by VachelChen on 2020/6/15.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 30010;

struct person{
    string id;
    int grade;
    int rank;
    int group;
    int local;
}p[maxn];

bool cmplocal(person a,person b){
    if (a.grade == b.grade) {
        return a.id<b.id;
    }
    else{
        return a.grade>b.grade;
    }
}

int n,k,totalnum=0;
int main(int argc, const char * argv[]) {
    cin >> n;
    int g = 0;
    for (int i=0; i<n; i++) {
        g++;
        cin >> k;
        for (int j=0+totalnum; j<k+totalnum; j++) {
            cin >> p[j].id;
            cin >> p[j].grade;
            p[j].group = g;
        }
        sort(p+totalnum, p+totalnum+k, cmplocal);
        p[totalnum].local = 1;
        for (int j=totalnum+1; j<totalnum+k; j++) {
            if (p[j].grade == p[j-1].grade) {
                p[j].local = p[j-1].local;
            }
            else{
                p[j].local = j-totalnum+1;
            }
        }
        totalnum+=k;
    }
    sort(p, p+totalnum, cmplocal);
    p[0].rank = 1;
    for (int i=1; i<totalnum; i++) {
        if (p[i].grade == p[i-1].grade) {
            p[i].rank = p[i-1].rank;
        }
        else{
            p[i].rank = i+1;
        }
    }
    cout<<totalnum<<endl;
    for (int i=0; i<totalnum; i++) {
        cout<<p[i].id<<" "<<p[i].rank<<" "<<p[i].group<<" "<<p[i].local<<endl;
    }
    return 0;
}

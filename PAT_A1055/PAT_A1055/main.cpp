//
//  main.cpp
//  PAT_A1055
//
//  Created by VachelChen on 2020/6/25.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 100010;

struct people{
    string name;
    int age;
    int worth;
}p[maxn];

bool cmp1(people a,people b){
    if (a.worth != b.worth) {
        return a.worth > b.worth;
    }
    if(a.age != b.age){
        return a.age < b.age;
    }
    return a.name < b.name;
}

int main(int argc, const char * argv[]) {
    int n,k;
    scanf("%d %d",&n,&k);
    for (int i=0; i<n; i++) {
        cin >> p[i].name;
        scanf("%d %d",&p[i].age,&p[i].worth);
    }
    sort(p, p+n, cmp1);
    for (int j=0; j<k; j++) {
        int m,s,e;
        scanf("%d %d %d",&m,&s,&e);
        cout<<"Case #"<<j+1<<":"<<endl;
        int index = 0;
        for (int i=0; i<n ; i++) {
            if (p[i].age>=s && p[i].age<=e) {
                cout<<p[i].name<<" "<<p[i].age<<" "<<p[i].worth<<endl;
                index++;
            }
            if (index == m) {
                break;
            }
        }
        if(!index)  cout<<"None"<<endl;
    }
    return 0;
}

//
//  main.cpp
//  PAT_A1028
//
//  Created by VachelChen on 2020/6/17.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 100010;

struct student{
    int id;
    string name;
    int grade;
}stu[maxn];

bool cmp1(student a,student b){
    return a.id < b.id;
}

bool cmp2(student a,student b){
    if(a.name == b.name) return a.id < b.id;
    return a.name < b.name;
}

bool cmp3(student a,student b){
    if(a.grade == b.grade) return a.id < b.id;
    return a.grade < b.grade;
}

int n,c;
int main(int argc, const char * argv[]) {
    cin >> n >> c;
    for (int i=0; i<n; i++) {
        cin >> stu[i].id >> stu[i].name >> stu[i].grade;
    }
    switch (c) {
        case 1:
            sort(stu, stu+n, cmp1);
            break;
        case 2:
            sort(stu, stu+n, cmp2);
            break;
        case 3:
            sort(stu, stu+n, cmp3);
            break;
        default:
            break;
    }
    for (int i=0; i<n; i++) {
        printf("%06d",stu[i].id);
        cout<<" "<<stu[i].name<<" "<<stu[i].grade<<endl;
    }
    return 0;
}

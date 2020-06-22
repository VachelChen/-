//
//  main.cpp
//  PAT_A1036
//
//  Created by VachelChen on 2020/6/19.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 10010;

struct stu{
    string name;
    char gender;
    string id;
    int grade;
}m[maxn],f[maxn];

bool cmp1(stu a, stu b){
    return a.grade < b.grade;
}

bool cmp2(stu a, stu b){
    return a.grade > b.grade;
}

int n;
int main(int argc, const char * argv[]) {
    cin >> n;
    int mnum = 0,fnum = 0;
    for (int i=0; i<n; i++) {
        stu temp;
        cin >> temp.name >> temp.gender >> temp.id >> temp.grade;
        if (temp.gender == 'M') {
            m[mnum++] = temp;
        }
        else{
            f[fnum++] = temp;
        }
    }
    sort(m,m+mnum,cmp1);
    sort(f,f+fnum,cmp2);
    
    if (!mnum || !fnum) {
        if (!fnum) {
            cout<<"Absent"<<endl;
        }
        else{
            cout<<f[0].name<<" "<<f[0].id<<endl;
        }
        
        if (!mnum) {
            cout<<"Absent"<<endl;
        }
        else{
            cout<<m[0].name<<" "<<m[0].id<<endl;
        }
        cout<<"NA"<<endl;
    }
    else{
        cout<<f[0].name<<" "<<f[0].id<<endl;
        cout<<m[0].name<<" "<<m[0].id<<endl;
        cout<<f[0].grade - m[0].grade<<endl;
    }
    return 0;
}

//
//  main.cpp
//  PAT_A1012
//
//  Created by VachelChen on 2020/5/18.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;
int n,m;

struct student{
    string id;
    int c;
    int m;
    int e;
    int a;
    int crank;
    int mrank;
    int erank;
    int arank;
}stu[2010];

string findID[2010];

bool cmpc(student a,student b){
    return a.c>b.c;
}

bool cmpm(student a,student b){
    return a.m>b.m;
}

bool cmpe(student a,student b){
    return a.e>b.e;
}

bool cmpa(student a,student b){
    return a.a>b.a;
}

char f[4];

int main(int argc, const char * argv[]) {
    f[0] = 'A';f[1] = 'C';f[2] = 'M';f[3] = 'E';
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        cin >> stu[i].id >> stu[i].c >> stu[i].m >> stu[i].e;
        double ave = (stu[i].c + stu[i].m + stu[i].e)*1.0/3.0;
        int zheng = (int)ave;
        if (ave - zheng >= 0.5) {
            stu[i].a = zheng+1;
        }
        else{
            stu[i].a = zheng;
        }
    }
    
    for (int i=0; i<m; i++) {
        cin >> findID[i];
    }
    
    sort(stu,stu+n,cmpe);
    stu[0].erank = 1;
    for (int i=1; i<n; i++) {
        if(stu[i].e == stu[i-1].e){
            stu[i].erank = stu[i-1].erank;
        }
        else{
            stu[i].erank = i+1;
        }
    }
    
    sort(stu,stu+n,cmpm);
    stu[0].mrank = 1;
    for (int i=1; i<n; i++) {
        if(stu[i].m == stu[i-1].m){
            stu[i].mrank = stu[i-1].mrank;
        }
        else{
            stu[i].mrank = i+1;
        }
    }
    
    sort(stu,stu+n,cmpc);
    stu[0].crank = 1;
    for (int i=1; i<n; i++) {
        if(stu[i].c == stu[i-1].c){
            stu[i].crank = stu[i-1].crank;
        }
        else{
            stu[i].crank = i+1;
        }
    }
    
    sort(stu,stu+n,cmpa);
    stu[0].arank = 1;
    for (int i=1; i<n; i++) {
        if(stu[i].a == stu[i-1].a){
            stu[i].arank = stu[i-1].arank;
        }
        else{
            stu[i].arank = i+1;
        }
    }
    
    
    for (int i=0; i<m; i++) {
        int j;
        for (j=0; j<n; j++) {
            if (stu[j].id == findID[i]) {
                int flag = 0;
                int ans = stu[j].arank;
                if (ans > stu[j].crank) {
                    flag = 1;
                    ans = stu[j].crank;
                }
                if (ans > stu[j].mrank) {
                    flag = 2;
                    ans = stu[j].mrank;
                }
                if (ans > stu[j].erank) {
                    flag = 3;
                    ans = stu[j].erank;
                }
                
                if(flag == 0){
                    cout<<stu[j].arank<<" "<<f[flag]<<endl;
                }
                else if(flag == 1){
                    cout<<stu[j].crank<<" "<<f[flag]<<endl;
                }
                else if(flag == 2){
                    cout<<stu[j].mrank<<" "<<f[flag]<<endl;
                }
                else if(flag == 3){
                    cout<<stu[j].erank<<" "<<f[flag]<<endl;
                }
                break;
            }
        }
        if(j == n)
            cout<<"N/A"<<endl;
    }
    return 0;
}

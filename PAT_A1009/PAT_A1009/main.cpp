//
//  main.cpp
//  PAT_A1009
//
//  Created by VachelChen on 2020/5/10.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

map<int,double> am;
map<int,double> bm;
map<int,double> cm;

struct factor{
    int k;
    int coe[2000];
    factor(){
        fill(coe,coe+2000,-1);
        k=0;
    }
};

bool cmp(int a, int b){
    return a>b;
}

//对于考试使用的编译器 map不能直接cin输入
int main(int argc, const char * argv[]) {
    factor a,b,c;
    bool flaga = true;
    bool flagb = true;
    int ak;
    int akk=0;
    cin >> ak;
    a.k = ak;
    for (int i=0; i<ak; i++) {
        double x;
        cin>>a.coe[i]>>x;
        if(x == 0){
            a.coe[i] = -1;
            //a.k--;
        }
        else{
            am[a.coe[i]] = x;
            akk++;
            flaga = false;
        }
    }
    int bk;
    int bkk=0;
    cin >> bk;
    b.k = bk;
    for (int i=0; i<bk; i++) {
        double x;
        cin>>b.coe[i]>>x;
        if(x == 0){
            b.coe[i] = -1;
            //b.k--;
        }
        else{
            bm[b.coe[i]] = x;
            bkk++;
            flagb = false;
        }
    }
    
    for (int i=0; i<a.k; i++) {
        for (int j=0; j<b.k; j++) {
            int x = a.coe[i]+b.coe[j];
            bool flag = false;
            for (int k=0; k<a.k*b.k; k++) {
                if(c.coe[k] == x){
                    cm[k] += am[a.coe[i]]*bm[b.coe[j]];
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                c.coe[c.k] = x;
                cm[c.k] = am[a.coe[i]]*bm[b.coe[j]];
                c.k++;
            }
        }
    }
    
    sort(c.coe, c.coe+c.k, cmp);
    int mmp=0;
    if(flaga || flagb){
        cout<<0;
    }
    else{
        for (int i=0; i<c.k; i++) {
            if(cm[i] != 0){
                mmp++;
            }
        }
        cout<<mmp;
    }
        
    for (int i=0; i<c.k; i++) {
        if(cm[i] != 0){
        cout<<" "<<c.coe[i]<<" ";
        printf("%.1f",cm[i]);
        }
    }
    
    cout<<endl;
    return 0;
}

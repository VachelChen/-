//
//  main.cpp
//  BJFU_241
//
//  Created by VachelChen on 2020/7/17.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#define ok 1
#define error -1
using namespace std;
const int maxn = 10010;

typedef struct
{
   int top[2], bot[2];        //栈顶和栈底指针
   int *V;                   //栈数组
   int m;                    //栈最大可容纳元素个数
}DblStack;

int InitDS(DblStack &ds,int m){
    ds.V = new int[maxn];
    if(!ds.V)   return error;
    ds.top[0] = -1;
    ds.top[1] = m;
    ds.bot[0] = 0;
    ds.bot[1] = m-1;
    ds.m = maxn;
    return ok;
}

bool EmptyDS(DblStack ds){
    if (ds.top[0]==-1 && ds.top[1] == ds.m) {
        return true;
    }
    else
        return false;
}

int InsertDS(DblStack &ds,bool flag,int m){
    for (int i=0; i<m; i++) {
        int x;
        cin >> x;
        if (!flag) {
            ds.V[++ds.top[0]] = x;
        }
        else{
            ds.V[--ds.top[1]] = x;
        }
    }
    return ok;
}

int PushDS(DblStack &ds,bool flag){
    if (EmptyDS(ds)) return error;
    else{
        if (!flag) {
            return ds.V[ds.top[0]--];
        }
        else{
            return ds.V[ds.top[1]++];
        }
    }
}


int main(int argc, const char * argv[]) {
    int m;
    while (cin >> m) {
        if(!m)  break;
        int e0,e1,d0,d1;
        cin >> e0 >> e1 >> d0 >> d1;
        DblStack ds;
        InitDS(ds, m);
        InsertDS(ds,0,e0);
        InsertDS(ds,1,e1);
        int a[maxn],b[maxn];
        for (int i=0; i<d0; i++) {
            a[i] = PushDS(ds, 0);
        }
        for (int i=0; i<d1; i++) {
            b[i] = PushDS(ds, 1);
        }
        cout<<(e0+e1 == m?1:0)<<endl;
        if (!d0) {
            cout<<(d0 == e0?0:1)<<endl;
        }
        else{
            cout<<a[0];
            for (int i=1; i<d0; i++) {
                cout<<" "<<a[i];
            }
            cout<<" "<<(d0 == e0?0:1)<<endl;
        }
        if (!d1) {
            cout<<(d1 == e1?0:1)<<endl;
        }
        else{
            cout<<b[0];
            for (int i=1; i<d1; i++) {
                cout<<" "<<b[i];
            }
            cout<<" "<<(d1 == e1?0:1)<<endl;
        }
    }
    return 0;
}

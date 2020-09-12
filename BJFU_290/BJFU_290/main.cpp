//
//  main.cpp
//  BJFU_290
//
//  Created by VachelChen on 2020/9/12.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#define maxn 100
using namespace std;

typedef struct node{
    int data;
    int count;
    node *llink,*rlink;
}node,*linklist;

int once;

void Create(linklist &t,int x){
    if (t) {
        if (t->data == x) {
            t->count++;
            return;
        }
        t->data<x?Create(t->rlink, x):Create(t->llink, x);
    }
    else{
        t = new node;
        t->data = x;
        t->count = 0;
        t->llink = NULL;
        t->rlink = NULL;
    }
}

void Search(linklist t,int x){
    if(t){
        Search(t->llink,x);
        if (!once) {
            once = 1;
            cout<<t->data;
        }
        else{
            cout<<" "<<t->data;
        }
        Search(t->rlink,x);
    }
}

void Show(linklist t){
    if(t){
        Show(t->llink);
        if (!once) {
            once = 1;
            cout<<t->count;
        }
        else{
            cout<<" "<<t->count;
        }
        Show(t->rlink);
    }
}

int main(int argc, const char * argv[]) {
    int n;
    while (cin >> n) {
        if(!n)  break;
        int a[maxn];
        for (int i=0; i<n; i++) {
            cin >> a[i];
        }
        int x;
        cin >> x;
        linklist t = NULL;
        for (int i=0; i<n; i++) {
            Create(t,a[i]);
        }
        Create(t, x);
        once = 0;
        Search(t,x);
        cout<<endl;
        once = 0;
        Show(t);
        cout<<endl;
    }
    return 0;
}

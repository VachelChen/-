//
//  main.cpp
//  BJFU_294
//
//  Created by VachelChen on 2020/9/13.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
using namespace std;

typedef struct node{
    int data;
    node *next;
}node,*linklist;

void Init(linklist &p){
    p = new node;
    p->next = NULL;
}

int main(int argc, const char * argv[]) {
    int n;
    while (cin >> n) {
        if(!n) break;
        linklist p,t;
        Init(p);
        t = p;
        for (int i=0; i<n; i++) {
            linklist s;
            s = new node;
            cin >> s->data;
            s->next = NULL;
            t->next = s;
            t = s;
        }
        linklist choose = p->next;
        linklist minp = choose->next;
        while (choose->next) {
            t = minp;
            while (t) {
                if (t->data<minp->data) {
                    minp = t;
                }
                t = t->next;
            }
            if(minp->data<choose->data){
                int temp = minp->data;
                minp->data = choose->data;
                choose->data = temp;
            }
            choose = choose->next;
            minp = choose->next;
        }
        t = p->next;
        while (t->next) {
            cout<<t->data<<" ";
            t = t->next;
        }
        cout<<t->data<<endl;
    }
    return 0;
}

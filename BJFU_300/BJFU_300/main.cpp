//
//  main.cpp
//  BJFU_300
//
//  Created by VachelChen on 2020/9/14.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
using namespace std;

typedef struct node{
    int data;
    node *next;
}node,*linklist;

void Init(linklist &l){
    l = new node;
    l->data = 0;
    l->next = NULL;
}

int Sreach(linklist list,int k){
    linklist p = list->next;
    for (int i=0; i<k; i++) {
        p = p->next;
        if (!p) {
            cout<<"0"<<endl;
            return 0;
        }
    }
    linklist q = list->next;
    while (p) {
        p = p->next;
        q = q->next;
    }
    cout<<q->data<<endl;
    return 1;
}

int main(int argc, const char * argv[]) {
    int n;
    while (cin >> n) {
        if(!n)  break;
        linklist list;
        Init(list);
        linklist t = list;
        for (int i=0; i<n; i++) {
            linklist s;
            s = new node;
            cin >> s->data;
            s->next = NULL;
            t->next = s;
            t = s;
        }
        int k;
        cin >> k;
        //假设我现在只有list
        Sreach(list,k);
    }
    return 0;
}

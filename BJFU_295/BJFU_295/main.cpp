//
//  main.cpp
//  BJFU_295
//
//  Created by VachelChen on 2020/9/13.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
using namespace std;

typedef struct node{
    int data;
    node *pre,*next;
}node,*linklist;

void Init(linklist &l){
    l = new node;
    l->pre = l->next = NULL;
}

int main(int argc, const char * argv[]) {
    int n;
    while (cin >> n) {
        if(!n)  break;
        linklist l,t;
        Init(l);
        t = l;
        for (int i=0; i<n; i++) {
            linklist s = new node;
            cin >> s->data;
            s->next = NULL;
            s->pre = t;
            t->next = s;
            t = s;
        }
        //sort
        linklist head,tail;
        head = l->next;
        tail = head;
        while (tail->next) {
            tail = tail->next;
        }
        while (1) {
            if(head!=tail){
                for (linklist i=head; i!=tail; i=i->next) {
                    if (i->data > i->next->data) {
                        int temp = i->next->data;
                        i->next->data = i->data;
                        i->data = temp;
                    }
                }
                tail = tail->pre;
            }
            else
                break;
            if (head!=tail) {
                for (linklist i=tail; i!=head; i=i->pre) {
                    if (i->data < i->pre->data) {
                        int temp = i->pre->data;
                        i->pre->data = i->data;
                        i->data = temp;
                    }
                }
                head = head->next;
            }
            else
                break;
    }
    //show
        t = l->next;
        while (t->next) {
            cout<<t->data<<" ";
            t = t->next;
        }
        cout<<t->data<<endl;
    }
    return 0;
}

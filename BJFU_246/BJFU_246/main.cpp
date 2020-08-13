//
//  main.cpp
//  BJFU_246
//
//  Created by VachelChen on 2020/7/28.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
using namespace std;

struct node{
    int data;
    node *next;
};

struct ListQueue{
    node *front;
    node *rear;
};

void Init(ListQueue &q){
    q.front = new node;
    q.rear = q.front;
    q.front->next = NULL;
}

void push(ListQueue &q,int x){
    node *t;
    t = new node;
    t->data = x;
    t->next = NULL;
    q.rear->next = t;
    q.rear = t;
}

int Pop(ListQueue &q){
    if(q.front == q.rear) return 0;
    node *t = q.front->next;
    int ans = t->data;
    q.front->next = t->next;
    delete t;
    if (!q.rear) {
        q.rear = q.front;
    }
    return ans;
}


int main(int argc, const char * argv[]) {
    int n,m;
    while (cin>>n>>m) {
        if(!n && !m)    break;
        ListQueue q;
        Init(q);
        for (int i=0; i<n; i++) {
            int x;
            cin >> x;
            push(q,x);
        }
        for (int i=0; i<m; i++) {
            cout<<Pop(q)<<" ";
        }
        if (n == m)
            cout<<0<<endl;
        else
            cout<<1<<endl;
    }
    return 0;
}

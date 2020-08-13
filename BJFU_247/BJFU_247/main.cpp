//
//  main.cpp
//  BJFU_247
//
//  Created by VachelChen on 2020/7/29.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#define ok 1
#define error 0
#define maxsize 110
using namespace std;

struct SqQueue{
    int *base;
    int head;
    int rear;
    int tag;
};

int Init(SqQueue &q){
    q.base = new int[maxsize];
    if(!q.base) return error;
    q.head = q.rear = q.tag = 0;
    return ok;
}

int enqueue(SqQueue &q,int x){
    if (q.tag && q.head == q.rear)  return error;
    q.base[q.rear] = x;
    q.rear = (q.rear+1) % maxsize;
    if (!q.tag) {
        q.tag = 1;
    }
    return ok;
}

int dlqueue(SqQueue &q){
    if (!q.tag && q.head == q.rear) return error;
    int ans = q.base[q.head];
    q.head = (q.head+1+maxsize)%maxsize;
    if (q.tag) {
        q.tag = 0;
    }
    return ans;
}
int main(int argc, const char * argv[]) {
    int n;
    while (cin >> n) {
        if(!n)  break;
        SqQueue q;
        Init(q);
        for (int i=0; i<n; i++) {
            int x;
            cin >> x;
            enqueue(q, x);
        }
        if (n)  cout<<dlqueue(q);
        for (int i=1; i<n; i++) {
            cout<<" "<<dlqueue(q);
        }
        cout<<endl;
    }
    return 0;
}

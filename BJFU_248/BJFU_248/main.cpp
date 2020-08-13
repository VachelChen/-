//
//  main.cpp
//  BJFU_248
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
};

int Init(SqQueue &q){
    q.base = new int[maxsize];
    if(!q.base) return error;
    q.head = q.rear = 0;
    return ok;
}

int enqueue(SqQueue &q,int x){
    if (q.rear == (q.head-1+maxsize)%maxsize)  return error;
    q.base[q.head] = x;
    q.head = (q.head-1+maxsize) % maxsize;
    return ok;
}

int dlqueue(SqQueue &q){
    if (q.head == q.rear) return error;
    int ans = q.base[q.rear];
    q.rear = (q.rear-1+maxsize)%maxsize;
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

//
//  main.cpp
//  BJFU_255
//
//  Created by VachelChen on 2020/8/13.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#define maxsize 1000
#define ok 1
#define error 0
using namespace std;

struct sqQueue{
    int *base;
    int front;
    int rear;
};

int InitQueue(sqQueue &q){
    q.base = new int[maxsize];
    if(!q.base) return error;
    q.front = q.rear = 0;
    return ok;
}

int Push(sqQueue &q,int x){
    if((q.rear+1)%maxsize == q.front) return error;
    q.base[q.rear] = x;
    q.rear = (q.rear+1)%maxsize;
    return ok;
}

int Front(sqQueue q){
    if (q.rear == q.front) return error;
    return q.base[q.front];
}

int Pop(sqQueue &q){
    if (q.rear == q.front) return error;
    int x =  q.base[q.front];
    q.front = (q.front+1)%maxsize;
    return x;;
}

int a[maxsize]={0};
int b[maxsize][3];
bool flag ;
int ans ;

void bfs(sqQueue &q){
    while (q.front != q.rear) {
        int temp = Front(q);
        Pop(q);
        if (temp == ans) {
            flag = true;
            return ;
        }
        for (int i=0; i<3; i++) {
            if (b[temp][i] && !a[b[temp][i]]) {
                a[b[temp][i]] = 1;
                Push(q, b[temp][i]);
            }
        }
    }
}


int main(int argc, const char * argv[]) {
    int n;
    while (cin>>n) {
        if(!n)  break;
        flag = false;
        for (int i=1; i<=n; i++) {
            a[i] = 0;
        }
        for (int i=1; i<=n; i++) {
            cin >> b[i][0] >> b[i][1] >> b[i][2];
        }
        cin >> ans;
        sqQueue q;
        InitQueue(q);
        a[1] =1;
        Push(q, 1);
        bfs(q);
        if (flag) {
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}

//
//  main.cpp
//  BJFU_234
//
//  Created by VachelChen on 2020/7/12.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#define ok 1
#define error 0;

const int maxn = 110000;
using namespace std;

struct sqlist{
    int *elem;
    int length;
};

int InitSqlist(sqlist &l){
    l.elem = new int[maxn];
    if(!l.elem) return error;
    l.length = 0;
    return ok;
}

int createSqlit(sqlist &l,int n){
    for (int i=0; i<n; i++) {
        cin >> l.elem[i];
        l.length++;
    }
    return ok;
}

int deleteElem(sqlist &l,int n){
    int m;
    cin >> m;
    int index = 0;
    for (int i=0; i<n; i++) {
        if (l.elem[i] != m) {
            l.elem[index++] = l.elem[i];
        }
    }
    l.length = index;
    return ok;
}

void printList(sqlist l){
    int i;
    for (i=0; i<l.length-1; i++) {
        cout<<l.elem[i]<<" ";
    }
    cout<<l.elem[i]<<endl;
}

int main(int argc, const char * argv[]) {
    int n;
    while (cin >> n) {
        if(!n)   break;
        sqlist l;
        InitSqlist(l);
        createSqlit(l,n);
        deleteElem(l,n);
        printList(l);
    }
    return 0;
}

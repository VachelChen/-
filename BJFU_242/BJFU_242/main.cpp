//
//  main.cpp
//  BJFU_242
//
//  Created by VachelChen on 2020/7/21.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#define maxn 110000
#define ok 1
#define error 0
using namespace std;

struct SqStack{
    int* base;
    int* top;
    int maxsize;
};

int InitStack(SqStack &s){
    s.base = new int[maxn];
    if(!s.base) return error;
    s.top = s.base;
    s.maxsize = maxn;
    return ok;
}

int PushStack(SqStack &s,int c){
    if (s.top-s.base == s.maxsize) return error;
    else
        *s.top++ = c;
    return ok;
}

int PopStack(SqStack &s){
    if (s.top == s.base) return error;
    else{
        s.top--;
    }
    return ok;
}

int FrontStack(SqStack s){
    if (s.top == s.base)
        return error;
    else{
        return *(s.top-1);
    }
}

bool EmptyStack(SqStack s){
    if (s.top == s.base) {
        return true;
    }
    return false;
}


int main(int argc, const char * argv[]) {
    int n;
    while (cin >> n) {
        if(!n)  break;
        SqStack s;
        InitStack(s);
        int a[n];
        for (int i=0; i<n; i++) {
            cin >> a[i];
        }
        for (int i=0; i<n; i++) {
            if (a[i] != -1) {
                PushStack(s, a[i]);
            }
            else{
                if (EmptyStack(s)) {
                    cout<<"POP ERROR"<<endl;
                    break;
                }
                else{
                    cout<<FrontStack(s)<<endl;
                    PopStack(s);
                }
            }
        }
    }
    return 0;
}

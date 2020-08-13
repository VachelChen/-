//
//  main.cpp
//  BJFU_245
//
//  Created by VachelChen on 2020/7/26.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#define ok 1
#define error 0
#define maxn 1100
using namespace std;

struct Sqstack{
    char *top;
    char *base;
    int maxsize;
};

int Init(Sqstack &s){
    s.base = new char[maxn];
    if(!s.base) return error;
    s.top = s.base;
    s.maxsize = maxn;
    return ok;
}

int push(Sqstack &s,char x){
    if (s.top-s.base == s.maxsize) {
        return error;
    }
    *s.top++ = x;
    return ok;
}

char pop(Sqstack &s){
    if (s.top == s.base) {
        return 'x';
    }
    return *(--s.top);
}

int main(int argc, const char * argv[]) {
    string str;
    Sqstack s;
    while (cin >> str) {
        Init(s);
        if(str == "0") break;
        int i;
        for (i=0; i<str.size(); i++) {
            if(str[i] == 'I')
                push(s, 'I');
            else if(str[i] == 'O'){
                if('x' == pop(s)){
                    break;
                }
            }
        }
        if (i == str.size()) {
            cout<<"TRUE"<<endl;
        }
        else
            cout<<"FALSE"<<endl;
    }
    return 0;
}

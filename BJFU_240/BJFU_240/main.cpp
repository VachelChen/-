//
//  main.cpp
//  BJFU_240
//
//  Created by VachelChen on 2020/7/16.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#define ok 1
#define error 0
#define MAXSIZE 1000
using namespace std;

typedef struct{
    char *base;
    char *top;
    int stacksize;
}SqStack1;

int InitStack1(SqStack1 &s){
    s.base = new char[MAXSIZE];
    if(!s.base) return error;
    s.top = s.base;
    s.stacksize = MAXSIZE;
    return ok;
}

int PushStack1(SqStack1 &s,char e){
    if(s.top-s.base == s.stacksize) return error;
    *s.top++ = e;
    return ok;
}

int Pop1(SqStack1 &s,char &e){
    if(s.top == s.base) return error;
    e = *--s.top;
    return ok;
}

double Top1(SqStack1 s){
    if (s.top!=s.base) {
        return *(s.top-1);
    }
    return error;
}

bool Empty1(SqStack1 s){
    if (s.top == s.base) {
        return true;
    }
    else
        return false;
}

int StackSize(SqStack1 s){
    return s.top-s.base;
}


typedef struct{
    double *base;
    double *top;
    int stacksize;
}SqStack2;

int InitStack2(SqStack2 &s){
    s.base = new double[MAXSIZE];
    if(!s.base) return error;
    s.top = s.base;
    s.stacksize = MAXSIZE;
    return ok;
}

int PushStack2(SqStack2 &s,double e){
    if(s.top-s.base == s.stacksize) return error;
    *s.top++ = e;
    return ok;
}

int Pop2(SqStack2 &s,double &e){
    if(s.top == s.base) return error;
    e = *--s.top;
    return ok;
}

double Top2(SqStack2 s){
    if (s.top!=s.base) {
        return *(s.top-1);
    }
    return error;
}

bool Empty2(SqStack2 s){
    if (s.top == s.base) {
        return true;
    }
    else
        return false;
}

char Percede(char a,char b){
    if ((a =='(' && b == ')')||(a == '='&&b == '='))
        return '=';
    else if (a=='(' || a=='=' || b=='(' || ((a=='+'||a=='-') && (b=='*'||b=='/')))
        return '<';//共四种小于情况
    else
        return '>';
}


int main(int argc, const char * argv[]) {
    string str;
    while (cin >> str) {
        if (str == "=") break;
        double t=0;
        SqStack1 s1;
        SqStack2 s2;
        InitStack1(s1);InitStack2(s2);
        int index = 0;
        int xiao = 0;
        double x=0.1;
        bool flag = 0;
        PushStack1(s1, '=');
        //进行算术表达式求值
        while (index<str.size()) {
            if (str[index]-'0'<=9 && str[index]-'0'>=0) {
                if (xiao) {
                    for (int j=1; j<xiao; j++) {
                        x *= 0.1;
                    }
                    t = t+(str[index]-'0')*x;
                    xiao++;
                }
                else{
                    flag = 1;
                    t = t*10+(str[index]-'0');
                }
            }
            else if (str[index]=='.'){
                xiao = 1;
            }
            else{
                if (flag) {
                    PushStack2(s2, t);
                    xiao = 0;
                    x = 0.1;
                    t=0;
                    flag = 0;
                }
                while(1){
                    if (Percede(Top1(s1),str[index]) == '<') {
                        PushStack1(s1, str[index]);
                        break;
                    }
                    else if(Percede(Top1(s1),str[index]) == '>'){
                        char c;
                        Pop1(s1, c);
                        double a,b,ans=0;
                        Pop2(s2, b);
                        Pop2(s2, a);
                        switch (c) {
                            case '+':
                                ans = a+b;
                                break;
                            case '-':
                                ans = a-b;
                                break;
                            case '*':
                                ans = a*b;
                                break;
                            case '/':
                                ans = a/b;
                                break;
                            default:
                                break;
                        }
                        PushStack2(s2, ans);
                    }
                    else{
                        char c;
                        Pop1(s1, c);
                        break;
                    }
                }
            }
            index++;
        }
        printf("%.2lf\n",Top2(s2));
    }
    return 0;
}

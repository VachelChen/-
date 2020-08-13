//
//  main.cpp
//  BJFU_244
//
//  Created by VachelChen on 2020/7/25.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#define maxnsize 1000
#define ok 0
#define error -1
using namespace std;

struct Sqstack{
    double *head;
    double *base;
    int maxsize;
};

int InitSqtack(Sqstack &s){
    s.base = new double[maxnsize];
    if(!s.base) return error;
    s.head = s.base;
    s.maxsize = maxnsize;
    return ok;
}

double PushSqtack(Sqstack &s,double x){
    if (s.head - s.base == s.maxsize) {
        return error;
    }
    *s.head++ = x;
    return ok;
}

double FrontSqtack(Sqstack s){
    if (s.head == s.base) {
        return error;
    }
    return *(s.head-1);
}

double PopSqtack(Sqstack &s){
    if (s.head == s.base) {
        return error;
    }
    return *(--s.head);
}

int main(int argc, const char * argv[]) {
    string str;
    getline(cin,str);
    while(str != "="){
        Sqstack s;
        InitSqtack(s);
        double m=0;
        int e=0;
        bool f = false;
        for (int i=0; i<str.size(); i++) {
            if (str[i]-'0'<=9 && str[i]-'0'>=0) {
                m *= 10;
                m += (str[i]-'0');
                e *= 10;
                f = true;
            }
            else if(str[i] == '.'){
                e = 1;
            }
            else{
                if(e)   m /= e;
                if (f) {
                    PushSqtack(s, m);
                    f = false;
                }
                m=0;
                e=0;
                if (str[i] == '+'||str[i] == '-'||str[i] == '*'||str[i] == '/') {
                    double b = PopSqtack(s);
                    double a = PopSqtack(s);
                    switch (str[i]) {
                        case '+':
                            PushSqtack(s, a+b);
                            break;
                        case '-':
                            PushSqtack(s, a-b);
                            break;
                        case '*':
                            PushSqtack(s, a*b);
                            break;
                        case '/':
                            PushSqtack(s, a/b);
                            break;
                        default:
                            break;
                    }
                }
            }
        }
        printf("%.2f\n",FrontSqtack(s));
        getline(cin,str);
    }
    
    return 0;
}

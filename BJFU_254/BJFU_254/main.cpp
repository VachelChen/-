//
//  main.cpp
//  BJFU_254
//
//  Created by VachelChen on 2020/8/5.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
using namespace std;

typedef struct cStackNode{
    char data;
    cStackNode *next;
}*cstack,csnode;

void PushCS(cstack &l,char x){
    cstack t;
    t = new csnode;
    t->data = x;
    t->next = l;
    l = t;
}

char Pop(cstack &l){
    cstack t;
    char ans;
    t = l;
    l=l->next;
    ans = t->data;
    delete t;
    return ans;
}


char Percede(char a,char b){
    if ((a =='(' && b == ')')||(a == '='&&b == '='))
        return '=';    //括号和等号的情况为等于
    else if (a=='(' || a=='=' || b=='(' || ((a=='+'||a=='-') && (b=='*'||b=='/')))
        return '<';    //共四种小于情况：a、b的左括号情况，a的=情况，还有先乘除后加减的情况
    else
        return '>';
}

int main(int argc, const char * argv[]) {
    string str;
    while (getline(cin,str)) {
        if(str == "=")  break;
        cstack s;
        s = NULL;
        PushCS(s, '=');
        for(int i=0;str[i]!='\0';i++){
            if (str[i]-'0'<=9 && str[i]-'0'>=0) {
                cout<<str[i];
            }
            else{
                if (!s) {
                    PushCS(s, str[i]);
                }
                else{
                    while(1){
                        if (Percede(s->data, str[i]) == '<') {
                            PushCS(s, str[i]);
                            break;
                        }
                        else if(Percede(s->data, str[i]) == '>'){
                            cout<<Pop(s);
                        }
                        else{
                            Pop(s);
                            break;
                        }
                    }
                }
            }
        }
        while (s) {
            cout<<Pop(s);
        }
        cout<<endl;
    }
    return 0;
}

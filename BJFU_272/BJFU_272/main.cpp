//
//  main.cpp
//  BJFU_272
//
//  Created by VachelChen on 2020/9/4.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#define maxn 100
using namespace std;

typedef struct Tnode{
    char data;
    Tnode *left,*right;
}Tnode,*tree;

typedef struct {
    tree *front;
    tree *rear;
    int maxsize;
}SqStack1;

void Init1(SqStack1 &s){
    s.rear = new tree[maxn];
    if (!s.rear) {
        return ;
    }
    s.front = s.rear;
    s.maxsize = maxn;
}

void Push1(SqStack1 &s,tree x){
    if(s.front - s.rear == maxn)    return;
    *s.front = x;
    s.front++;
}

tree Pop1(SqStack1 &s){
    s.front--;
    return *s.front;
}

tree Top1(SqStack1 s){
    return *(s.front-1);
}

typedef struct {
    char *front;
    char *rear;
    int maxsize;
}SqStack2;

void Init2(SqStack2 &s){
    s.rear = new char[maxn];
    s.front = s.rear;
    s.maxsize = maxn;
}

void Push2(SqStack2 &s,char x){
    if(s.front - s.rear == maxn)
        return;
    *s.front = x;
    s.front++;
}

int Pop2(SqStack2 &s){
    s.front--;
    return *s.front;
}

int Top2(SqStack2 s){
    return *(s.front-1);
}

char Precede(char a,char b){
    if ((a=='(' && b ==')')||(a=='=' && b=='=')) {
        return '=';
    }
    else if(a=='(' || a == '=' || b=='(' || ((a=='+'||a=='-')&&(b=='*'||b=='/'))){
        return '<';
    }
    else
        return '>';
}

void CreateTree(tree &t,tree a,tree b,char c){
    t = new Tnode;
    t->left = a;
    t->right = b;
    t->data = c;
}

int value(tree t){
    int l,r;
    l = 0;r = 0;
    if (!t->left && !t->right) {
        return t->data-'0';
    }
    else{
        l = value(t->left);
        r = value(t->right);
        if (t->data == '+') return l+r;
        else if(t->data == '-') return l-r;
        else if(t->data == '*') return l*r;
        else{
            return l/r;
        }
    }
}


int main(int argc, const char * argv[]) {
    char str[maxn];
    while (cin >> str) {
        if(str[0] == '=' && str[1] == '\0') break;
        SqStack1 treestack;
        SqStack2 treenode;
        Init1(treestack);Init2(treenode);
        tree t;
        int x=0;
        Push2(treenode, '=');
        while (str[x] != '\0') {
            if (str[x]-'0' >=0 && str[x]-'0' <= 9) {
                CreateTree(t,NULL,NULL,str[x]);
                Push1(treestack, t);
                x++;
            }
            else{
                switch (Precede(Top2(treenode),str[x])) {
                    case '<':
                        Push2(treenode, str[x]);
                        x++;
                        break;
                        
                    case '=':
                        Pop2(treenode);
                        x++;
                        break;
                        
                    case '>':
                        char c = Pop2(treenode);
                        tree b = Pop1(treestack);
                        tree a = Pop1(treestack);
                        CreateTree(t, a,b,c);
                        Push1(treestack, t);
                        break;
                }
            }
        }
        cout<<value(t)<<endl;
    }
    return 0;
}

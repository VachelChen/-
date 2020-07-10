//
//  main.cpp
//  BJFU_224
//
//  Created by VachelChen on 2020/7/1.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
using namespace std;

typedef struct Pnode{
    int length;
    int c;
    int e;
    Pnode *next;
}*LinkList;

void InitList(LinkList &l){
    l = new Pnode;
    l->next = NULL;
    l->length = 0;
}

void CreateList(LinkList &l,int x){
    InitList(l);
    LinkList t=l,s;
    for (int i=0; i<x; i++) {
        s = new Pnode;
        cin >> s->c;
        cin >> s->e;
        s->next = NULL;
        t->next = s;
        t = s;
    }
    l->length = x;
}

void Order(LinkList &l){
    for (int i=0; i<l->length-1; i++) {
        LinkList t = l->next;
        for (int j=0; j<l->length-i-1; j++) {
            if (t->e < t->next->e) {
                int tc,te;
                tc = t->next->c;  te = t->next->e;
                t->next->c = t->c;  t->next->e = t->e;
                t->c = tc;  t->e = te;
            }
            t = t->next;
        }
    }
}


LinkList add(LinkList &a,LinkList &b){
    LinkList pa=a->next,pb=b->next,c=a,pc=c;
    while (pa && pb) {
        if (pa->e > pb->e) {
            pc->next = pa;
            pc = pa;
            pa = pa->next;
        }
        else if(pa->e == pb->e){
            pc->next = pa;
            pa->c += pb->c;
            pc = pa;
            pa = pa->next;
            pb = pb->next;
        }
        else{
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }
    }
    pc->next = pa?pa:pb;
    return c;
}

LinkList sub(LinkList &a,LinkList &b){
    LinkList pb=b->next;
    while (pb) {
        pb->c *=(-1);
        pb = pb->next;
    }
    return add(a, b);
}

LinkList mul(LinkList &a,LinkList &b){
    LinkList pa=a->next,pb=b->next;
    LinkList c,temp;
    InitList(c);
    InitList(temp);
    LinkList s;
    while (pa) {
        while (pb) {
            s = new Pnode;
            s->c = pa->c*pb->c;
            s->e = pa->e+pb->e;
            s->next = NULL;
            temp->next = s;
            c = add(c, temp);
            pb = pb->next;
        }
        pb = b->next;
        pa = pa->next;
    }
    Order(c);
    return c;
}

void der(LinkList &a,LinkList &b){
    LinkList pa=a->next,pb=b->next;
    while (pa) {
        pa->c *= pa->e;
        pa->e--;
        pa = pa->next;
    }
    while (pb) {
        pb->c *= pb->e;
        pb->e--;
        pb = pb->next;
    }
    
}

void Output(LinkList l){
    LinkList temp = l->next;
    bool flag = false;
    while (temp) {
        if (temp->c == 0) {
            temp = temp->next;
            continue;
        }
        if (flag) {
            if (temp->c == 0) {
                temp = temp->next;
                continue;
            }
            else if (temp->c > 0){
                cout<<"+";
            }
        }
        cout<<temp->c;
        if (temp->e != 0) {
            cout<<"x^"<<temp->e;
        }
        temp = temp->next;
        flag = true;
    }
    if (!flag) {
        cout<<"0";
    }
    cout<<endl;
}

int main(int argc, const char * argv[]) {
    int n,a,b;
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        scanf("%d %d",&a,&b);
        LinkList x1,x2,ans;
        CreateList(x1,a);
        CreateList(x2,b);
        Order(x1);
        Order(x2);
        char c;
        cin >> c;
        switch(c){
            case '+' :   ans = add(x1,x2);  Output(ans);break;
            case '-' :   ans = sub(x1,x2);  Output(ans);break;
            case '*' :   ans = mul(x1,x2);  Output(ans);break;
            case '\'':   der(x1,x2);  Output(x1);  Output(x2);break;
        }
    }
    
    return 0;
}
 

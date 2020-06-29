//
//  main.cpp
//  BJFU_010
//
//  Created by VachelChen on 2020/6/26.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#define error -1
#define ok 1
using namespace std;

struct book{
    string id;
    string name;
    double price;
};

typedef struct Lnode{
    int length;
    book data;
    Lnode *next;
}Lnode,*LinkList;

int InitL(LinkList &l){
    l = new Lnode;
    l->next = NULL;
    return ok;
}

int createL(LinkList &l){
    LinkList r;
    r = l;
    string id0,name0;
    double price0;
    int index = 1;
    while (cin >> id0 >> name0 >> price0) {
        if (id0 == "0" && name0 == "0" && price0 == 0 ) {
            return ok;
        }
        else{
            LinkList q = new Lnode;
            q->data.id = id0;
            q->data.name = name0;
            q->data.price = price0;
            q->next = NULL;
            r->next = q;
            r = q;
            l->length = index;
            index++;
        }
    }
    return ok;
}

int printL(LinkList &l){
    LinkList t;
    cout<<l->length<<endl;
    t = l->next;
    while (t) {
        cout<<t->data.id<<" "<<t->data.name<<" ";
        printf("%.2lf\n",t->data.price);
        t = t->next;
    }
    return ok;
}

int main(int argc, const char * argv[]) {
    LinkList l;
    InitL(l);
    createL(l);
    printL(l);
    return 0;
}

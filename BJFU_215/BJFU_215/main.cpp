//
//  main.cpp
//  BJFU_215
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
    Lnode(){
        length = 0;
    }
}Lnode,*LinkList;

int initList(LinkList &l){
    l = new Lnode;
    l->next = NULL;
    return ok;
};

int createList(LinkList &l){
    LinkList r,q;
    r = l;
    string id0,name0;
    double price0;
    while (cin >> id0 >> name0 >> price0) {
        if (id0 == "0" && name0 == "0" && price0 == 0) {
            return ok;
        }
        else{
            q = new Lnode;
            q->next = NULL;
            q->data.id = id0;
            q->data.name = name0;
            q->data.price = price0;
            r->next = q;
            r = q;
            l->length++;
        }
    }
    return ok;
}

int sortList(LinkList &l){
    for (int i=0; i<l->length-1; i++) {
        LinkList p = l->next;
        for (int j=0; j<l->length-i-1; j++) {
            if (p->data.price < p->next->data.price) {
                book t = p->data;
                p->data = p->next->data;
                p->next->data = t;
            }
            p=p->next;
        }
    }
    return ok;
}

int printList(LinkList l){
    LinkList t;
    t = l->next;
    while(t){
        cout<<t->data.id<<" "<<t->data.name<<" ";
        printf("%.2lf\n",t->data.price);
        t = t->next;
    }
    return ok;
}

int main(int argc, const char * argv[]) {
    LinkList l;
    initList(l);
    createList(l);
    sortList(l);
    printList(l);
    return 0;
}

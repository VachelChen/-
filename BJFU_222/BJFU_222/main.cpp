//
//  main.cpp
//  BJFU_222
//
//  Created by VachelChen on 2020/6/29.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
using namespace std;

struct book{
    string id;
    string name;
    double price;
};

typedef struct Lnode{
    book data;
    int length;
    Lnode *next;
    Lnode(){
        length = 0;
    }
}*LinkList;

void InitList(LinkList &l){
    l = new Lnode;
    l->length = 0;
    l->next = NULL;
}

void CreateList(LinkList &l){
    int n;
    cin >> n;
    LinkList t=l,s;
    for (int i=0; i<n; i++) {
        s = new Lnode;
        s->next = NULL;
        cin >> s->data.id >> s->data.name >> s->data.price;
        t->next = s;
        t = s;
        l->length++;
    }
}


void OutPut(LinkList l){
    LinkList temp;
    temp = l->next;
    while (temp) {
        cout<<temp->data.id<<" "<<temp->data.name<<" ";
        printf("%.2lf\n",temp->data.price);
        temp = temp->next;
    }
}

void DeleteList(LinkList &l){
    int x;
    cin >> x;
    if (x<1 || x>l->length) {
        cout<<"Sorry，the position to be deleted is invalid!"<<endl;
        return ;
    }
    else{
        LinkList f = l,b = l;
        int front = x-1,behind = x;
        while (front--) {
            f = f->next;
        }
        while (behind--) {
            b = b->next;
        }
        f->next = b->next;
        delete b;
        OutPut(l);
    }
}

int main(int argc, const char * argv[]) {
    LinkList l;
    InitList(l);
    CreateList(l);
    DeleteList(l);
    return 0;
}


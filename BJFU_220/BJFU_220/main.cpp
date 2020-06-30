//
//  main.cpp
//  BJFU_220
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

void InsertList(LinkList &l){
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

void FindList(LinkList l){
    int m;
    cin >> m;
    for (int i=0; i<m; i++) {
        int x;
        cin >> x;
        if (x < 1 || x>l->length) {
            cout<<"Sorry，the book on the best position doesn't exist!"<<endl;
        }
        else{
            LinkList temp;
            temp = l;
            while (x--) {
                temp = temp->next;
            }
            cout<<temp->data.id<<" "<<temp->data.name<<" ";
            printf("%.2lf\n",temp->data.price);
        }
    }
}

int main(int argc, const char * argv[]) {
    LinkList l;
    InitList(l);
    InsertList(l);
    FindList(l);
    return 0;
}

//
//  main.cpp
//  BJFU_217
//
//  Created by VachelChen on 2020/6/28.
//  Copyright © 2020 VachelChen. All rights reserved.
//


#include <iostream>
using namespace std;

struct book{
    string id;
    string name;
    double price;
};

typedef struct node{
    book data;
    int length;
    node *next;
    node(){
        length = 0;
    }
}*LinkList;

void InitList(LinkList &l){
    l = new node;
    l->length = 0;
    l->next = NULL;
}

void ListInsert(LinkList &l){
    LinkList s;
    book temp;
    int n;
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        cin >> temp.id >> temp.name >> temp.price;
        s = new node;
        s->data = temp;
        s->next = l->next;
        l->next = s;
        l->length++;
    }
}

void outPut(LinkList l){
    LinkList temp = l->next;
    while (temp) {
        cout<<temp->data.id<<" "<<temp->data.name<<" ";
        printf("%.2lf\n",temp->data.price);
        temp = temp->next;
    }
}


int main(int argc, const char * argv[]) {
    LinkList l;
    InitList(l);
    ListInsert(l);
    outPut(l);
    return 0;
}

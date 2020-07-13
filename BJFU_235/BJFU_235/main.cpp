//
//  main.cpp
//  BJFU_235
//
//  Created by VachelChen on 2020/7/12.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
const int maxn = 100010;
int a[maxn];
typedef struct node{
    int data;
    node *next;
}*LinkList;

void InitList(LinkList &l){
    l = new node;
    l->next = NULL;
}

void createList(LinkList &l,int n){
    LinkList t=l,s;
    for (int i=0; i<n; i++) {
        InitList(s);
        cin >> s->data;
        t->next = s;
        t = s;
    }
}

void deleteElem(LinkList &l){
    LinkList temp = l->next,head = l;
    while (temp) {
        a[abs(temp->data)]++;
        if (a[abs(temp->data)]>1) {
            head->next = temp->next;
            delete temp;
            temp = head->next;
        }
        else{
            head=head->next;
            temp=temp->next;
        }
    }
}
void printList(LinkList &l){
    LinkList temp=l->next;
    while (temp->next) {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<temp->data<<endl;
}

int main(int argc, const char * argv[]) {
    int n;
    while (cin >> n) {
        if(!n)  break;
        memset(a, 0, sizeof(a));
        LinkList l;
        InitList(l);
        createList(l,n);
        deleteElem(l);
        printList(l);
    }
    return 0;
}

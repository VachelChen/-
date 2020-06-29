//
//  main.cpp
//  BJFU_218
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

void ListInsert(LinkList &l,double &maxn,int &cnt){
    LinkList s,t=l;
    book temp;
    int n;
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        cin >> temp.id >> temp.name >> temp.price;
        
        if (temp.price > maxn) {
            maxn = temp.price;
            cnt = 1;
        }
        else if(temp.price == maxn){
            cnt++;
        }
        
        s = new node;
        s->data = temp;
        s->next = NULL;
        t->next = s;
        t = s;
        l->length++;
    }
}

void outPut(LinkList l,double &maxn,int cnt){
    cout<<cnt<<endl;
    LinkList temp = l->next;
    while (temp) {
        if (temp->data.price == maxn) {
            cout<<temp->data.id<<" "<<temp->data.name<<" ";
            printf("%.2lf\n",temp->data.price);
        }
        temp = temp->next;
    }
}


int main(int argc, const char * argv[]) {
    LinkList l;
    InitList(l);
    double maxn = 0;
    int cnt = 0;
    ListInsert(l,maxn,cnt);
    outPut(l,maxn,cnt);
    return 0;
}

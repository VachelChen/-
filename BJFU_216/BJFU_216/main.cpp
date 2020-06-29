//
//  main.cpp
//  BJFU_216
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

void ListInsert(LinkList &l,double &total){
    LinkList s,t=l;
    book temp;
    while(cin >> temp.id >> temp.name >> temp.price){
        if (temp.id == "0" && temp.name == "0" && temp.price == 0) {
            return ;
        }
        total += temp.price;
        s = new node;
        s->data = temp;
        s->next = NULL;
        t->next = s;
        t = s;
        l->length++;
    }
}

void changeList(LinkList &l,double avg){
    LinkList temp = l->next;
    while (temp) {
        if (temp->data.price < avg) {
            temp->data.price *= 1.2;
        }
        else{
            temp->data.price *= 1.1;
        }
        temp = temp->next;
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
    double total=0,avg=0;
    LinkList l;
    InitList(l);
    ListInsert(l,total);
    avg = total/l->length;
    printf("%.2lf\n",avg);
    changeList(l,avg);
    outPut(l);
    return 0;
}

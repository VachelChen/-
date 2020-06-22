//
//  main.cpp
//  BJFU_003
//
//  Created by VachelChen on 2020/6/17.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <stdio.h>
#include <string.h>
const int maxn = 1010;

struct book{
    char id[20];
    char name[30];
    double price;
};

struct BookList{
    book *elem;
    int length;
};

void initList(BookList &l){
    l.elem = new book[maxn];
    if (!l.elem) {
        return ;
    }
    l.length = 0;
}

void insertList(BookList &l,int i,book e){
    if (i<1 || i>l.length+1) {
        return;
    }
    if (l.length == maxn) {
        return;
    }
    for (int j = l.length; j>i; j--) {
        l.elem[j] = l.elem[j-1];
    }
    l.elem[i] = e;
    l.length++;
}

int main(){
    BookList l;
    initList(l);
    book temp;
    double total = 0;
    scanf("%s %s %lf",temp.id,temp.name,&temp.price);
    while (strcmp(temp.id, "0")!=0 || strcmp(temp.name, "0")!=0 || temp.price != 0) {
        total += temp.price;
        insertList(l,l.length+1,temp);
        scanf("%s %s %lf",temp.id,temp.name,&temp.price);
    }
    printf("%.2lf\n",total/l.length);
    for (int i=1; i<=l.length; i++) {
        if (l.elem[i].price < total/l.length) {
            l.elem[i].price *= 1.2;
        }
        else{
            l.elem[i].price *= 1.1;
        }
    }
    for (int i=1; i<=l.length; i++) {
        printf("%s %s %.2lf\n",l.elem[i].id,l.elem[i].name,l.elem[i].price);
    }
}

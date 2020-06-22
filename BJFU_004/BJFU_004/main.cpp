//
//  main.cpp
//  BJFU_004
//
//  Created by VachelChen on 2020/6/18.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <stdio.h>
#include <string>
const int maxn = 11000;
struct book{
    char id[50];
    char name[50];
    double price;
};

struct bookList{
    book *elem;
    int length;
};

void initList(bookList &l){
    l.elem = new book[maxn];
    if (!l.elem) {
        return;
    }
    l.length = 0;
}
int n;

void insertList(bookList &l,int i,book e){
    l.elem[n-i-1] = e;
    l.length++;
}
int main(){
    bookList l;
    initList(l);
    book temp;
    
    while(scanf("%d",&n)!=EOF){
    for (int i=0; i<n; i++) {
        scanf("%s %s %lf",temp.id,temp.name,&temp.price);
        insertList(l,i,temp);
    }
    for (int i=0; i<n; i++) {
        printf("%s %s %.2lf\n",l.elem[i].id,l.elem[i].name,l.elem[i].price);
    }
    }
    return 0;
}

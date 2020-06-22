//
//  main.cpp
//  BJFU_002
//
//  Created by VachelChen on 2020/6/16.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int maxn = 1000;

struct book{
    char id[20];
    char name[50];
    float price;
};

struct BookList{
    book *elem;
    int length;
};

void initList(BookList &b){
    b.elem = new book[maxn];
    if(!b.elem) exit(0);
    b.length = 0;
}

void insertList(BookList &b,int i,book e){
    if ((i<1) || (i>b.length+1)) {
        return ;
    }
    if (b.length == maxn) {
        return ;
    }
    for (int j = b.length-1; j>i-1; j--) {
        b.elem[j+1] = b.elem[j];
    }
    b.elem[i-1] = e;
    b.length++;
}

int main(){
    BookList b;
    initList(b);
    book temp;
    int num=0;
    scanf("%s %s %f",temp.id,temp.name,&temp.price);
    while (strcmp(temp.id,"0")!=0 || strcmp(temp.name,"0")!=0 || temp.price != 0) {
        num++;
        insertList(b, num, temp);
        scanf("%s %s %f",temp.id,temp.name,&temp.price);
    }
    for (int i=0; i<b.length-1; i++) {
        for (int j=0; j<b.length-1-i; j++) {
            if (b.elem[j].price<b.elem[j+1].price) {
                book t = b.elem[j];
                b.elem[j] = b.elem[j+1];
                b.elem[j+1] = t;
            }
        }
    }
    for (int i=0; i<b.length; i++) {
        printf("%s %s %.2f\n",b.elem[i].id,b.elem[i].name,b.elem[i].price);
    }
}

//
//  main.cpp
//  BJFU_005
//
//  Created by VachelChen on 2020/6/22.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <stdio.h>
const int maxn = 10010;

struct book{
    char id[50];
    char name[100];
    double price;
};

struct bookList{
    book *elem;
    int length;
};

void init(bookList &l){
    l.elem = new book[maxn];
    if (!l.elem) {
        return ;
    }
    l.length = 0;
}

void inserList(bookList &l,int i,book b){
    if (i<1 || i>l.length+1) {
        return;
    }
    if (l.length == maxn) {
        return;
    }
    for (int j=l.length; j>i-1; j--) {
        l.elem[j] = l.elem[j-1];
    }
    l.elem[i-1] = b;
    l.length++;
}

int main(){
    int n;
    bookList l;
    init(l);
    scanf("%d",&n);
    double maxprice = 0;
    int num = 1;
    for (int i=0; i<n; i++) {
        book temp;
        scanf("%s %s %lf",temp.id,temp.name,&temp.price);
        inserList(l, l.length + 1, temp);
        if (maxprice < temp.price) {
            maxprice = temp.price;
            num = 1;
        }
        else if (maxprice == temp.price){
            num++;
        }
    }
    printf("%d\n",num);
    for (int i=0; i<n; i++) {
        if (l.elem[i].price == maxprice) {
            printf("%s %s %.2lf\n",l.elem[i].id,l.elem[i].name,l.elem[i].price);
        }
    }
}

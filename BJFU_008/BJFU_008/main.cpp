//
//  main.cpp
//  BJFU_007
//
//  Created by VachelChen on 2020/6/22.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <stdio.h>
#include <string.h>
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

bool inserList(bookList &l,int i,book b){
    if (i<1 || i>l.length+1) {
        printf("Sorry，the position to be inserted is invalid!\n");
        return false;
    }
    if (l.length == maxn) {
        return false;
    }
    for (int j=l.length; j>i-1; j--) {
        l.elem[j] = l.elem[j-1];
    }
    l.elem[i-1] = b;
    l.length++;
    return true;
}

int main(){
    int n;
    bookList l;
    init(l);
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        book temp;
        scanf("%s %s %lf",temp.id,temp.name,&temp.price);
        inserList(l, l.length + 1, temp);
    }
    int m;
    scanf("%d",&m);
        book temp;
        scanf("%s %s %lf",temp.id,temp.name,&temp.price);
        if(inserList(l, m, temp))
        for (int i=0; i<l.length; i++) {
            printf("%s %s %.2lf\n",l.elem[i].id,l.elem[i].name,l.elem[i].price);
        }
    return 0;
}

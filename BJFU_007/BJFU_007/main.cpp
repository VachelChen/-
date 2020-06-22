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

void findId(bookList &l,int x){
    if (x<1 || x>l.length) {
        printf("Sorry，the book on the best position doesn't exist!\n");
        return ;
    }
    printf("%s %s %.2lf\n",l.elem[x-1].id,l.elem[x-1].name,l.elem[x-1].price);
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
    for (int i=0; i<m; i++) {
        int x;
        scanf("%d",&x);
        findId(l,x);
    }
    return 0;
}

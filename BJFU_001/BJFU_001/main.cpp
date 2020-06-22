//
//  main.cpp
//  BJFU_001
//
//  Created by VachelChen on 2020/6/13.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
//分配内存失败的over所需的头文件
#include <string.h>
const int maxn = 10010;

struct book{
    char number[50];
    char name[50];
    float price;
};

struct booklist{
    book *b;
    int Length;
};

void ListInit(booklist &l){
    l.b = new book[maxn];
    if(!l.b)    exit(0);
    l.Length = 0;
}

void ListInsert(booklist &l,int i,book n){
    if(i<1 || i>l.Length+1) return;
    //此处是l.Length+1，+1表示插在末尾
    if(l.Length == maxn) return;
    for (int j=l.Length-1; j>i-1; j--) {
        l.b[j+1] = l.b[j];
    }
    l.b[i] = n;
    l.Length++;
}

int main(){
    book t;
    booklist l;
    ListInit(l);
    scanf("%s %s %f",t.number,t.name,&t.price);
    while (strcmp(t.number,"0")!=0 && strcmp(t.name,"0")!=0  && t.price!=0) {
        ListInsert(l, l.Length+1, t);
        scanf("%s %s %f",t.number,t.name,&t.price);
    }
    printf("%d\n",l.Length);
    for (int i=1; i<=l.Length; i++) {
        printf("%s %s %.2f\n",l.b[i].number,l.b[i].name,l.b[i].price);
    }
    return 0;
}

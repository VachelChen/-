//
//  main.cpp
//  PAT_A1032
//
//  Created by VachelChen on 2020/3/15.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
using namespace std;

const int maxn = 100010;

struct node{
    char letter;    //该节点内容
    int next;     //下一个节点
    bool flag;
}n[maxn];

int main(int argc, const char * argv[]) {
    for(int i = 0;i<maxn;i++){
        n[i].flag = false;
    }
    int start_1,start_2,num;
    cin >> start_1 >> start_2 >>num;
    int address,nextAddress;
    char let;
    for(int i=0; i<num; i++){
        cin >> address >> let >> nextAddress;
        n[address].letter = let;
        n[address].next = nextAddress;
    }
    int p;
    for(p = start_1; p!=-1; p=n[p].next){
        n[p].flag = true;
    }
    for(p = start_2; p!=-1; p=n[p].next){
        if(n[p].flag == true){
            printf("%05d\n",p);
            return 0;
        }
    }
    cout<<"-1"<<endl;
    return 0;
}

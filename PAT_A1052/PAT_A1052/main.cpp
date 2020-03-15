//
//  main.cpp
//  PAT_A1052
//
//  Created by VachelChen on 2020/3/15.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
using namespace std;

const int maxn = 100010;

struct node{
    int address,key,next;
}n[maxn];

int main(int argc, const char * argv[]) {
    int num,start;
    cin >> num >> start;
    for(int i=0; i < num; i++){
        int address,key,next;
        cin >> address >> key >> next;
        n[address].address = address;
        n[address].key = key;
        n[address].next = next;
    }
    
    return 0;
}

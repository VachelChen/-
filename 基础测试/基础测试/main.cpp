//
//  main.cpp
//  基础测试
//
//  Created by VachelChen on 2020/2/29.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#include <map>
#include <algorithm>
#include <queue>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

ListNode* deleteDuplicates(ListNode* head) {
    if(head == NULL || head->next == NULL)    return head;
    ListNode* p = head;
    ListNode* d = head->next;
    while(p!=NULL){
        if(d->val == p->val){
            d = d->next;
            p -> next = d;
        }
        else{
            p = p->next;
            d = d->next;
        }
    }
    return head;
}

int main(){
    ListNode* l1;
    ListNode a(1),b(2);
    l1 = &a;
    l1 -> next = &b;
    
    ListNode* l2 = deleteDuplicates(l1);
    
    return 0;
}

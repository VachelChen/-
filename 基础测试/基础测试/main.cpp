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


ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* a = l1;
    ListNode* b = l2;
    ListNode head(0);
    ListNode* c = &head;
    while(a && b){
        ListNode p(0);
        if(a->val > b->val){
            p.val = b->val;
            p.next = NULL;
            b = b->next;
        }
        else{
            p.val = a->val;
            p.next = NULL;
            a = a->next;
        }
        c->next = &p;
        c = c->next;
    }
    c->next = a?a:b;
    return head.next;
}


int main(){
    ListNode* l1;
    ListNode a(1),b(2);
    l1 = &a;
    l1 -> next = &b;
    
    ListNode* l2;
    ListNode c(1),d(3);
    l2 = &c;
    l2 -> next = &d;
    
    ListNode* l3 = mergeTwoLists(l1, l2);
    
    return 0;
}

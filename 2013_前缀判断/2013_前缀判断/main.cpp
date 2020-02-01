//
//  main.cpp
//  2013_前缀判断
//
//  Created by VachelChen on 2020/2/1.
//  Copyright © 2020 VachelChen. All rights reserved.
//

//
//题目标题：前缀判断
//
//    如下的代码判断 needle_start指向的串是否为haystack_start指向的串的前缀，如不是，则返回NULL。
//
//    比如："abcd1234" 就包含了 "abc" 为前缀
//
//char* prefix(char* haystack_start, char* needle_start)
//{
//    char* haystack = haystack_start;
//    char* needle = needle_start;
//
//
//    while(*haystack && *needle){
//        if(______________________________) return NULL;  //填空位置
//    }
//
//    if(*needle) return NULL;
//
//    return haystack_start;
//}
//
//
//请分析代码逻辑，并推测划线处的代码，通过网页提交。
//注意：仅把缺少的代码作为答案，千万不要填写多余的代码、符号或说明文字！！
//
//

#include<iostream>
using namespace std;

char* prefix(char* haystack_start, char* needle_start)
{
    char* haystack = haystack_start;
    char* needle = needle_start;


    while(*haystack && *needle){
        if(*(haystack++) != *(needle++)) return NULL;  //填空位置
    }

    if(*needle) return NULL;

    return haystack_start;
}


int main(){
    cout<<prefix("abcd1234", "abd")<<endl;
    return 0;
}

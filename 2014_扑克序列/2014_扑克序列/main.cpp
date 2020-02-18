//
//  main.cpp
//  2014_扑克序列
//
//  Created by VachelChen on 2020/2/13.
//  Copyright © 2020 VachelChen. All rights reserved.
//
/*
标题：扑克序列

    A A 2 2 3 3 4 4， 一共4对扑克牌。请你把它们排成一行。
    要求：两个A中间有1张牌，两个2之间有2张牌，两个3之间有3张牌，两个4之间有4张牌。

    请填写出所有符合要求的排列中，字典序最小的那个。

例如：22AA3344 比 A2A23344 字典序小。当然，它们都不是满足要求的答案。


请通过浏览器提交答案。“A”一定不要用小写字母a，也不要用“1”代替。字符间一定不要留空格。
 */

#include <iostream>
#include <string>
using namespace std;

bool check(string str){
    if(str.rfind("A")-str.find("A")==2 &&
       str.rfind("2")-str.find("2")==3 &&
       str.rfind("3")-str.find("3")==4 &&
       str.rfind("4")-str.find("4")==5 )
        return true;
    else
        return false;
}

int main(int argc, const char * argv[]) {
    string str="223344AA";
    do{
        if (check(str)) {
            cout<<str<<endl;
        }
    }while(next_permutation(str.begin(),str.end()));
    
    
    return 0;
}

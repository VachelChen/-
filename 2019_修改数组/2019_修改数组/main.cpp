//
//  main.cpp
//  2019_修改数组
//
//  Created by VachelChen on 2020/2/6.
//  Copyright © 2020 VachelChen. All rights reserved.
//

/*
 试题H: 修改数组
 时间限制: 1.0s 内存限制: 256.0MB 本题总分：20 分
 【问题描述】
 给定一个长度为N 的数组A = [A1; A2; … AN]，数组中有可能有重复出现
 的整数。
 现在小明要按以下方法将其修改为没有重复整数的数组。小明会依次修改
 A2; A3; … ; AN。
 当修改Ai 时，小明会检查Ai 是否在A1  Ai?1 中出现过。如果出现过，则
 小明会给Ai 加上1 ；如果新的Ai 仍在之前出现过，小明会持续给Ai 加1 ，直
 到Ai 没有在A1  Ai?1 中出现过。
 当AN 也经过上述修改之后，显然A 数组中就没有重复的整数了。
 现在给定初始的A 数组，请你计算出最终的A 数组。
 【输入格式】
 第一行包含一个整数N。
 第二行包含N 个整数A1; A2; …; AN 。
 【输出格式】
 输出N 个整数，依次是最终的A1; A2; … ; AN。
 【样例输入】
 5
 2 1 1 3 4
 【样例输出】
 2 1 3 4 5
 【评测用例规模与约定】
 对于80% 的评测用例，1 <= N <=10000。
 对于所有评测用例，1 <=N <=100000，1 <=Ai <=1000000。
 */


#include <iostream>
#include <sstream>
using namespace std;

void s2i(int &x,string s){
    stringstream ss;
    ss << s;
    ss >> x;
}

void i2s(int x,string &s){
    stringstream ss;
    ss << x;
    ss >> s;
}

int n;
string str;

int main(int argc, const char * argv[]) {
    cin>>n;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        while(str.find(s) != string::npos){
            int x;
            s2i(x, s);
            x++;
            i2s(x, s);
        }
        str.append(s);
    }
    
    cout<<str[0];
    
    for(int i=1;i<=n;i++)
        cout<<" "<<str[i];
        
    return 0;
}

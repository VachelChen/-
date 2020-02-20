//
//  main.cpp
//  2015_方程整数解
//
//  Created by VachelChen on 2020/2/20.
//  Copyright © 2020 VachelChen. All rights reserved.
//
/*
 方程整数解
 
 方程: a^2 + b^2 + c^2 = 1000
 （或参见【图1.jpg】）
 这个方程有整数解吗？有：a,b,c=6,8,30 就是一组解。
 你能算出另一组合适的解吗？
 
 请填写该解中最小的数字。
 
 注意：你提交的应该是一个整数，不要填写任何多余的内容或说明性文字。
 */
#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    for(int i=0;i<40;i++)
        for (int j=0; j<40; j++) {
            for (int k=0; k<40; k++) {
                if(i*i + j*j + k*k == 1000){
                    cout<<i<<" "<< j<<" "<<k<<endl;
                }
            }
        }
    return 0;
}

//
//  main.cpp
//  2014_扑克序列
//
//  Created by VachelChen on 2020/2/13.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

bool check(string str){
    return true;
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

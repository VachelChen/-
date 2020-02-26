//
//  main.cpp
//  2017_正则问题
//
//  Created by VachelChen on 2020/2/26.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
using namespace std;

int f(){
    int x=0,y=0;
    while(1){
        int in = getchar();
        if(in == '('){
            x += f();
        }
        else if(in == '|'){
            y = max(x,y);
            x = 0;
        }
        else if (in == ')'){
            y = max(x,y);
            return y;
        }
        else if (in == 'x'){
            x++;
        }
        else{
            y = max(x,y);
            return y;
        }
    }
    return x;
}

int main(){
    cout<<f()<<endl;
}

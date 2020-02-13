//
//  main.cpp
//  2014_猜年龄
//
//  Created by VachelChen on 2020/2/12.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int x;int y;
    for(x=1;x<=50;x++)
        for (y=1; y<=50; y++) {
            if(x*y == (x+y)*6 && x!=y && abs(x-y)<=8)
                cout<<x<<" "<<y<<endl;
        }
    return 0;
}

//
//  main.cpp
//  codeup_分数矩阵
//
//  Created by VachelChen on 2020/3/7.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
using namespace std;

struct fen{
    int up,down;
};

fen m[50000][50000];

int main(int argc, const char * argv[]) {
    int n;
    while (scanf("%d",&n) != EOF) {
        if(n == 0)  break;
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                if(i == j)  m[i][j].up = m[i][j].down =1;
                
            }
        }
    }
    return 0;
}

//
//  main.cpp
//  PAT_A1062
//
//  Created by VachelChen on 2020/6/27.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 100010;

struct man{
    int id;
    int talent;
    int virtue;
    int rank;
    int total;
}m[maxn];

bool cmp(man a,man b){
    if (a.rank == b.rank) {
        if (a.total == b.total) {
            if(a.virtue == b.virtue){
                return a.id < b.id;
            }
            return a.virtue > b.virtue;
        }
        return a.total > b.total;
    }
        return a.rank < b.rank;
}

int n,l,h;
int main(int argc, const char * argv[]) {
    scanf("%d %d %d",&n,&l,&h);
    int index = 0;
    for(int i=0; i<n ;i++){
        int id0;
        int t0,v0;
        scanf("%d %d %d",&id0,&v0,&t0);
        if (t0 >= l && v0 >=l) {
            m[index].id = id0;
            m[index].talent = t0;
            m[index].virtue = v0;
            m[index].total = v0+t0;
            if (t0>=h && v0>= h) {
                m[index].rank = 1;
            }
            else if(t0<h && v0>=h){
                m[index].rank = 2;
            }
            else if(t0<h && v0<h && v0>=t0){
                m[index].rank = 3;
            }
            else{
                m[index].rank = 4;
            }
            index++;
        }
    }
    sort(m, m+index, cmp);
    cout<<index<<endl;
    for(int i=0;i<index;i++){
        printf("%d %d %d\n",m[i].id,m[i].virtue,m[i].talent);
    }
    return 0;
}


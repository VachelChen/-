//
//  main.cpp
//  PAT_A1026
//
//  Created by VachelChen on 2020/6/16.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 10010;

const int starttime = 8*3600;
const int endtime = 21*3600;

struct pairPlay{
    int arrive;
    int serving;
    int playing;
    bool vip;
    int waittime;
    pairPlay(){
        waittime = 0;
    }
}p[maxn];

struct table{
    bool viptable;
    int serve;
    table(){
        viptable = false;
        serve = 0;
    }
}t[110];
int ttime[110];

bool cmp(pairPlay a,pairPlay b){
    return a.arrive < b.arrive;
}

bool cmpp(pairPlay a,pairPlay b){
    return a.serving < b.serving;
}


int n,k,mnum;
vector<pairPlay> v;

int main(int argc, const char * argv[]) {
    cin >> n;
    int okp=0;
    for (int i=0; i<n; i++) {
        string t;
        cin >> t >> p[i].playing >> p[i].vip;
        p[i].arrive = ((t[0]-'0')*10+(t[1]-'0'))*3600+
                      ((t[3]-'0')*10+(t[4]-'0'))*60+
                      ((t[6]-'0')*10+(t[7]-'0'));
        if (p[i].playing >= 120) {
            p[i].playing = 120;
        }
    }
    cin >> k >> mnum;
    sort(p, p+n, cmp);
    
    for (int i=1; i<=k; i++) {
        ttime[i] = starttime;
    }
    
    for (int i=0; i<mnum; i++) {
        int x;
        cin >> x;
        t[x].viptable = true;
    }
    
    for (int i=0; i<n; i++) {
        if(p[i].arrive > endtime) break;
        else{
            //找一个时间最小的table
            int mintable = endtime;
            int tablenumber = 1;
            for (int j = 1; j<=k; j++) {
                if (ttime[j] < mintable) {
                    mintable = ttime[j];
                    tablenumber = j;
                }
            }
            //VIP客户会优先选择空闲VIP桌,哪怕有编号更小的空闲非VIP桌
            //我真tm没看出来为什么：）
            if(p[i].vip){
                for (int j = 1; j<=k; j++) {
                    if (ttime[j] == mintable && t[j].viptable) {
                        mintable = ttime[j];
                        tablenumber = j;
                    }
                }
            }
            
            if(t[tablenumber].viptable && mintable-p[i].arrive > 0 && p[i].vip == false){
                int x = 1;
                while (mintable-p[i+x].arrive > 0 && x+i<n) {
                    if (p[i+x].vip == true) {
                        pairPlay temp = p[i+x];
                        for (int j=i+x; j>i; j--) {
                            p[j] = p[j-1];
                        }
                        p[i] = temp;
                        break;
                    }
                    x++;
                }
            }
            int servertime = max(p[i].arrive,mintable);
            if (servertime>=endtime) {
                break;
            }
            okp++;
            p[i].waittime = (servertime - p[i].arrive);
            ttime[tablenumber] = servertime+p[i].playing*60;
            p[i].serving = servertime;
            t[tablenumber].serve++;
        }
    }
    sort(p, p+n, cmpp);
    for (int i=n-okp; i<n; i++) {
        printf("%02d:%02d:%02d ",p[i].arrive/3600,(p[i].arrive%3600)/60,(p[i].arrive%60));
        printf("%02d:%02d:%02d ",p[i].serving/3600,(p[i].serving%3600)/60,(p[i].serving%60));
        printf("%d\n",((p[i].waittime*1.0)/60-(p[i].waittime/60))>=0.5?((p[i].waittime/60)+1):(p[i].waittime/60));
    }
    cout<<t[1].serve;
    for (int j=2; j<=k; j++) {
        cout<<" "<<t[j].serve;
    }
    cout<<endl;
    return 0;
}


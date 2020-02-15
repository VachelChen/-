#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <cstring>
#include <cstdlib>

using namespace std;
//删除字符串中空格，制表符tab等无效字符
string Trim(string& str)
{
    //str.find_first_not_of(" \t\r\n"),在字符串str中从索引0开始，返回首次不匹配"\t\r\n"的位置
    str.erase(0,str.find_first_not_of(" \t\r\n"));
    str.erase(str.find_last_not_of(" \t\r\n") + 1);
    return str;
}

float s2i(string str){
    stringstream ss;
    float x;
    ss << str;
    ss >> x;
    return x;
}

float deltax=0;
float deltay=0;
int forwardDirection=0;
int player[12][12];
int number=1;
int shoufa=1;
bool flag=false;
map <string,int>m;
//map <string,int>x;
//map <string,int>y;
//map <string,int>num;
//map <string,int>shoot;

void output(){
    for(int i=1;i<=11;i++){
        for(int j=1;j<=11;j++){
            cout<<player[i][j]<<"\t";
        }
        cout<<endl;
    }
    
    cout<<"平均deltax:"<<deltax/forwardDirection<<endl;
    cout<<"平均deltay:"<<deltay/forwardDirection<<endl;
    cout<<"y/x:"<<(deltax/forwardDirection)/(deltay/forwardDirection)<<endl;
}


int main()
{
    ifstream fin("/Users/vachelchen/Desktop/2020_Problem_D_DATA/fullevents.csv"); //打开文件流操作
    string line;
    while (getline(fin, line))   //整行读取，换行符“\n”区分，遇到文件尾标志eof终止读取
    {
        //cout <<"原始字符串："<< line << endl; //整行输出
        if(number==1){
            number++;
            continue;
        }
        number++;
        istringstream sin(line); //将整行字符串line读入到字符串流istringstream中
        vector<string> fields; //声明一个字符串向量
        string field;
        while (getline(sin, field, ',')) //将字符串流sin中的字符读入到field字符串中，以逗号为分隔符
        {
            fields.push_back(field); //将刚刚读取的字符串添加到向量fields中
        }
        string matchID = Trim(fields[0]); //清除掉向量fields中第1个元素的无效字符
        string teamID = Trim(fields[1]); //清除掉向量fields中第2个元素的无效字符
        string oID = Trim(fields[2]); //清除掉向量fields中第3个元素的无效字符
        string dID = Trim(fields[3]); //清除掉向量fields中第4个元素的无效字符
        string MP = Trim(fields[4]); //清除掉向量fields中第5个元素的无效字符
        string eventTime = Trim(fields[5]); //清除掉向量fields中第6个元素的无效字符
        string type = Trim(fields[6]); //清除掉向量fields中第7个元素的无效字符
        string subtype = Trim(fields[7]); //清除掉向量fields中第7个元素的无效字符
        string ox = Trim(fields[8]); //清除掉向量fields中第8个元素的无效字符
        string oy = Trim(fields[9]); //清除掉向量fields中第9个元素的无效字符
        string dx = Trim(fields[10]); //清除掉向量fields中第10个元素的无效字符
        string dy = Trim(fields[11]); //清除掉向量fields中第11个元素的无效字符
        //cout<<matchID<<" "<<teamID<<" "<<oID<<" "<<dID<<" "<<MP<<" "<<eventTime<<" "<<type<<" "<<subtype<<endl;
        //cout<<number<<endl;
        if(teamID != "Huskies" ) continue;
        if(type == "Substitution"){
            m[dID] = m[oID];
            cout<<"发生一次换人"<<oID<<"->"<<dID<<endl;
        }
        if(type != "Pass")  continue;
        
        if(matchID == "1"){
            if(!flag){
                flag=true;
                m.clear();
//                x.clear();
//                y.clear();
                forwardDirection=0;
                deltax=0;
                deltay=0;
                shoufa=1;
                memset(player,0,sizeof(player));
                cout<<"第一场比赛分析开始"<<endl;
            }
            if(m.count(oID)<1 && m.size()<11){
                m[oID]=shoufa++;
                cout<<m.size()<<"号元素"<<oID<<endl;
            }
            if(dID=="")  continue;
            if(m.count(dID)<1 && m.size()<11){
                m[dID]=shoufa++;
                cout<<m.size()<<"号元素"<<dID<<endl;
            }
            if(ox<dx){
                deltax +=(s2i(dx)-s2i(ox));
                if(dy<ox){
                    deltay +=(s2i(oy)-s2i(dy));
                }
                else{
                    deltay +=(s2i(dy)-s2i(oy));
                }
                forwardDirection++;
            }
            player[m[oID]][m[dID]]++;
        }
        else if (matchID == "2"){
            if(flag){
                output();
                forwardDirection=0;
                deltax=0;
                deltay=0;
                flag=false;
                m.clear();
//                x.clear();
//                y.clear();
                shoufa=1;
                memset(player,0,sizeof(player));
                cout<<"第二场比赛分析开始"<<endl;
            }
            if(m.count(oID)<1 && m.size()<11){
                m[oID]=shoufa++;
                cout<<m.size()<<"号元素"<<oID<<endl;
            }
            if(dID=="")  continue;
            if(m.count(dID)<1 && m.size()<11){
                m[dID]=shoufa++;
                cout<<m.size()<<"号元素"<<dID<<endl;
            }
            if(ox<dx){
                deltax +=(s2i(dx)-s2i(ox));
                if(dy<ox){
                    deltay +=(s2i(oy)-s2i(dy));
                }
                else{
                    deltay +=(s2i(dy)-s2i(oy));
                }
                forwardDirection++;
            }
            if(type == "Substitution"){
                m[dID] = m[oID];
                cout<<"发生一次换人"<<oID<<"->"<<dID<<endl;
            }
            //cout<<m[oID]<<" "<<m[dID]<<endl;
            player[m[oID]][m[dID]]++;
        }
        else if (matchID == "3"){
            if(!flag){
                output();
                forwardDirection=0;
                deltax=0;
                deltay=0;
                flag=true;
                m.clear();
//                x.clear();
//                y.clear();
                shoufa=1;
                memset(player,0,sizeof(player));
                cout<<"第三场比赛分析开始"<<endl;
            }
            if(m.count(oID)<1 && m.size()<11){
                m[oID]=shoufa++;
                cout<<m.size()<<"号元素"<<oID<<endl;
            }
            if(dID=="")  continue;
            if(m.count(dID)<1 && m.size()<11){
                m[dID]=shoufa++;
                cout<<m.size()<<"号元素"<<dID<<endl;
            }
            if(ox<dx){
                deltax +=(s2i(dx)-s2i(ox));
                if(dy<ox){
                    deltay +=(s2i(oy)-s2i(dy));
                }
                else{
                    deltay +=(s2i(dy)-s2i(oy));
                }
                forwardDirection++;
            }
            if(type == "Substitution"){
                m[dID] = m[oID];
                cout<<"发生一次换人"<<oID<<"->"<<dID<<endl;
            }
            player[m[oID]][m[dID]]++;
        }
        else if (matchID == "4"){
            if(flag){
                output();
                flag=false;
                forwardDirection=0;
                deltax=0;
                deltay=0;
                m.clear();
//                x.clear();
//                y.clear();
                shoufa=1;
                memset(player,0,sizeof(player));
                cout<<"第四场比赛分析开始"<<endl;
            }
            if(m.count(oID)<1 && m.size()<11){
                m[oID]=shoufa++;
                cout<<m.size()<<"号元素"<<oID<<endl;
            }
            if(dID=="")  continue;
            if(m.count(dID)<1 && m.size()<11){
                m[dID]=shoufa++;
                cout<<m.size()<<"号元素"<<dID<<endl;
            }
            if(ox<dx){
                deltax +=(s2i(dx)-s2i(ox));
                if(dy<ox){
                    deltay +=(s2i(oy)-s2i(dy));
                }
                else{
                    deltay +=(s2i(dy)-s2i(oy));
                }
                forwardDirection++;
            }
            if(type == "Substitution"){
                m[dID] = m[oID];
                cout<<"发生一次换人"<<oID<<"->"<<dID<<endl;
            }
            player[m[oID]][m[dID]]++;
        }
        else if (matchID == "5"){
            if(!flag){
                output();
                flag=true;
                forwardDirection=0;
                deltax=0;
                deltay=0;
                m.clear();
//                x.clear();
//                y.clear();
                shoufa=1;
                memset(player,0,sizeof(player));
                cout<<"第5场比赛分析开始"<<endl;
            }
            if(m.count(oID)<1 && m.size()<11){
                m[oID]=shoufa++;
                cout<<m.size()<<"号元素"<<oID<<endl;
            }
            if(dID=="")  continue;
            if(m.count(dID)<1 && m.size()<11){
                m[dID]=shoufa++;
                cout<<m.size()<<"号元素"<<dID<<endl;
            }
            if(ox<dx){
                deltax +=(s2i(dx)-s2i(ox));
                if(dy<ox){
                    deltay +=(s2i(oy)-s2i(dy));
                }
                else{
                    deltay +=(s2i(dy)-s2i(oy));
                }
                forwardDirection++;
            }
            if(type == "Substitution"){
                m[dID] = m[oID];
                cout<<"发生一次换人"<<oID<<"->"<<dID<<endl;
            }
            player[m[oID]][m[dID]]++;
        }
        else if (matchID == "6"){
            if(flag){
                output();
                forwardDirection=0;
                deltax=0;
                deltay=0;
                flag=false;
                m.clear();
//                x.clear();
//                y.clear();
                shoufa=1;
                memset(player,0,sizeof(player));
                cout<<"第6场比赛分析开始"<<endl;
            }
            if(m.count(oID)<1 && m.size()<11){
                m[oID]=shoufa++;
                cout<<m.size()<<"号元素"<<oID<<endl;
            }
            if(dID=="")  continue;
            if(m.count(dID)<1 && m.size()<11){
                m[dID]=shoufa++;
                cout<<m.size()<<"号元素"<<dID<<endl;
            }
            if(ox<dx){
                deltax +=(s2i(dx)-s2i(ox));
                if(dy<ox){
                    deltay +=(s2i(oy)-s2i(dy));
                }
                else{
                    deltay +=(s2i(dy)-s2i(oy));
                }
                forwardDirection++;
            }
            if(type == "Substitution"){
                m[dID] = m[oID];
                cout<<"发生一次换人"<<oID<<"->"<<dID<<endl;
            }
            player[m[oID]][m[dID]]++;
        }
        else if (matchID == "7"){
            if(!flag){
                output();
                forwardDirection=0;
                deltax=0;
                deltay=0;
                flag=true;
                m.clear();
//                x.clear();
//                y.clear();
                shoufa=1;
                memset(player,0,sizeof(player));
            cout<<"第7场比赛分析开始"<<endl;
            }
            if(m.count(oID)<1 && m.size()<11){
                m[oID]=shoufa++;
                cout<<m.size()<<"号元素"<<oID<<endl;
            }
            if(dID=="")  continue;
            if(m.count(dID)<1 && m.size()<11){
                m[dID]=shoufa++;
                cout<<m.size()<<"号元素"<<dID<<endl;
            }
            if(ox<dx){
                deltax +=(s2i(dx)-s2i(ox));
                if(dy<ox){
                    deltay +=(s2i(oy)-s2i(dy));
                }
                else{
                    deltay +=(s2i(dy)-s2i(oy));
                }
                forwardDirection++;
            }
            if(type == "Substitution"){
                m[dID] = m[oID];
                cout<<"发生一次换人"<<oID<<"->"<<dID<<endl;
            }
            player[m[oID]][m[dID]]++;
        }
        else if (matchID == "8"){
            if(flag){
                output();
                forwardDirection=0;
                deltax=0;
                deltay=0;
                flag=false;
                m.clear();
//                x.clear();
//                y.clear();
                shoufa=1;
                memset(player,0,sizeof(player));
            cout<<"第8场比赛分析开始"<<endl;
            }
            if(m.count(oID)<1 && m.size()<11){
                m[oID]=shoufa++;
                cout<<m.size()<<"号元素"<<oID<<endl;
            }
            if(dID=="")  continue;
            if(m.count(dID)<1 && m.size()<11){
                m[dID]=shoufa++;
                cout<<m.size()<<"号元素"<<dID<<endl;
            }
            if(ox<dx){
                deltax +=(s2i(dx)-s2i(ox));
                if(dy<ox){
                    deltay +=(s2i(oy)-s2i(dy));
                }
                else{
                    deltay +=(s2i(dy)-s2i(oy));
                }
                forwardDirection++;
            }
            if(type == "Substitution"){
                m[dID] = m[oID];
                cout<<"发生一次换人"<<oID<<"->"<<dID<<endl;
            }
            player[m[oID]][m[dID]]++;
        }
        else if (matchID == "9"){
            if(!flag){
                output();
                forwardDirection=0;
                deltax=0;
                deltay=0;
                flag=true;
                m.clear();
//                x.clear();
//                y.clear();
                shoufa=1;
                memset(player,0,sizeof(player));
            cout<<"第9场比赛分析开始"<<endl;
            }
            if(m.count(oID)<1 && m.size()<11){
                m[oID]=shoufa++;
                cout<<m.size()<<"号元素"<<oID<<endl;
            }
            if(dID=="")  continue;
            if(m.count(dID)<1 && m.size()<11){
                m[dID]=shoufa++;
                cout<<m.size()<<"号元素"<<dID<<endl;
            }
            if(ox<dx){
                deltax +=(s2i(dx)-s2i(ox));
                if(dy<ox){
                    deltay +=(s2i(oy)-s2i(dy));
                }
                else{
                    deltay +=(s2i(dy)-s2i(oy));
                }
                forwardDirection++;
            }
            if(type == "Substitution"){
                m[dID] = m[oID];
                cout<<"发生一次换人"<<oID<<"->"<<dID<<endl;
            }
            player[m[oID]][m[dID]]++;
        }
        else if (matchID == "10"){
            if(flag){
                output();
                flag=false;
                forwardDirection=0;
                deltax=0;
                deltay=0;
                m.clear();
//                x.clear();
//                y.clear();
                shoufa=1;
                memset(player,0,sizeof(player));
            cout<<"第10场比赛分析开始"<<endl;
            }
            if(m.count(oID)<1 && m.size()<11){
                m[oID]=shoufa++;
                cout<<m.size()<<"号元素"<<oID<<endl;
            }
            if(dID=="")  continue;
            if(m.count(dID)<1 && m.size()<11){
                m[dID]=shoufa++;
                cout<<m.size()<<"号元素"<<dID<<endl;
            }
            if(ox<dx){
                deltax +=(s2i(dx)-s2i(ox));
                if(dy<ox){
                    deltay +=(s2i(oy)-s2i(dy));
                }
                else{
                    deltay +=(s2i(dy)-s2i(oy));
                }
                forwardDirection++;
            }
            if(type == "Substitution"){
                m[dID] = m[oID];
                cout<<"发生一次换人"<<oID<<"->"<<dID<<endl;
            }
            player[m[oID]][m[dID]]++;
        }
        else if (matchID == "11"){
            if(!flag){
                output();
                forwardDirection=0;
                deltax=0;
                deltay=0;
                flag=true;
                m.clear();
//                x.clear();
//                y.clear();
                shoufa=1;
                memset(player,0,sizeof(player));
            cout<<"第11场比赛分析开始"<<endl;
            }
            if(m.count(oID)<1 && m.size()<11){
                m[oID]=shoufa++;
                cout<<m.size()<<"号元素"<<oID<<endl;
            }
            if(dID=="")  continue;
            if(m.count(dID)<1 && m.size()<11){
                m[dID]=shoufa++;
                cout<<m.size()<<"号元素"<<dID<<endl;
            }
            if(ox<dx){
                deltax +=(s2i(dx)-s2i(ox));
                if(dy<ox){
                    deltay +=(s2i(oy)-s2i(dy));
                }
                else{
                    deltay +=(s2i(dy)-s2i(oy));
                }
                forwardDirection++;
            }
            if(type == "Substitution"){
                m[dID] = m[oID];
                cout<<"发生一次换人"<<oID<<"->"<<dID<<endl;
            }
            player[m[oID]][m[dID]]++;
        }
        else if (matchID == "12"){
            if(flag){
                output();
                forwardDirection=0;
                deltax=0;
                deltay=0;
                flag=false;
                m.clear();
//                x.clear();
//                y.clear();
                shoufa=1;
                memset(player,0,sizeof(player));
            cout<<"第12场比赛分析开始"<<endl;
            }
            if(m.count(oID)<1 && m.size()<11){
                m[oID]=shoufa++;
                cout<<m.size()<<"号元素"<<oID<<endl;
            }
            if(dID=="")  continue;
            if(m.count(dID)<1 && m.size()<11){
                m[dID]=shoufa++;
                cout<<m.size()<<"号元素"<<dID<<endl;
            }
            if(ox<dx){
                deltax +=(s2i(dx)-s2i(ox));
                if(dy<ox){
                    deltay +=(s2i(oy)-s2i(dy));
                }
                else{
                    deltay +=(s2i(dy)-s2i(oy));
                }
                forwardDirection++;
            }
            if(type == "Substitution"){
                m[dID] = m[oID];
                cout<<"发生一次换人"<<oID<<"->"<<dID<<endl;
            }
            player[m[oID]][m[dID]]++;
        }
        else if (matchID == "13"){
            if(!flag){
                output();
                forwardDirection=0;
                deltax=0;
                deltay=0;
                flag=true;
                m.clear();
//                x.clear();
//                y.clear();
                shoufa=1;
                memset(player,0,sizeof(player));
            cout<<"第13场比赛分析开始"<<endl;
            }
            if(m.count(oID)<1 && m.size()<11){
                m[oID]=shoufa++;
                cout<<m.size()<<"号元素"<<oID<<endl;
            }
            if(dID=="")  continue;
            if(m.count(dID)<1 && m.size()<11){
                m[dID]=shoufa++;
                cout<<m.size()<<"号元素"<<dID<<endl;
            }
            if(ox<dx){
                deltax +=(s2i(dx)-s2i(ox));
                if(dy<ox){
                    deltay +=(s2i(oy)-s2i(dy));
                }
                else{
                    deltay +=(s2i(dy)-s2i(oy));
                }
                forwardDirection++;
            }
            if(type == "Substitution"){
                m[dID] = m[oID];
                cout<<"发生一次换人"<<oID<<"->"<<dID<<endl;
            }
            player[m[oID]][m[dID]]++;
        }
        else if (matchID == "14"){
            if(flag){
                output();
                forwardDirection=0;
                deltax=0;
                deltay=0;
                flag=false;
                m.clear();
//                x.clear();
//                y.clear();
                shoufa=1;
                memset(player,0,sizeof(player));
            cout<<"第14场比赛分析开始"<<endl;
            }
            if(m.count(oID)<1 && m.size()<11){
                m[oID]=shoufa++;
                cout<<m.size()<<"号元素"<<oID<<endl;
            }
            if(dID=="")  continue;
            if(m.count(dID)<1 && m.size()<11){
                m[dID]=shoufa++;
                cout<<m.size()<<"号元素"<<dID<<endl;
            }
            if(ox<dx){
                deltax +=(s2i(dx)-s2i(ox));
                if(dy<ox){
                    deltay +=(s2i(oy)-s2i(dy));
                }
                else{
                    deltay +=(s2i(dy)-s2i(oy));
                }
                forwardDirection++;
            }
            if(type == "Substitution"){
                m[dID] = m[oID];
                cout<<"发生一次换人"<<oID<<"->"<<dID<<endl;
            }
            player[m[oID]][m[dID]]++;
        }
        else if (matchID == "15"){
            if(!flag){
                output();
                forwardDirection=0;
                deltax=0;
                deltay=0;
                flag=true;
                m.clear();
//                x.clear();
//                y.clear();
                shoufa=1;
                memset(player,0,sizeof(player));
            cout<<"第15场比赛分析开始"<<endl;
            }
            if(m.count(oID)<1 && m.size()<11){
                m[oID]=shoufa++;
                cout<<m.size()<<"号元素"<<oID<<endl;
            }
            if(dID=="")  continue;
            if(m.count(dID)<1 && m.size()<11){
                m[dID]=shoufa++;
                cout<<m.size()<<"号元素"<<dID<<endl;
            }
            if(ox<dx){
                deltax +=(s2i(dx)-s2i(ox));
                if(dy<ox){
                    deltay +=(s2i(oy)-s2i(dy));
                }
                else{
                    deltay +=(s2i(dy)-s2i(oy));
                }
                forwardDirection++;
            }
            if(type == "Substitution"){
                m[dID] = m[oID];
                cout<<"发生一次换人"<<oID<<"->"<<dID<<endl;
            }
            player[m[oID]][m[dID]]++;
        }
        else if (matchID == "16"){
            if(flag){
                output();
                forwardDirection=0;
                deltax=0;
                deltay=0;
                flag=false;
                m.clear();
//                x.clear();
//                y.clear();
                shoufa=1;
                memset(player,0,sizeof(player));
            cout<<"第16场比赛分析开始"<<endl;
            }
            if(m.count(oID)<1 && m.size()<11){
                m[oID]=shoufa++;
                cout<<m.size()<<"号元素"<<oID<<endl;
            }
            if(dID=="")  continue;
            if(m.count(dID)<1 && m.size()<11){
                m[dID]=shoufa++;
                cout<<m.size()<<"号元素"<<dID<<endl;
            }
            if(ox<dx){
                deltax +=(s2i(dx)-s2i(ox));
                if(dy<ox){
                    deltay +=(s2i(oy)-s2i(dy));
                }
                else{
                    deltay +=(s2i(dy)-s2i(oy));
                }
                forwardDirection++;
            }
            if(type == "Substitution"){
                m[dID] = m[oID];
                cout<<"发生一次换人"<<oID<<"->"<<dID<<endl;
            }
            player[m[oID]][m[dID]]++;
        }
        else if (matchID == "17"){
            if(!flag){
                output();
                forwardDirection=0;
                deltax=0;
                deltay=0;
                flag=true;
                m.clear();
//                x.clear();
//                y.clear();
                shoufa=1;
                memset(player,0,sizeof(player));
            cout<<"第17场比赛分析开始"<<endl;
            }
            if(m.count(oID)<1 && m.size()<11){
                m[oID]=shoufa++;
                cout<<m.size()<<"号元素"<<oID<<endl;
            }
            if(dID=="")  continue;
            if(m.count(dID)<1 && m.size()<11){
                m[dID]=shoufa++;
                cout<<m.size()<<"号元素"<<dID<<endl;
            }
            if(ox<dx){
                deltax +=(s2i(dx)-s2i(ox));
                if(dy<ox){
                    deltay +=(s2i(oy)-s2i(dy));
                }
                else{
                    deltay +=(s2i(dy)-s2i(oy));
                }
                forwardDirection++;
            }
            if(type == "Substitution"){
                m[dID] = m[oID];
                cout<<"发生一次换人"<<oID<<"->"<<dID<<endl;
            }
            player[m[oID]][m[dID]]++;
        }
        else if (matchID == "18"){
            if(flag){
                output();
                forwardDirection=0;
                deltax=0;
                deltay=0;
                flag=false;
                m.clear();
//                x.clear();
//                y.clear();
                shoufa=1;
                memset(player,0,sizeof(player));
            cout<<"第18场比赛分析开始"<<endl;
            }
            if(m.count(oID)<1 && m.size()<11){
                m[oID]=shoufa++;
                cout<<m.size()<<"号元素"<<oID<<endl;
            }
            if(dID=="")  continue;
            if(m.count(dID)<1 && m.size()<11){
                m[dID]=shoufa++;
                cout<<m.size()<<"号元素"<<dID<<endl;
            }
            if(ox<dx){
                deltax +=(s2i(dx)-s2i(ox));
                if(dy<ox){
                    deltay +=(s2i(oy)-s2i(dy));
                }
                else{
                    deltay +=(s2i(dy)-s2i(oy));
                }
                forwardDirection++;
            }
            if(type == "Substitution"){
                m[dID] = m[oID];
                cout<<"发生一次换人"<<oID<<"->"<<dID<<endl;
            }
            player[m[oID]][m[dID]]++;
        }
        else if (matchID == "19"){
            if(!flag){
                output();
                forwardDirection=0;
                deltax=0;
                deltay=0;
                flag=true;
                m.clear();
//                x.clear();
//                y.clear();
                shoufa=1;
                memset(player,0,sizeof(player));
            cout<<"第19场比赛分析开始"<<endl;
            }
            if(m.count(oID)<1 && m.size()<11){
                m[oID]=shoufa++;
                cout<<m.size()<<"号元素"<<oID<<endl;
            }
            if(dID=="")  continue;
            if(m.count(dID)<1 && m.size()<11){
                m[dID]=shoufa++;
                cout<<m.size()<<"号元素"<<dID<<endl;
            }
            if(ox<dx){
                deltax +=(s2i(dx)-s2i(ox));
                if(dy<ox){
                    deltay +=(s2i(oy)-s2i(dy));
                }
                else{
                    deltay +=(s2i(dy)-s2i(oy));
                }
                forwardDirection++;
            }
            if(type == "Substitution"){
                m[dID] = m[oID];
                cout<<"发生一次换人"<<oID<<"->"<<dID<<endl;
            }
            player[m[oID]][m[dID]]++;
        }
        else{
            output();
            break;
        }
    }
        
//        if(matchID == "1")  continue;
//        if(matchID != "2")  break;
//        if(type == "Substitution"){
//            m[dID]=m[oID];      //替补上场
//            cout<<"替补登场"<<endl;
//        }
//        if(teamID=="Huskies" &&type == "Pass" && dID!=""){
//            num[oID]++;
//            int x_,y_;
//            s2i(ox, x_);s2i(oy, y_);
//            x[oID]+=x_;
//            y[oID]+=y_;
//            player[m[oID]][m[dID]]++;
//            if(m[oID]==m[dID])
//                cout<<"nmb???"<<oID<<" "<<m[oID]<<" "<<dID<<" "<<m[dID]<<" "<<number<<endl;
//        }
//        if(type == "Shot" || type.find("shot")!=string::npos){
//            shoot[oID]++;
//        }
//    }
//
//    for(int i=1;i<=11;i++){
//        for(int j=1;j<=11;j++){
//            cout<<player[i][j]<<"\t";
//        }
//        cout<<endl;
//    }
//
//
//    cout<<"x:"<<x["Huskies_F1"]/num["Huskies_F1"]<<" y:"<<y["Huskies_F1"]/num["Huskies_F1"]<<" num:"<<num["Huskies_F1"]<<endl;
//    cout<<"x:"<<x["Huskies_F2"]/num["Huskies_F2"]<<" y:"<<y["Huskies_F2"]/num["Huskies_F2"]<<" num:"<<num["Huskies_F2"]<<endl;
//    cout<<"x:"<<x["Huskies_F3"]/num["Huskies_F3"]<<" y:"<<y["Huskies_F3"]/num["Huskies_F3"]<<" num:"<<num["Huskies_F3"]<<endl;
//    cout<<"x:"<<x["Huskies_D1"]/num["Huskies_D1"]<<" y:"<<y["Huskies_D1"]/num["Huskies_D1"]<<" num:"<<num["Huskies_D1"]<<endl;
//    cout<<"x:"<<x["Huskies_D2"]/num["Huskies_D2"]<<" y:"<<y["Huskies_D2"]/num["Huskies_D2"]<<" num:"<<num["Huskies_D2"]<<endl;
//    cout<<"x:"<<x["Huskies_D3"]/num["Huskies_D3"]<<" y:"<<y["Huskies_D3"]/num["Huskies_D3"]<<" num:"<<num["Huskies_D3"]<<endl;
//    cout<<"x:"<<x["Huskies_D4"]/num["Huskies_D4"]<<" y:"<<y["Huskies_D4"]/num["Huskies_D4"]<<" num:"<<num["Huskies_D4"]<<endl;
//    cout<<"x:"<<x["Huskies_M1"]/num["Huskies_M1"]<<" y:"<<y["Huskies_M1"]/num["Huskies_M1"]<<" num:"<<num["Huskies_M1"]<<endl;
//    cout<<"x:"<<x["Huskies_M2"]/num["Huskies_M2"]<<" y:"<<y["Huskies_M2"]/num["Huskies_M2"]<<" num:"<<num["Huskies_M2"]<<endl;
//    cout<<"x:"<<x["Huskies_M3"]/num["Huskies_M3"]<<" y:"<<y["Huskies_M3"]/num["Huskies_M3"]<<" num:"<<num["Huskies_M3"]<<endl;
//    cout<<"x:"<<x["Huskies_G1"]/num["Huskies_G1"]<<" y:"<<y["Huskies_G1"]/num["Huskies_G1"]<<" num:"<<num["Huskies_G1"]<<endl;
    
    
//    cout<<"shot:"<<endl<<"Huskies_F1:"<<shoot["Huskies_F1"]<<endl;
//    cout<<"Huskies_F2:"<<shoot["Huskies_F2"]<<endl;
//    //cout<<"Huskies_F3:"<<shoot["Huskies_F3"];
//    
//    float cw[11];
//    float fenzi,fenmu;
//    for(int i=1;i<12;i++){
//        fenzi=0;fenmu=0;
//        for(int j=1;j<12;j++){
//            for(int k=1;j<12;j++){
//                fenzi+=(player[i][j]*player[j][k]*player[i][k]);
//                fenmu+=(player[i][j]*player[i][k]);
//            }
//        }
//        cw[i]=fenzi/fenmu;
//    }
//    for (int i=1; i<12; i++) {
//        cout<<i<<":"<<cw[i]<<endl;
//    }
    
    return EXIT_SUCCESS;
}


// 网易游戏雷火 第一题
#include<iostream>
#include<sstream>
#include<string>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <vector>

using namespace std;

struct color{
    char name;
    string describe;
    int start;
    color(char name, string describe, int start)
    :name(name), describe(describe), start(start){}
};


unordered_map<char, string> map = {
        {'R', "FF0000"},
        {'G', "00C932"},
        {'B', "0000FF"},
        {'K', "000000"},
        {'Y', "FFFF00"},
        {'W', "FFFFFF"},
        {'P', "FF88FF"},
};

unordered_set<char> set = {
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'
};

bool isOperator(const string &text, int index){
    if (index >= text.size()-1){
        // #是最后一个字符了
        return false;
    }
    char c = text[index+1];
    if(map.count(c) != 0){
        return true;
    }else if(c == 'C' && text.size() - index >= 7){
        for (int k=1; k<=6; k++){
            if (set.count(text[index+k]) == 0){
                return false;
            }
        }
        return true;
    }
    return false;
}

color getColor(const string &text, int index){
    char name=text[index+1];
    string describe;
    if (name !='C'){
        describe = map[name];
    }else{
        describe = text.substr(index+2, 6);
    }
    int start = index;
    return color(name, describe, start);

}

bool isEnd(const string &text, int index){
    if (index >= text.size()-1) {
        // #是最后一个字符了
        return false;
    }else if(text[index+1] == 'n'){
        return true;
    }else{
        return false;
    }
}



int main(){
    int M;
    cin >> M;
    cin.get();
    for(int i=0; i<M; i++){

        string text;
        getline(cin, text);

        stack<color> s;

        vector<bool> visited(text.size(), false);
        vector<string> textColor(text.size(), "nocolor");

        for (int j=0; j<text.size(); j++){
            if (text[j] == '#'){
                if(isOperator(text, j)){
                    // 入栈
                    auto color = getColor(text, j);
                    s.push(color);
//                    cout << color.name << "  "
//                         << color.describe << "  "
//                         << color.start << endl;
                }else if(isEnd(text, j) && !s.empty()){
                    // 出栈
                    auto color = s.top();
                    s.pop();
                    int bias;
                    if(color.name != 'C'){
                        bias = 2;
                    }else{
                        bias = 8;
                    }
                    for (int k=color.start+bias; k<=j-1; k++){
                        if (!visited[k]){
                            // cout << text[k];
                            textColor[k] = color.describe;
                        }
                    }
                    // cout << endl;
                    for(int k=color.start; k<=j+1; k++){
                        if(textColor[k] == "nocolor"){
                            textColor[k] = "operator";
                        }
                        visited[k] = true;
                    }

                }
            }
        }
        vector<int> changePoint;
        for(int j=1; j<textColor.size(); j++){
            if(textColor[j] != textColor[j-1]){
                changePoint.push_back(j);
            }
        }
        int ptr = 0;
        bool flag = false;
        for (int change: changePoint){
            if (textColor[ptr] != "nocolor" && textColor[ptr] != "operator"){
                cout << text.substr(ptr, change-ptr) << ' ' << textColor[ptr] << endl;
                flag = true;
            }
            ptr = change;
        }
        if (! flag)
            cout << "empty" << endl;


    }
    return 0;
}


1
#Ppan gu#n you fu,kai tian pi di,li jie er wang.#C52BE80#CE74C3Cqing qi#n sheng,wei tian;#C2E86C1zhuo qi#n jiang, wei di#n;yuan qi yan sheng chu wan wu,cui fa sheng ji;mo qi yan sheng chu si wang duo luo,mi luan hui mie.yu zhou wan wu,you zheng,ze bi you fan.


2
#C6789xuvW #n1ergfdgb #W
#Ppan gu#n you fu,kai tian pi di,li jie er wang.#C52BE80#CE74C3Cqing qi#n sheng,wei tian;#C2E86C1zhuo qi#n jiang, wei di#n;yuan qi yan sheng chu wan wu,cui fa sheng ji;mo qi yan sheng chu si wang duo luo,mi luan hui mie.yu zhou wan wu,you zheng,ze bi you fan.

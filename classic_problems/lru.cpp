// 146. LRU 缓存
// 请你设计并实现一个满足 LRU (最近最少使用) 缓存 约束的数据结构。
// 实现 LRUCache 类：
// LRUCache(int capacity) 以 正整数 作为容量capacity 初始化 LRU 缓存
// int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
// void put(int key, int value)如果关键字key 已经存在，则变更其数据值value ；如果不存在，则向缓存中插入该组key-value 。
// 如果插入操作导致关键字数量超过capacity ，则应该 逐出 最久未使用的关键字。
// 函数 get 和 put 必须以 O(1) 的平均时间复杂度运行。

// 要使用 哈希链表 LinkedHashMap




#include "../utils.h"


#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <climits>
#include <iomanip>
#include <random>

using namespace std;

struct Node{int key, value; };

class LRUCache {
    list<Node> lst;
    unordered_map<int, list<Node>::iterator> m;
    int maxSize;

public:
    LRUCache(int capacity) {
        lst.clear();
        maxSize = capacity;
    }

    int get(int key) {
        if(m.count(key)){
            Node node = *m[key];
            // 删除list中的node
            lst.erase(m[key]);
            // 放到list最后
            lst.push_back(node);
            auto p = lst.end();
            p--;
            m[key] = p;
            return node.value;
        }else{
            return -1;
        }
    }

    void put(int key, int value) {
        if(m.count(key)){
            Node node = *m[key];
            // 删除list中的node
            lst.erase(m[key]);
            node.value = value;
            // 放到list最后
            lst.push_back(node);
            auto p = lst.end();
            p--;
            m[key] = p;
        }else{
            if(m.size()+1 > maxSize){
                auto node = *lst.begin();
                m.erase(node.key);
                lst.erase(lst.begin());
            }
            Node node{key, value};
            lst.push_back(node);
            auto p = lst.end();
            p--;
            m[key] = p;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */


int main() {

    auto lRUCache = new LRUCache(2);
    int res;
    lRUCache->put(2, 1); // 缓存是 {1=1}
    lRUCache->put(2, 2); // 缓存是 {1=1, 2=2}
    res = lRUCache->get(2);    // 返回 1
    cout << res << endl;
    lRUCache->put(1, 1); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
    lRUCache->put(4, 1); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
    res = lRUCache->get(2);    // 返回 -1 (未找到)
    cout << res << endl;



    return 0;
}

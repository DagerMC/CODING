#ifndef HASHMAP_H
#define HASHMAP_H
#include <string>
#include <set>
#include <vector>
#include <iostream>

template<class Ty>
class hashmap {
    std::set<std::string> keys;
    struct elem {
        std::string _str;
        Ty _value;
    };
    std::vector<elem> map;
    int max_size;
    int size;
    std::set<int> reserved;


    int hash(std::string str) {
        keys.insert(str);
        const int SEED = 131;
        unsigned long hash = 0;
        int length = str.length();
        for(int i = 0; i < length; i++) {
            hash = (hash * SEED) + str[i];
        }
        int pos = hash % max_size;
        while(reserved.find(pos) != reserved.end()) {
            if(map[pos]._str == str) return pos;
            hash = (hash / 2 - 1) * (SEED + pos);
            pos = hash % max_size;
        }
        reserved.insert(pos);
        map[pos]._str = str;
        size++;
        if ((float(size) / max_size) > (2. / 3)) return resize(str);
        return pos;
    }

    int resize(std::string str) {
        std::vector<Ty> temp;
        for (auto key : keys) {
            temp.push_back(map[hash(key)]._value);
        }
        
        reserved.erase(reserved.begin(), reserved.end());
        map.erase(map.begin(), map.end());
        size = 0;
        max_size *= 2;
        map.resize(max_size);

        auto size_ = temp.size();
        auto iter = keys.begin();
        for(unsigned int i = 0; i < size_; i++, iter++) {
            map[hash(*iter)]._value = temp[i];
        }
        
        return hash(str); 
    }

    public:

    hashmap() {
        map = std::vector<elem>(8);
        max_size = 8;
        size = 0;
        keys = std::set<std::string>();
        reserved = std::set<int>();
    }
    
    ~hashmap() {}

    Ty& operator[](std::string str) {
        return map[hash(str)]._value;
    }

    void print_items() {
        std::cout << "{";
        for(auto itr = keys.begin(); itr != keys.end(); itr++) {
            std::cout << " " << *itr 
                      << " : " << map[hash((*itr))]._value
                      << ",";
        }
        std::cout << "}\n";
    }

    void delete_(std::string str) {
        if(keys.find(str) == keys.end()) return;
        int pos = hash(str);
        map[pos]._value = Ty();
        map[pos]._str = std::string();
        keys.erase(keys.find(str));
    }
};

#endif
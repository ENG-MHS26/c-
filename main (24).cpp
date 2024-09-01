#include <iostream>
#include <list>
#include <map>

using namespace std;

template <typename Key, typename Value>
class SimpleCache {
private:
    list<pair<Key, Value>> cache;
    map<Key, typename list<pair<Key, Value>>::iterator> cacheMap;
    int maxSize;

public:
    SimpleCache(int size) : maxSize(size) {}

    void put(Key key, Value value) {
        auto it = cacheMap.find(key);
        if (it != cacheMap.end()) {
            cache.erase(it->second);
            cache.push_front(make_pair(key, value));
            it->second = cache.begin();
        } else {
            if (cache.size() == maxSize) {
                Key oldestKey = cache.back().first;
                cacheMap.erase(oldestKey);
                cache.pop_back();
            }
            cache.push_front(make_pair(key, value));
            cacheMap[key] = cache.begin();
        }
    }

    Value* get(Key key) {
        auto it = cacheMap.find(key);
        if (it != cacheMap.end()) {
            return &it->second->second;
        }
        return nullptr;
    }

    bool contains(Key key) {
        return cacheMap.find(key) != cacheMap.end();
    }

    int size() {
        return cache.size();
    }
};

int main() {
    SimpleCache<int, string> cache(3);

    cache.put(1, "One");
    cache.put(2, "Two");
    cache.put(3, "Three");

    if (auto value = cache.get(1)) {
        cout << "Key 1: " << *value << endl;
    } else {
        cout << "Key 1 not found" << endl;
    }

    if (auto value = cache.get(2)) {
        cout << "Key 2: " << *value << endl;
    } else {
        cout << "Key 2 not found" << endl;
    }

    cache.put(4, "Four");

    if (!cache.contains(1)) {
        cout << "Key 1 has been evicted" << endl;
    }

    if (auto value = cache.get(3)) {
        cout << "Key 3: " << *value << endl;
    } else { 
        cout << "Key 3 not found" << endl;
    }

    if (auto value = cache.get(4)) {
        cout << "Key 4: " << *value << endl;
    } else {
        cout << "Key 4 not found" << endl;
    }

    return 0;}

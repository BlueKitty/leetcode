class LRUCache{
private:
    int cap;
    list<pair<int, int>> ru_list;
    unordered_map<int, list<pair<int, int>>::iterator> hash;
public:
    LRUCache(int capacity) {
        ru_list.clear(); /* head is the most recently used */
        hash.clear();
        cap = capacity;
    }
    
    int get(int key) {
        if (hash.count(key) == 0) return -1;
        auto entry = hash[key];
        ru_list.splice(ru_list.begin(), ru_list, entry);
        return entry->second;
    }
    
    void set(int key, int value) {
        if (hash.count(key)) {
            auto entry = hash[key];
            ru_list.splice(ru_list.begin(), ru_list, entry);
            entry->second = value;
        } else {
            if (ru_list.size() == cap) {
                hash.erase(ru_list.back().first);
                ru_list.pop_back();
            }
            ru_list.push_front(make_pair(key, value));
            hash[key] = ru_list.begin();
        }
    }
};
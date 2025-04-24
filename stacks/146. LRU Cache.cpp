class LRUCache {
    int capacity;
    list<pair<int, int>> cache;  // {key, value}
    unordered_map<int, list<pair<int, int>>::iterator> mp;  // key -> node

public:
    LRUCache(int cap) {
        capacity = cap;
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;

        // Move to front (most recently used)
        cache.splice(cache.begin(), cache, mp[key]);
        return mp[key]->second;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            // Update and move to front
            mp[key]->second = value;
            cache.splice(cache.begin(), cache, mp[key]);
        } else {
            // Insert new
            if (cache.size() == capacity) {
                int lruKey = cache.back().first;
                cache.pop_back();
                mp.erase(lruKey);
            }
            cache.push_front({key, value});
            mp[key] = cache.begin();
        }
    }
};

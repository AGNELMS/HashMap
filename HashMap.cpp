#include <iostream>
#include <vector>
#include <list>
using namespace std;

class MyHashMap {
private:
    const static int bucket_count = 100003;
    vector<list<pair<int, int>>> buckets;

public:
    MyHashMap() : buckets(bucket_count) {}
    
    void put(int key, int value) {
        int index = key % bucket_count;
        list<pair<int, int>>& chain = buckets[index];
        for (auto it = chain.begin(); it != chain.end(); it++) {
            if (it->first == key) {
                it->second = value;
                return;
            }
        }
        chain.push_back(make_pair(key, value));
    }
    
    int get(int key) {
        int index = key % bucket_count;
        list<pair<int, int>>& chain = buckets[index];
        for (auto it = chain.begin(); it != chain.end(); it++) {
            if (it->first == key) {
                return it->second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        int index = key % bucket_count;
        list<pair<int, int>>& chain = buckets[index];
        for (auto it = chain.begin(); it != chain.end(); it++) {
            if (it->first == key) {
                chain.erase(it);
                return;
            }
        }
    }
};

int main() {
    // Test the HashMap implementation
    MyHashMap obj;
    obj.put(1, 10);
    obj.put(2, 20);
    
    cout << "obj.get(1): " << obj.get(1) << endl;   // 10
    cout << "obj.get(3): " << obj.get(3) << endl;   // -1
    
    obj.put(2, 30);
    cout << "obj.get(2): " << obj.get(2) << endl;   // 30
    
    obj.remove(2);
    cout << "obj.get(2): " << obj.get(2) << endl;   // -1

    return 0;
}
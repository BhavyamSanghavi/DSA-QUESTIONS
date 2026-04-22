1class Node {
2public:
3    int key;
4    int val;
5    Node* prev;
6    Node* next;
7
8    Node(int key, int val) : key(key), val(val), prev(nullptr), next(nullptr) {}
9};
10
11class LRUCache {
12public:
13private:
14    int cap;
15    std::unordered_map<int, Node*> cache;
16    Node* oldest;
17    Node* latest;
18
19public:
20    LRUCache(int capacity) : cap(capacity) {
21        oldest = new Node(0, 0);
22        latest = new Node(0, 0);
23        oldest->next = latest;
24        latest->prev = oldest;
25    }
26
27    int get(int key) {
28        if (cache.find(key) != cache.end()) {
29            Node* node = cache[key];
30            remove(node);
31            insert(node);
32            return node->val;
33        }
34        return -1;
35    }
36
37private:
38    void remove(Node* node) {
39        Node* prev = node->prev;
40        Node* next = node->next;
41        prev->next = next;
42        next->prev = prev;
43    }
44
45    void insert(Node* node) {
46        Node* prev = latest->prev;
47        Node* next = latest;
48        prev->next = next->prev = node;
49        node->next = next;
50        node->prev = prev;
51    }
52
53public:
54    void put(int key, int value) {
55        if (cache.find(key) != cache.end()) {
56            remove(cache[key]);
57        }
58        Node* newNode = new Node(key, value);
59        cache[key] = newNode;
60        insert(newNode);
61
62        if (cache.size() > cap) {
63            Node* lru = oldest->next;
64            remove(lru);
65            cache.erase(lru->key);
66            delete lru;
67        }
68    }
69
70    // Destructor to release memory used by the nodes
71    ~LRUCache() {
72        Node* curr = oldest;
73        while (curr != nullptr) {
74            Node* next = curr->next;
75            delete curr;
76            curr = next;
77        }
78    }
79};
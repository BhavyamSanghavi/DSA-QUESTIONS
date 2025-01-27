//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way
class Node{
    public:
    int key,val;
    Node*next;
    Node*prev;
    
    Node(){
        
        key=val=-1;
        
        next=prev=NULL;
    }
    
    Node(int k,int value){
        key = k;
        val = value;
        next = prev = NULL;
    }
};
class LRUCache {
  private:
    unordered_map<int,Node*>mp;
  int capacity;
  Node*head;
  Node*tail;
  void insertAfterHead(Node*node){
      Node*nextNode = head->next;
      head->next = node;
      node->prev = head;
      node->next = nextNode;
      nextNode->prev = node;
     
  }
  void deleteNode(Node*node){
      Node*before = node->prev;
      Node*after = node->next;
      before->next = after;
      after->prev = before;
     
      
  }
  public:
    // Constructor for initializing the cache capacity with the given value.
int mppSize; // Cache capacity
    map<int, pair<int, int>> mpp; // Key -> {value, recency}
    int x = 0; // Recency counter (like a timestamp)

    // Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap) {
        mppSize = cap; // Assign directly to the class member variable
    }

    // Function to return value corresponding to the key.
    int get(int key) {
        if (mpp.find(key) != mpp.end()) {
            x++; // Increment recency counter
            mpp[key].second = x; // Update recency of the accessed key
            return mpp[key].first; // Return the value
        } else {
            return -1; // Key not found
        }
    }

    // Function for storing key-value pair.
    void put(int key, int value) {
        x++; // Increment recency counter

        // If the key is already present, update its value and recency
        if (mpp.find(key) != mpp.end()) {
            mpp[key] = {value, x};
            return;
        }

        // If cache is at full capacity, evict the least recently used item
        if (mpp.size() == mppSize) {
            int leastRecency = INT_MAX;
            int keyToRemove;

            // Find the least recently used key
            for (auto it = mpp.begin(); it != mpp.end(); it++) {
                if (it->second.second < leastRecency) {
                    leastRecency = it->second.second;
                    keyToRemove = it->first;
                }
            }

            mpp.erase(keyToRemove); // Erase the LRU key
        }

        // Insert the new key-value pair with the current recency
        mpp[key] = {value, x};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);

        int queries;
        cin >> queries;
        while (queries--) {
            string q;
            cin >> q;
            if (q == "PUT") {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->put(key, value);
            } else {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
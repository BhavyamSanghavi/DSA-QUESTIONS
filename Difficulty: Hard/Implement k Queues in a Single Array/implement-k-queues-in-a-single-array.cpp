class kQueues {

  public:
    vector<queue<int>>v;
    int total=0,count=0;
    
    kQueues(int n, int k) {
        v.resize(k);
        count=n;
    }

    void enqueue(int x, int i) {
        ++total;
        v[i].push(x);
    }

    int dequeue(int i) {
        if(v[i].size()==0) return -1;
        --total;
        int val=v[i].front();
        v[i].pop();
        return val;
    }

    bool isEmpty(int i) {
        return v[i].empty();
    }

    bool isFull() {
        return total==count;
    }
};

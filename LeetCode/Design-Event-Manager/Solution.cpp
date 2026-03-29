class EventManager {
public:
    struct Compare{
        bool operator()(pair<int,int>a, pair<int,int>b){
            if(a.first!=b.first) return a.first < b.first;
            return a.second>b.second;          
        }
    };
    priority_queue<pair<int,int>,vector<pair<int,int>>,Compare> pq;

    map<int,int> mp;
    EventManager(vector<vector<int>>& events) {
        for(auto x:events){
            mp[x[0]]=x[1];
            pq.push({x[1],x[0]});
        }
    }
    
    void updatePriority(int eventId, int newPriority) {
        mp[eventId]=newPriority;
        pq.push({newPriority,eventId});
    }
    
    int pollHighest() {
        while(!pq.empty()){
            auto x = pq.top();
            if(!mp.count(x.second)) pq.pop();
            else if(mp[x.second]!=x.first){ pq.pop();}
            else break;
        }

        if(!pq.empty())
        {
            int ans = pq.top().second;
            pq.pop();
            mp.erase(ans);
            return ans;
        }
        return -1;
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */
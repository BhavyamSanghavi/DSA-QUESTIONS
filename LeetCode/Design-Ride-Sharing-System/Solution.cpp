1class RideSharingSystem {
2public:
3    queue<int>riderQueue,driverQueue;
4    RideSharingSystem() {
5        
6    }
7    
8    void addRider(int riderId) {
9        riderQueue.push(riderId);
10    }
11    
12    void addDriver(int driverId) {
13        driverQueue.push(driverId);
14    }
15    
16    vector<int> matchDriverWithRider() {
17        if(driverQueue.empty() || riderQueue.empty()) return {-1,-1};
18        int driverId=driverQueue.front();
19        int riderId=riderQueue.front();
20        driverQueue.pop();
21        riderQueue.pop();
22        return {driverId,riderId};
23    }
24    
25    void cancelRider(int riderId) {
26        int n=riderQueue.size();
27        for(int i=0;i<n;i++) 
28        {
29            int id=riderQueue.front();
30            riderQueue.pop();
31            if(id!=riderId) riderQueue.push(id);
32        }
33    }
34};
35
36/**
37 * Your RideSharingSystem object will be instantiated and called as such:
38 * RideSharingSystem* obj = new RideSharingSystem();
39 * obj->addRider(riderId);
40 * obj->addDriver(driverId);
41 * vector<int> param_3 = obj->matchDriverWithRider();
42 * obj->cancelRider(riderId);
43 */
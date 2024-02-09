#include <iostream> 
#include <queue>
using namespace std;

class RecentCounter {
public:
    RecentCounter() {
        
    }
    queue<int> times;
    
    int ping(int t) {
        times.push(t);
        while (times.front() < t - 3000)
            times.pop();

        return times.size();
    }
};
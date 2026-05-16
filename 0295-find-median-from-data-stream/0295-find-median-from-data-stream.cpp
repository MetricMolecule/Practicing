class MedianFinder {
public:
    priority_queue<int> maxpq;
    priority_queue<int, vector<int>, greater<int>> minpq;
    int count=0;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        count++;
        if(maxpq.empty() || num<=maxpq.top()){
            maxpq.push(num);
        }
        else minpq.push(num);
        if(maxpq.size()>minpq.size()+1){
            int a=maxpq.top();
            minpq.push(a);
            maxpq.pop();
        }if(minpq.size()>maxpq.size()){
            int b=minpq.top();
            maxpq.push(b);
            minpq.pop();
        }
    }
    
    double findMedian() {
        double median=0;
        
        if(maxpq.size()>minpq.size()){
            return maxpq.top();
        }if(minpq.size()>maxpq.size()){
            return minpq.top();
        }
        else if(minpq.size()==maxpq.size()) return (maxpq.top()+minpq.top())/2.0;
        return 0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
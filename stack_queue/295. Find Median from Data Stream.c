class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    std::priority_queue<int, std::vector<int>, std::greater<int>> small_queue;
    std::priority_queue<int, std::vector<int>, std::less<int>> big_queue;
    void addNum(int num) {
        if (big_queue.empty()) {
            big_queue.push(num);
            return;
        }
        if (big_queue.size() == small_queue.size()) {
            if (num < big_queue.top()) {
                big_queue.push(num);
            }
            else {
                small_queue.push(num);
            }
        }
        else if (big_queue.size() > small_queue.size()) {
            if (num > big_queue.top()) {
                small_queue.push(num);
            }
            else {
                small_queue.push(big_queue.top());
                big_queue.pop();
                big_queue.push(num);
            }
        }
        else if (big_queue.size() < small_queue.size()) {
            if (num < small_queue.top()) {
                big_queue.push(num);
            }
            else {
                big_queue.push(small_queue.top());
                small_queue.pop();
                small_queue.push(num);
            }
        }      
    }
    
    double findMedian() {
        if (big_queue.size() == small_queue.size()) {
            return big_queue.empty()?0:(big_queue.top() + small_queue.top())/2.0;
        }
        else if (big_queue.size() > small_queue.size()) {
            return big_queue.top();
        }
        else {
            return small_queue.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
// class MedianFinder {
// private:
//     priority_queue<int> firstQ; // max_heap for the first half
//     priority_queue<int, std::vector<int>, std::greater<int> > secQ; // min_heap for the second half
// public:
//     // Adds a number into the data structure.
//     void addNum(int num) {
//         if(firstQ.empty() || (firstQ.top()>num)) firstQ.push(num); // if it belongs to the smaller half
//         else secQ.push(num); 
        
//         // rebalance the two halfs to make sure the length difference is no larger than 1
//         if(firstQ.size() > (secQ.size()+1))
//         {
//             secQ.push(firstQ.top());
//             firstQ.pop();
//         }
//         else if(firstQ.size()+1<secQ.size())
//         {
//             firstQ.push(secQ.top());
//             secQ.pop();
//         }
//     }

//     // Returns the median of current data stream
//     double findMedian() {
//         if(firstQ.size() == secQ.size()) return firstQ.empty()?0:( (firstQ.top()+secQ.top())/2.0);
//         else return (firstQ.size() > secQ.size())? firstQ.top():secQ.top(); 
//     }
// };
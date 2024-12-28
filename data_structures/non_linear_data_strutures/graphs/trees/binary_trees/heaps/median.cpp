class MedianFinder {
    // contains first floor(n/2) elements
    priority_queue <int> max_heap;

    // contains last ceil(n/2) elements
    priority_queue <int, vector <int>, greater <int>> min_heap;
    
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        int n1 = max_heap.size();
        int n2 = min_heap.size();

        if(n2 + 1 - n1 == 2){
            // cannot add it to min_heap directly
            if(min_heap.top() >= num){
                max_heap.push(num);
            }else{
                max_heap.push(min_heap.top());
                min_heap.pop();
                min_heap.push(num);
            }
        }else{
            if(max_heap.empty() || max_heap.top() <= num){
                min_heap.push(num);
            }else{
                min_heap.push(max_heap.top());
                max_heap.pop();
                max_heap.push(num);
            }
        }
    }
    
    double findMedian() {
        int n1 = max_heap.size();
        int n2 = min_heap.size();

        if((n1 + n2) & 1) return min_heap.top();
        return (max_heap.top() * 1.0 + min_heap.top()) / 2;
    }
};
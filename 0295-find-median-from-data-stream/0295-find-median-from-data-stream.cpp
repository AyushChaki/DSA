class MedianFinder {
public:
    priority_queue<int> maxi; 
    // max heap for smaller half

    priority_queue<int, vector<int>, greater<int>> mini; 
    // min heap for greater half

    double median;

    int signum(int a, int b) {
        if (a == b)
            return 0;
        else if (a > b)
            return 1;
        else
            return -1;
    }

    MedianFinder() {
        median = 0;
    }

    void addNum(int num) {
        switch (signum(maxi.size(), mini.size())) {

            case 0:
                // both heaps have equal size
                if (num > median) {
                    mini.push(num);
                    median = mini.top();
                } 
                else {
                    maxi.push(num);
                    median = maxi.top();
                }
                break;

            case 1:
                // max heap has more elements
                if (num > median) {
                    mini.push(num);
                    median = (maxi.top() + mini.top()) / 2.0;
                } 
                else {
                    mini.push(maxi.top());
                    maxi.pop();

                    maxi.push(num);

                    median = (maxi.top() + mini.top()) / 2.0;
                }
                break;

            case -1:
                // min heap has more elements
                if (num > median) {
                    maxi.push(mini.top());
                    mini.pop();

                    mini.push(num);

                    median = (maxi.top() + mini.top()) / 2.0;
                } 
                else {
                    maxi.push(num);
                    median = (maxi.top() + mini.top()) / 2.0;
                }
                break;
        }
    }

    double findMedian() {
        return median;
    }
};
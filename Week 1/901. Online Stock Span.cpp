// Question Link ---> https://leetcode.com/problems/online-stock-span/

// Solution 1 (Better)
class StockSpanner {
    stack<pair<int, int>> stock; // {{100, 1}, {80, 1}, {price, spans}}
public:
    StockSpanner() {}
    int next(int price) {
        int span = 1;
        while (!stock.empty() && stock.top().first <= price) {
            span += stock.top().second;
            stock.pop();
        }
        stock.push({price, span});
        return stock.top().second;
    }
};

// Solution 2
class StockSpanner {
    vector<vector<int>> output; // {{100, 1}, {80, 1}, {price, spans}}
public:
    StockSpanner() {}
    int next(int price) {
        output.push_back({price, 1});
        // cout << "current: " << price << endl;
        return getSpanBackwards();
    }
    
    int getSpanBackwards() {
        // cout << "size: " << output.size() << endl;
        for (int i = output.size() - 1; i - 1 >= 0 && output[i][0] >= output[i - 1][0]; i--) {
            // cout << "\t" << output[i - 1][0] << " prevVal: " << output[i - 1][1] << endl;
            output[i][1] += output[i - 1][1];
            output[i - 1] = output[i];
            output.pop_back();
        }
        // cout << "backNum: " << output.back()[0] << " valRet: " << output.back()[1]  << endl;
        return output.back()[1];
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
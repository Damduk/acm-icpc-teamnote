#include <vector>
#include <functional>

using namespace std;

class RMQ {
    private:
        int _arrSize;
        vector<int> _range;
        function<int(int, int)> _decide;
        int _inf;

        int makeNode(const vector<int>& arr, int left, int right, int node) {
            if (left == right)
                return _range[node] = arr[left];

            int mid = (left + right) / 2;
            int leftValue = makeNode(arr, left, mid, node * 2);
            int rightValue = makeNode(arr, mid + 1, right, node * 2 + 1);

            return _range[node] = _decide(leftValue, rightValue); 
        }

        int inner_query(int left, int right, int node, int nodeLeft, int nodeRight) {
            if (right < nodeLeft || nodeRight < left) return _inf;
            if (left <= nodeLeft && nodeRight <= right)
                return _range[node];

            int mid = (nodeLeft + nodeRight) / 2;

            return _decide(inner_query(left, right, node * 2, nodeLeft, mid), inner_query(left, right, node * 2 + 1, mid + 1, nodeRight));
        }
    public:
        RMQ(const vector<int>& arr, function<int(int, int)> decide, int inf) {
            _arrSize = arr.size();
            _decide = decide;
            _inf = inf;
            _range.resize(_arrSize * 4);

            makeNode(arr, 0, _arrSize - 1, 1);
        }

        int query(int left, int right) {
            return inner_query(left, right, 1, 0, _arrSize - 1);
        }
};
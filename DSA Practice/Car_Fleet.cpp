class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> vehicles;
        for(int i = 0; i < position.size(); i++) {
            vehicles.emplace_back(make_pair(position[i],speed[i]));
        }   
        sort(vehicles.begin(), vehicles.end());
        stack<double> st;
        for(int i = vehicles.size() - 1; i >= 0; i--) {
            double t = (target - vehicles[i].first) / (double) vehicles[i].second;
            if(st.empty() || st.top() < t) {
                st.push(t);
            }
        }

        return st.size();

    }
};

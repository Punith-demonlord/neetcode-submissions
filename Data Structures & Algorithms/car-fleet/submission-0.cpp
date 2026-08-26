class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> pospe;
        for (int i = 0; i < position.size(); i++) {
            pospe.push_back({position[i], speed[i]});
        }
        sort(pospe.begin(), pospe.end());
        
        stack<pair<int,int>> track;
        
        for (int i = pospe.size() - 1; i >= 0; i--) {
            if (track.empty()) {
                track.push(pospe[i]);
            } else {
                auto temp = track.top();
                
                double time_ahead = (double)(target - temp.first) / temp.second;
                double time_current = (double)(target - pospe[i].first) / pospe[i].second;
                
            
                if (time_current > time_ahead) {
                    track.push(pospe[i]);
                }
                
            }
        }
        
        return track.size(); 
    }
};
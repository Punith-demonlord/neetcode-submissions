class TimeMap {
    private:
    unordered_map<string,vector<pair<string,int>>> mapper;
    public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mapper[key].push_back({value,timestamp});
    }
    
    string get(string key, int timestamp) {
       int l=0;
       int r=mapper[key].size()-1;
       string result="";
       int middle=l+(r-l)/2;
       while (l<=r) {
            middle =l+(r-l)/2;
            if (mapper[key][middle].second<=timestamp) {
                result=mapper[key][middle].first;
                l=middle+1;
            } else {
                r=middle-1;
            }
        } 
        return result;
    }
};

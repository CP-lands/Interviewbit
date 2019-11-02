vector<int> Solution::lszero(vector<int> &A) {
    map<int, int> mp;
    vector<int> v;
    int sum = 0;
    mp.insert({0, -1});
    int start = -1;
    int end = -1;
    int max_l = INT_MIN;
    for(int i = 0; i < A.size(); i++){
        sum += A[i];
        if(mp.find(sum) != mp.end()){
            if(max_l < i - mp[sum]){
                max_l = i - mp[sum];
                end = i;
                start = mp[sum] + 1;
            }
        }
        else
            mp.insert({sum, i});
    }
    if(start >= 0)
        for(int i = start; i <= end; i++)
            v.push_back(A[i]);
    return v;
}
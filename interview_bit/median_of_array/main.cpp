double Solution::findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
    int m = A.size(), n = B.size(), res, mid, min_e, max_e;
    if(m == 0)
    {
        min_e = B[0];
        max_e = B[n - 1];
    }
    else if(n == 0) 
    {
        min_e = A[0];
        max_e = A[m - 1];
    }
    else 
    {
        min_e = min(A[0], B[0]);
        max_e = max(A[m - 1], B[n - 1]);
    }
    res = (m + n + 1) / 2;
    int temp_max = max_e; int temp_min = min_e;
    while(max_e > min_e)
    {
        mid = min_e + (max_e - min_e) / 2;
        int place = 0;
        place = upper_bound(A.begin(), A.end(), mid) - A.begin();
        place += upper_bound(B.begin(), B.end(), mid) - B.begin();
        if(place < res)
            min_e = mid + 1;
        else
            max_e = mid;
    }
    if((m + n) % 2 == 1) return min_e;
    else
    {
        int temp = min_e;
        res++;
        min_e = temp_min;
        max_e = temp_max;
        while(max_e > min_e)
        {
            mid = min_e + (max_e - min_e) / 2;
            int place = 0;
            place = upper_bound(A.begin(), A.end(), mid) - A.begin();
            place += upper_bound(B.begin(), B.end(), mid) - B.begin();
            if(place < res)
                min_e = mid + 1;
            else
                max_e = mid;
        }
        float ans = (float)temp + (float) min_e;
        return ans / 2;
    }
}

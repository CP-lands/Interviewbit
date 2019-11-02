int Solution::searchInsert(vector<int> &A, int B) {
    int start = 0; int end = A.size() - 1; int mid;
    while(end > start)
    {
        mid = start + (end - start) / 2;
        if(A[mid] == B) return mid;
        if(A[mid] > B) end = mid - 1;
        if(A[mid] < B) start = mid + 1;
    }
    if(A[start] >= B) return start;
    if(A[end] < B) return end + 1;
}
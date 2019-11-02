int Solution::searchMatrix(vector<vector<int> > &A, int B) {
    int r = A.size(); int c = A[0].size();
    for(int i = 0; i < r; i++)
    {
        if(A[i][0] <= B && A[i][c - 1] >= B)
        {
            int start = 0; int end = c - 1; int mid;
            while(end > start)
            {
                mid = start + (end - start) / 2;
                if(A[i][mid] == B) return 1;
                if(A[i][mid] > B) end = mid - 1;
                if(A[i][mid] < B) start = mid + 1;
            }
            if(A[i][mid] == B || A[i][end] == B) return 1;
            else return 0;
        }
    }
    return 0;
}
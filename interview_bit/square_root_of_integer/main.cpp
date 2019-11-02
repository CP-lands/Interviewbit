int Solution::sqrt(int A) {
    if(A == 0) return 0;
    if(A == 1) return 1;
    long long int head = 1; long long int back = A/2;
    if(head == back) return head;
    long long int mid;
    while(back > head)
    {
        mid = head + (back - head) / 2;
        if(mid * mid == A) return mid;
        if(mid * mid > A)
            back = mid - 1;
        if(mid * mid < A)
            head = mid;
        if(back - head == 1)
        {
            if(back * back <= A) return back;
            else return head;
        }
    }
    return head;
}

namespace kadane_algo{
    int kadane(vi a) 
    { 
        int n=a.size();
        int tillnow = 0, until = 0; 
        int i; 
        for (i = 0; i < n; i++) { 
            until = until + a[i]; 
            amax(until,0);
            amax(tillnow,until); 
        } 
        return tillnow; 
    } 
    int maxCircularSum(vi a) 
    { 
        int n=a.size();
        int max_kadane = kadane(a); 
      
        int max_wrap = 0, i; 
        for (i = 0; i < n; i++) { 
            max_wrap += a[i]; 
            a[i] = -a[i]; 
        } 
        max_wrap = max_wrap + kadane(a); 
        return (max_wrap > max_kadane) ? max_wrap : max_kadane; 
    } 
}
using namespace kadane_algo;
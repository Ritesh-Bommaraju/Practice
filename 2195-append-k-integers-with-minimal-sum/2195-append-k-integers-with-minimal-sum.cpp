class Solution {
    long long int ap_sum(long long int count, long long int start_val){
        return (count*((2*start_val)+count-1))/2;
    }
public:
    long long minimalKSum(vector<int>& ar, int k) {
        sort(ar.begin(), ar.end());
        int n = ar.size();
        int start = 1;
        long long int sum = 0;
        for(int i = 0; i < n; i++){
            int numbers_can_be_inserted = ar[i] - start;
            if(numbers_can_be_inserted >= 0){
                if(k > numbers_can_be_inserted)
                    k -=numbers_can_be_inserted;
                else{
                    numbers_can_be_inserted = k;
                    k = 0;
                }
                sum += ap_sum(numbers_can_be_inserted, start);
            start = ar[i] + 1;
            }
            if(k == 0){
                break;
            }
        }
        if(k!= 0){
            sum += ap_sum(k, start);
        }
        return sum;
    }
};
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        		// Size of the vector
        int n = letters.size();
        
		// Create variables left and right
        int l = 0, r = n-1;
		
		// Create a variable to store result
        char ans = letters[0];
        
		// Traverse the vector
		// Binary Search
        while(l <= r)
        {
			// Find mid index
            int mid = l + (r-l)/2;
            
			// If letter is less than or equal to target
			// Move left variable to mid+1
            if(letters[mid] <= target)
                l = mid+1;
				
			// If letter is greater than target
			// Store the answer and move right variable to mid-1
            else
            {
                ans = letters[mid];
                r = mid-1;
            }
        }
        
		// Return the result
        return ans;
    }
};
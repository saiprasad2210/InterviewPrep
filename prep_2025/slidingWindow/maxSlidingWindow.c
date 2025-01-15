class Solution {
    set<pair<int,int> , greater<pair<int,int>>> heap;
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> out;

        for (int i = 0 ; i < k ; i++) {
            heap.insert({nums[i], i});
        }

        out.push_back(heap.begin()->first);

        for (int i = k ; i < nums.size(); i++) {
             
             //first remove elemnet outside window
             
             //cout << "erasing: " << nums[i-k] << endl;

             heap.erase({nums[i-k],i-k});

             //cout << "Adding: " << nums[i] << endl;
             // add new element
             heap.insert({nums[i], i});

             // copy the max elem to output

             out.push_back(heap.begin()->first);
        }

        return out;
        
    }
};

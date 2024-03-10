class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> counter;
        for(int i=0; i<nums1.size(); i++){
            counter[nums1[i]]++;
        }
        map<int, int> ansmap;
        for(int i=0; i<nums2.size(); i++){
            if(counter[nums2[i]]>0){
                ansmap[nums2[i]]=1;
            }

        }
        vector<int> result;
        for(int i=0; i<nums2.size(); i++){
            if(ansmap[nums2[i]]==1){
                result.push_back(nums2[i]);
                ansmap[nums2[i]]=0;
            }
        }
        return result;
    }
};
class Solution {
 public:
  vector<int> singleNumber(vector<int>& nums) {
    /*const int xors = accumulate(nums.begin(), nums.end(), 0, bit_xor<>());
    const int lowbit = xors & -xors;
    vector<int> ans(2);

    for (const int num : nums)
      if (num & lowbit)
        ans[0] ^= num;
      else
        ans[1] ^= num;

    return ans;*/
    set<int> fset;
        set<int> sset;
        set<int> rset;
        for(int num : nums){
            if(fset.find(num)==fset.end()){
                fset.insert(num);
            }else{
                sset.insert(num);
            }
        }
        vector<int> ans(fset.size());
        auto v_it = set_difference(fset.begin(), fset.end(), sset.begin(), sset.end(), ans.begin());
        ans.resize(v_it-ans.begin());
        return ans;
  }
};
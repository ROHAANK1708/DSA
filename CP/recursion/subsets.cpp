class solution{
    private:
        void solve(vector<vector<int>> &ans,  vector<int> output, int index, vector<int> nums){
         //base case
         if(index>=nums.size()){
            ans.push_back(output);
            return;
         }   
         //exclude
         solve(ans,output,index+1,nums);
         //include
         int element=nums[index];
         output.push_back(element);
         solve(ans,output,index+1,nums);
        }
public:
 vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> output;
    int index=0;
    solve(ans,output,index,nums);
    return ans;

 }

};
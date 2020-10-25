class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] output = new int[2];
        HashMap<Integer, Integer> map = new HashMap<>();
        for(int i = 0;i<nums.length;i++){
            map.put(nums[i],i);
        }
        for(int i = 0;i<nums.length;i++){
            int val = target - nums[i];
            if(map.containsKey(val) && map.get(val) != i){
                output[0] = i;
                output[1] = map.get(val);
            }
        }
        return output;
    }
}

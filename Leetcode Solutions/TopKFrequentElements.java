/**
 * leetcode : https://leetcode.com/problems/top-k-frequent-elements/
 */
class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        HashMap<Integer,Integer> map = new HashMap<>();
        for(int i:nums){
            map.put(i,map.getOrDefault(i,0)+1);
        }
        
        PriorityQueue<Integer> heap = new PriorityQueue<>(
                    (n1,n2) -> map.get(n1) - map.get(n2));
        
        for(int n : map.keySet()){
            heap.add(n);
            if(heap.size() > k)
                heap.poll();
        }
        
        int res[] = new int[k];
        for(int i = k - 1;i >= 0;i--){
            res[i] = heap.poll();
        }
        return res;
    }
}
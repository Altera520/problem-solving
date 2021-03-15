class Solution {
    private Map<Integer, Integer> map = new HashMap<>();
    
    public int singleNumber(int[] nums) {
        int ans = 0;
        
        for(int num : nums) {
            if(!map.containsKey(num)) {
                map.put(num, 1);
            } else {
                map.put(num, map.get(num) + 1);
            }
        }
        
        for(Map.Entry<Integer, Integer> entry : map.entrySet()) {
            if(entry.getValue().equals(1)) {
                ans = entry.getKey();
            }
        }
        
        return ans;
    }
}
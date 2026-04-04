class Solution {
    /**
     * @param {number[]} nums
     * @param {number} k
     * @return {number[]}
     */
    topKFrequent(nums, k) {
        const dict = {};
        for(const num of nums){
            dict[num] = (dict[num] || 0) + 1;
        }
        const buckets = Array(nums.length + 1).fill(null).map(() => []);
        for(const key in dict){
            buckets[dict[key]].push(Number(key));
        }

        const res = [];
        for(let i = nums.length; i >= 0; i--){
            if(buckets[i]){
                for(let j = 0; j < buckets[i].length; j++){
                    res.push(buckets[i][j]);
                    if(res.length === k){
                        return res;
                    }
                }
            }
        }
        return res;
    }
}

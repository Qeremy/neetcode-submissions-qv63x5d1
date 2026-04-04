class Solution {
    /**
     * @param {string[]} strs
     * @return {string[][]}
     */
    groupAnagrams(strs) {
        const dict = new Map();

        for (const str of strs) {
            const key = str.split('').sort().join('');

            if (!dict.has(key)) {
                dict.set(key, []);
            }

            dict.get(key).push(str);
        }

        let res = [];
        for (const value of dict.values()) {
            res.push(value);
        }

        return res;
    }
}
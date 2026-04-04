class Solution {
    /**
     * @param {string[]} strs
     * @returns {string}
     */
    encode(strs) {
        let res = "";
        const sizes = [];
        for(const str of strs){
            sizes.push(str.length);
            res += str;
        }
        let count = "";
        for(const size of sizes){
            count += '#' + String(size) + ',';
        }
        return count + res;
    }

    /**
     * @param {string} str
     * @returns {string[]}
     */
    decode(str) {
        const res = [];
        const count = [];
        let index = 0;
        while(true){
            if(str[index] === '#'){
                let num = "";
                index++;
                while(str[index] !== ','){
                    num += str[index];
                    index++;
                }
                count.push(Number(num));
                index++;
            }
            else{
                for(let i = 0; i < count.length; i++){
                    let word = "";
                    for(let j = 0; j < count[i]; j++){
                        word += str[index];
                        index++;
                    }
                    res.push(word);
                }
                return res;
            }
        }
    }
}

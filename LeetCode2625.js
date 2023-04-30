/**
 * @param {any[]} arr
 * @param {number} depth
 * @return {any[]}
 */
var flat = function (arr, n) {
    if (n === 0) {
        return arr;
    }
    const ret = new Array();
    for (const val of arr) {
        if (Object(val) instanceof Number) {
            ret.push(val);
        }
        else {
            ret.push(...flat(val, n - 1));
        }
    }
    return ret;
};
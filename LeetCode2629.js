/**
 * @param {Function[]} functions
 * @return {Function}
 */

var compose = function (functions) {
    if (functions.length == 0) {
        return x => x;
    }
    const func = functions.pop(), ret = compose(functions);
    return x => ret(func(x));
};

// const fn = compose([x => x + 1, x => 2 * x])
// console.log(fn(4)) // 9
// console.log(fn(5)) // 11
// console.log(fn(0)) // 1

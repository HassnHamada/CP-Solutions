/**
 * @param {Function} fn
 * @return {Array}
 */
Array.prototype.groupBy = function (fn) {
    const object = new Object();
    this.forEach((value) => {
        const key = fn(value);
        if (object.hasOwnProperty(key)) {
            object[key].push(value);
        } else {
            object[key] = [value];
        }
    });
    return object;
    // console.log(Object.fromEntries(this.map((value) => [fn(value), [value]])));
};


// [1, 2, 3].groupBy((num) => Math.floor(num / 2)) // {"1":[1],"2":[2],"3":[3]}

/**
 * @param {any} o1
 * @param {any} o2
 * @return {boolean}
 */
var areDeeplyEqual = function (o1, o2) {
    if (o1 === undefined || o1 === null || o2 === undefined || o2 === null) {
        return o1 === o2;
    }
    if (Object.getPrototypeOf(o1) !== Object.getPrototypeOf(o2)) {
        return false;
    }
    if (o1 instanceof Object && o2 instanceof Object) {
        const keys = new Set();
        for (const key in o1) {
            keys.add(key);
            const e1 = o1[key], e2 = o2[key];
            if (e1 instanceof Object || e1 instanceof Object) {
                if (!areDeeplyEqual(e1, e2)) {
                    return false;
                }
            } else if (e1 !== e2) {
                return false;
            }
        }
        for (const key in o2) {
            if (!keys.has(key)) {
                return false;
            }
        }
        return true;
    }
    return o1 === o2;
};

// const o1 = { "x": null, "L": [1, 2, 3] }, o2 = { "x": null, "L": ["1", "2", "3"] };

// console.log(o2['1']);

// console.log(areDeeplyEqual(o1, o2));
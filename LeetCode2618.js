/**
 * @param {any} object
 * @param {any} classFunction
 * @return {boolean}
 */

var checkIfInstanceOf = function (obj, classFunction) {
    while (obj != null) {
        console.log(obj, obj.constructor);
        if (obj.constructor === classFunction) {
            return true;
        }
        obj = Object.getPrototypeOf(obj);
    }
    return false;
};


/**
 * checkIfInstanceOf(new Date(), Date); // true
 */
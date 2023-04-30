/**
 * @param {any} object
 * @return {string}
 */
var jsonStringify = function (object) {
    let ret = new String();
    ret = ret.concat(`{`);
    for (const key in object) {
        const element = object[key];
        console.log(typeof key);
        console.log(typeof key === 'string');
        ret = ret.concat(`${typeof key === 'string' ? `"${key}"` : key}:${typeof element === 'string' ? `"${element}"` : element},`);
    }
    ret = ret.slice(0, -1);
    ret = ret.concat(`}`);
    return ret;
};
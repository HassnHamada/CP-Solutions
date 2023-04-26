var TimeLimitedCache = function () {
    this.cache = new Map();
    this.promises = new Map();
};

/** 
 * @param {number} key
 * @param {number} value
 * @param {number} time until expiration in ms
 * @return {boolean} if un-expired key already existed
 */
TimeLimitedCache.prototype.set = function (key, value, duration) {
    let ret = false;
    if (this.cache.has(key)) {
        clearTimeout(this.promises.get(key));
        ret = true;
    }
    this.cache.set(key, value);
    new Promise((resolve, reject) => {
        const id = setTimeout(() => {
            this.cache.delete(key);
            this.promises.delete(key);
            resolve(0);
        }, duration);
        this.promises.set(key, id);
    });
    return ret;
};

/** 
 * @param {number} key
 * @return {number} value associated with key
 */
TimeLimitedCache.prototype.get = function (key) {
    return this.cache.has(key) ? this.cache.get(key) : -1;
};

/** 
 * @return {number} count of non-expired keys
 */
TimeLimitedCache.prototype.count = function () {
    return this.cache.size;
};

/**
 * Your TimeLimitedCache object will be instantiated and called as such:
 * var obj = new TimeLimitedCache()
 * obj.set(1, 42, 1000); // false
 * obj.get(1) // 42
 * obj.count() // 1
 */
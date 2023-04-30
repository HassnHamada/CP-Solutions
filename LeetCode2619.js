Array.prototype.last = function() {
    return this.length ? this[this.length - 1] : -1;
};

const arr = [1, 2, 3];
// console.log(arr[arr.length - 1]);
console.log(arr.last()); // 3

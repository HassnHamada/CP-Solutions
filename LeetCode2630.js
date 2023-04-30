
class Trie {
    constructor() {
        /**
         * @type {Array<{next:Map<any, number>, done:boolean, value:any}>}
         */
        this.tree = new Array();
        this.tree.push({
            next: new Map(),
            done: false,
            value: null
        });
    }
    get(...args) {
        let node = 0;
        for (const arg of args) {
            if (!this.tree[node].next.has(arg)) {
                this.tree[node].next.set(arg, this.tree.length);
                this.tree.push({
                    next: new Map(),
                    done: false,
                    value: null
                });
            }
            node = this.tree[node].next.get(arg);
        }
        return node;
    }
}
/**
 * @param {Function} fn
 */
function memoize(fn) {
    const memo = new Trie();
    return function (...args) {
        const node = memo.get(...args);
        if (!memo.tree[node].done) {
            memo.tree[node].value = fn(...args);
            memo.tree[node].done = true;
        }
        return memo.tree[node].value;
    }
}

// console.log([{}].map(String).join());
// console.log([undefined].map(String).join());
// console.log([0].map(String).join());

// let callCount = 0;
// const memoizedFn = memoize(function (a, b) {
//     callCount += 1;
//     return a + b;
// })
// console.log(memoizedFn(2, 3)) // 5
// console.log(memoizedFn(2, 3)) // 5
// console.log(callCount) // 1 

// const input = (() => { const o = {}; return [[o, o], [o, {}], [o, o]]; })();
// const fn = memoize(function (a, b) { return ({ ...a, ...b }); });
// console.log(input.forEach((value) => {
//     // console.log(value);
//     // console.log(value[0] == value[1], value[0] === value[1]);
//     return fn(value);
// }));

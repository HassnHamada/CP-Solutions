/**
 * @param {Array} arr
 * @return {Generator}
 */
var inorderTraversal = function* (arr) {

    try {
        for (const val of arr) {
            yield* inorderTraversal(val);
        }
    } catch (error) {
        yield arr;
    }
};

// const gen = inorderTraversal([1, [2, 3]]);
// console.log(gen.next().value); // 1
// console.log(gen.next().value); // 2
// console.log(gen.next().value); // 3

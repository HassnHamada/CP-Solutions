/**
 * @param {number} rowsCount
 * @param {number} colsCount
 * @return {Array<Array<number>>}
 */

Array.prototype.snail = function (rowsCount, colsCount) {
    if (this.length === rowsCount * colsCount) {
        const ret = Array.from(Array(rowsCount), () => Array(colsCount));
        for (let i = 0; i < this.length; i++) {
            const element = this[i];
            const row = i % (2 * rowsCount) < rowsCount ?
                i % rowsCount
                : i % (2 * rowsCount) - i % rowsCount * 2 - 1;
            const col = Math.floor(i / rowsCount);
            console.log(element, row, col);
            ret[row][col] = element;
        }
        return ret;
    }
    return [];
}

// const arr = [19, 10, 3, 7, 9, 8, 5, 2, 1, 17, 16, 14, 12, 18, 6, 13, 11, 20, 4, 15];
// console.log(arr.snail(5, 4)); // [[1,2,3,4]]

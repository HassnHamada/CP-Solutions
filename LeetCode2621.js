/**
 * @param {number} millis
 */

async function sleep(millis) {
    await new Promise((resolve, reject) => {
        setTimeout(() => {
            resolve(0);
        }, millis);
    });
}

const t = Date.now()
sleep(100).then(() => console.log(Date.now() - t)) // 100

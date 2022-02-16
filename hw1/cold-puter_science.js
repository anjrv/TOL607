// Stdin boilerplate
const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let res = 0;
let flag = false;

rl.on('line', (input) => {
  if (!flag) {
    flag = true;
  } else {
    // Don't care about the array size
    const nums = input.split(' ');

    for (let i = 0; i < nums.length; i++) {
      if (nums[i] < 0) res++;
    }

    console.log(res);
    process.exit(0);
  }
});

// Stdin boilerplate
const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

const nums = [];

rl.on('line', (input) => {
  nums.push(input);

  if (nums.length == 2) {
    const left = nums[0] < 0;
    const down = nums[1] < 0;

    if (left) {
      console.log(down ? 3 : 2);
    } else {
      console.log(down ? 4 : 1);
    }

    process.exit(0);
  }
});

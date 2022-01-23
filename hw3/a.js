const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let flag = false;

rl.on('line', (input) => {
  if (!flag) {
    flag = true;
  } else {
    const nums = input.split(' ').sort().reverse();

    let alice = 0;
    let bob = 0;

    for (let i = 0; i < nums.length; i++) {
      if (i % 2 == 0) {
        alice += parseInt(nums[i], 10);
      } else {
        bob += parseInt(nums[i], 10);
      }
    }

    console.log(`${alice} ${bob}`);
    process.exit(0);
  }
});

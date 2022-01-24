const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

rl.on('line', (input) => {
  const nums = input.split(' ');

  console.log(`${Math.min(nums[0], nums[1])} ${Math.max(nums[0], nums[1])}`);
  process.exit(0);
});

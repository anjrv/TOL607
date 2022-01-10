// Stdin boilerplate
const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let left = 1;
let mid = 500;
let right = 1000;

console.log(mid);

rl.on('line', (input) => {
  if (input === 'correct') process.exit(0);
  if (input === 'lower') right = mid - 1;
  if (input === 'higher') left = mid + 1;

  mid = Math.floor((left + right)/2);
  console.log(mid);
});

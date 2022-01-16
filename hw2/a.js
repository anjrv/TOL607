const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let res = '';

rl.on('line', (input) => {
  res += input.charAt(0);

  for (let i = 1; i < input.length; i++) {
    if (input.charAt(i - 1) === '-' && i != 1) res += input.charAt(i);
  }
  
  console.log(res);
  process.exit(0);
});

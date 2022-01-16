const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let currVal = null;
let output = 0;

rl.on('line', (input) => {
  if (!currVal) {
    currVal = input;
    output += parseInt(currVal, 10);
  } else {
    const lst = input.split(' ');

    const occurrances = lst.reduce(function (val, curr) {
      return val[curr] ? ++val[curr] : (val[curr] = 1), val;
    }, {});

    console.log(output);
    process.exit(0);
  }
});
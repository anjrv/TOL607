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

    let N = Object.keys(occurrances).length;

    for (let i = 0; i < N; i++) {
      const next = Object.keys(occurrances).reduce((a, b) =>
        occurrances[a] >= occurrances[b] ? a : b,
      );

      currVal -= occurrances[next];
      occurrances[next] = null;

      output += currVal;
    }

    console.log(output);
    process.exit(0);
  }
});

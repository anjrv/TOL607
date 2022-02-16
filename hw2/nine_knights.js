const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

const layout = [];
let numInputs = 0;
let numKnights = 0;

let collides = function (i, j) {
  if (
    (layout[i - 2] &&
      (layout[i - 2].charAt(j - 1) === 'k' ||
        layout[i - 2].charAt(j + 1) === 'k')) ||
    (layout[i - 1] &&
      (layout[i - 1].charAt(j - 2) === 'k' ||
        layout[i - 1].charAt(j + 2) === 'k')) ||
    (layout[i + 1] &&
      (layout[i + 1].charAt(j - 2) === 'k' ||
        layout[i + 1].charAt(j + 2) === 'k')) ||
    (layout[i + 2] &&
      (layout[i + 2].charAt(j - 1) === 'k' ||
        layout[i + 2].charAt(j + 1) === 'k'))
  )
    return true;
};

rl.on('line', (input) => {
  numInputs++;
  layout.push(input);

  if (numInputs === 5) {
    for (let i = 0; i < layout.length; i++) {
      for (let j = 0; j < layout[i].length; j++) {
        if (layout[i].charAt(j) === 'k') {
          if (collides(i, j)) {
            console.log('invalid');
            process.exit(0);
          }

          numKnights++;
        }
      }
    }

    if (numKnights !== 9) {
      console.log('invalid');
      process.exit(0);
    }

    console.log('valid');
    process.exit(0);
  }
});

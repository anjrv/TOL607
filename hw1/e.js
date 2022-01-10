// Stdin boilerplate
const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let goal = null;

rl.on('line', (input) => {

  if (!goal) {
    goal = input;
  } else {
    const omnom = input.split(' ');

    // Cannot be right
    if (omnom.length !== parseInt(goal, 10)) {
      console.log('something is fishy');
      process.exit(0);
    }

    let ctr = 0;
    for (let i = 0; i < omnom.length; i++) {
      ctr++;

      if (omnom[i] !== 'mumble' && ctr !== parseInt(omnom[i], 10)) {
        console.log('something is fishy')
        process.exit(0);
      }
    }

    console.log('makes sense');
    process.exit(0);
  }
});


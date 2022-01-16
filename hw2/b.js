const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

const mappings = {
  bauk: 'dos',
  flatbaka: 'petsa',
  k: 'g',
  y: 'u'
};

rl.on('line', (input) => {
  let res = input.replace(/bauk|flatbaka|k|y/g, function(matched) {
    return mappings[matched];
  });

  console.log(res);
  process.exit(0);
});

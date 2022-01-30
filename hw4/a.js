const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let n = null;
let k = null;

rl.on('line', (input) => {
  if (!n) {
    const val = input.split(' ').map( Number ); 
    n = val[0];
    k = val[1];
  } else {
    const s = input.split(' ').map( Number );
    const p = Array(n);
    const m = Array(n).fill().map(() => Array(k));

    for (let i = 0; i < n; i += 1) {
      p[i] = p[i-1] ? p[i-1] + s[i] : s[i];
      m[i][0] = p[i];
    }

    for (let i = 0; i < k; i += 1) {
      m[0][i] = s[0];
    }

    for (let i = 1; i < n; i += 1) {
      const len = i != n - 1 ? k - 1 : k;

      for (j = 1; j < len; j += 1) {
        m[i][j] = Number.MAX_SAFE_INTEGER;

        for (h = 0; h < i; h += 1) {
          const curr = Math.max(m[h][j - 1], p[i] - p[h]);
          
          if (m[i][j] > curr) {
            m[i][j] = curr;
          }
        }
      }
    }

    console.log(m[n - 1][k - 1]);

    process.exit(0);
  }
});

var moves = function(grid) {
    const m = grid.length;
    const n = grid[0].length;
   
    const dp = new Array(m);
    for (let i = 0; i < m; i++) {
      dp[i] = new Array(n).fill(0);
    }

    for (let i = 0; i < m; i++) {
      dp[i][0] = 0;
    }
  
    for (let col = 1; col < n; col++) {
      for (let row = 0; row < m; row++) {
        const currentVal = grid[row][col];
  
        dp[row][col] = 0;

        for (let i = -1; i <= 1; i++) {
          const newRow = row + i;
  
          if (newRow >= 0 && newRow < m) {
            dp[row][col] = Math.max(dp[row][col], dp[newRow][col - 1] + (currentVal > grid[newRow][col - 1] ? 1 : 0));
          }
        }
      }
    }
  
    let max = 0;
    for (let i = 0; i < m; i++) {
      max = Math.max(max, dp[i][n - 1]);
    }
  
    return max;
  };
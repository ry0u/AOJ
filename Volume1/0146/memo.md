# Lupin the 4th

* bitDP．dp[状態][蔵] = 最低の移動時間  
* 現在の状態でiからjに行くことを考える．(k|(1<<j))
* dp[k|(1<<j)][j] = min(dp[k|(1<<j)][j], dp[k][i] + cost);

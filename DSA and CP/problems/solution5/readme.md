# Dry run
S = "banana"
T = "an"

### initilization 

|         | b | a | n | a | n | a | "" |
|:--------|:--|:--|:--|:--|:--|:--|:---|
| **a**   |   |   |   |   |   |   |  0 |
| **n**   |   |   |   |   |   |   |  0 |
| **""**  | 1 | 1 | 1 | 1 | 1 | 1 |  1 |

### filling table from down is always fun

|         | b | a | n | a | n | a | "" |
|:--------|:--|:--|:--|:--|:--|:--|:---|
| **a**   | 3 | 3 | 1 | 1 | 0 | 0 |  0 |
| **n**   | 2 | 2 | 2 | 1 | 1 | 0 |  0 |
| **""**  | 1 | 1 | 1 | 1 | 1 | 1 |  1 |

### Dont see algo 🤫 while filling the table 
Transition state:  
if S[i] == T[j] then dp[i][j] = dp[i][j+1] + dp[i+1][j+1] 
else then dp[i][j] = dp[i][j+1];

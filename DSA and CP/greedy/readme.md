| S.no | problem | notes |
|:-----|:--------|:------|
| 1 | [Jump game](https://www.geeksforgeeks.org/problems/jump-game/1) | [jump_game.cpp](jump_game.cpp), O(n) time, O(1) space | 
| 2 | [Minimum jumps](https://www.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1) | dp solition : O(n^2) time O(n) space <br/> greedy solution: [min_jumps.cpp](min_jumps.cpp) O(n) time, O(1) solution, source: [video](https://www.youtube.com/watch?v=7SBVnw7GSTk) | 
| 3 | [Minumum platoforms](https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1) | 1) using only sorting <br/> 2) using queue, after space optimization: O(nlogn) time, O(1) space solution : [min_platforms.cpp](min_platforms.cpp) <br/> 3) using pq(my submission) |
| 4 | [Trapping rain water](https://www.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1)  | my approach: [trapping_rain_water1.cpp](trapping_rain_water1.cpp) <br/> using pre-computed left max and right max, O(n) time, O(1) solution: [trapping_rain_water2.cpp](trapping_rain_water2.cpp) <br/> two pointer approach (O(n) time, O(1) space) : [trapping_rain_water3.cpp](trapping_rain_water3.cpp) <br/> |



-----------
## Exchange arguments

- **Problem**: Minimize the maximum lateness
    - [Youtube viedo](https://www.youtube.com/watch?v=5d5tVcUAzJU)
    - [My code](minimize_maximum_lateness.cpp)

- SOLVING BLOG: [CF blog](https://codeforces.com/blog/entry/63533)
    1. Boxes
        1) [Question](https://atcoder.jp/contests/cf17-final/tasks/cf17_final_d), [code](https://atcoder.jp/contests/cf17-final/submissions/62639384), BONUS NEED TO be done!!
        2) As there is no judge, May be correct solution for bonus part: [code](hero.cpp)
            - good incorrect algo:
                - For current hp, fight with the monster which can give maximum profit.
                - Wrong test case:
                    - ```
                        2 4
                        1 0
                        4 2
                    - By the above wrong algo, monster 1 will be faught first and the maximum number of monsters that could be killed by the wrong algo is 1.
                    - But the optimal answer is 2! in order monster 2 first and then monster 1.

    2.
##




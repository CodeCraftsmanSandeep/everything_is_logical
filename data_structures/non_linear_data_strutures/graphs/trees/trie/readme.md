1) [Word break problem](https://www.geeksforgeeks.org/problems/word-break1352/1)
    - [word_break_dp_optimized.cpp](word_break_dp_optimized.cpp)
        - Time: O(n^2 * hashing_time)
        - Auxillary space: O(n)
    - [Trie based solution](word_break_using_trie.cpp)
        - Time: O(n*m)
            - where n is the length of the string
            -       m is the length of the longest string in dictionary
        - Auxillary space: O(n + 26*m)
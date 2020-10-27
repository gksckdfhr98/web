**[two_sum](https://leetcode.com/problems/two-sum/)**
```
1. 브루트포스 방식으로 target에 해당하는 수 찾아서 return - two_sum.cpp
2. map을 이용하여 target에서 nums[i]를 뺀 값이 map에 있다면 그 값을 return, 그렇지 않다면 insert. - another_two_sum1.cpp
```

**[Add Two Numbers](https://leetcode.com/problems/add-two-numbers/)**
```
1. 주어진 list 2개의 자릿수를 구하여 비교한다.
1-1. 1l의 자릿수 < l2의 자릿수면 두개의 list를 swap한다.
2. ListNode ans에 l1을 할당한 후, 루프를 돌면서 l1과 l2의 각 자릿수의 합을 더한 것을 l1에 저장한다.
```

**[Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/)**
```
1. sliding windwo algorithm 사용.
2. 넣을 문자가 set에 없다면 insert 후 j index++ , 있다면 erase 후 i index++
```

**[Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring/)**
```
1. dp문제, dp[n][n]으로 잡아놓고 dp[i][j]가 팰린드롬이면 1로 설정
2. 길이가 3부터 검사를 하며 s[i]==s[j] && dp[i+1][j-1]==1 인지 확인.
```

**[ZigZag Conversion](https://leetcode.com/problems/zigzag-conversion/)**
```
1. 변수 increase의 값에 따라 idx를 증가시키면서 넣는지 감소시키면서 넣는지 확인.
```

**[Palindrome Number](https://leetcode.com/problems/palindrome-number/)**
```
1. x가 음수이면 회문일 수 없다.
2. 자릿수가 짝수이면 반까지만 reverse한 후 원래 숫자와 비교
3. 자릿수가 홀수이면 반까지만 reverse한 후 ans/10와 원래 숫자  
```

**[Container With Most Water](https://leetcode.com/problems/container-with-most-water/)**
```
1. brute force 방식.
2. two pointer 방식.
2-1. idx 2개를 처음과 끝으로 잡아놓고 height를 비교해 가면서 idx 조절.
```

**[Integer to Roman](https://leetcode.com/problems/integer-to-roman/)**
```
1. roma 숫자에 해당하는 배열과 그 값을 선언 후 num에서 value를 빼면서 ans에 문자열 추가.
```

**[Longest Common Prefix](https://leetcode.com/problems/longest-common-prefix/)**
```
※코테전 참고 - 문자열 비교
1. strs[0]을 prefix로 설정해 놓고 그 다음 인덱스의 문자열과 비교하면서 prefix조정
```

**[3Sum](https://leetcode.com/problems/3sum/)**
```
1. brute force 방식은 시간 초과(복잡도가 n^3이라 그런가봄)
2. 비교를 줄이기 위해 two pointer algorithm이용.
2-1. 따라서 주어진 vector sort() method를 통해 오름차순 정렬.
3. 결과값이 중복되면 안되므로 set에 값을 넣어 중복 제거
```

**[3Sum Closest](https://leetcode.com/problems/3sum-closest/)**
```
1. 3Sum 문제와 접근 방식은 동일
2. ans에 무한대 값을 주고 현재 sum과 target과의 절댓값과 ans와 target과의 절댓값을 비교하여 작다면 ans=sum
```

**[Letter Combinations of a Phone Number](https://leetcode.com/problems/letter-combinations-of-a-phone-number/)**
```
1. 주어진 digits의 길이만큼 dfs탐색.
```

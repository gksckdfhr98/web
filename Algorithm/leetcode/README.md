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

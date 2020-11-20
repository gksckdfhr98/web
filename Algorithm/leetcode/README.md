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
**다시보기**
1. sliding windwo algorithm 사용.
2. 넣을 문자가 set에 없다면 insert 후 j index++ , 있다면 erase 후 i index++
```

**[Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring/)**
```
**다시보기**
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

**[Remove Nth Node From End of List](https://leetcode.com/problems/remove-nth-node-from-end-of-list/)**
```
1. head 앞에 node하나 만들어 두고 next를 돌면서 head의 length를 먼저 구한다.
2. length에 n값을 빼고 루프를 통해 해당 위치에서 그 다음의 node로 연결시켜준다.
```

**[Valid Parentheses](https://leetcode.com/problems/valid-parentheses/)**
```
1. stack에 값을 넣으면서 괄호가 닫히면 pop한다.
```

**[Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists/)**
```
1. 두 개의 리스트를 비교하면서 작은 값들을 연결시켜 나간다.
2. 반환을 위해 head를 만듬.
3. prior node로 두 리스트의 값을 비교하면서 연결시켜나감.
```

**[Generate Parentheses](https://leetcode.com/problems/generate-parentheses/)**
```
1. backtracking을 이용하여 문제 품.
2. backtracking을 하면서 열린괄호의 개수는 닫힌괄호의 개수보다 많이 유지되어야함.
```

**[Swap Nodes in Pairs](https://leetcode.com/problems/swap-nodes-in-pairs/)**
```
1. 재귀함수를 써서 해결
2. 주어진 list 앞에 dummynode를 만들어서 해결.
```

**[Remove Duplicates from Sorted Array](https://leetcode.com/problems/remove-duplicates-from-sorted-array/)**
```
1. set을 이용하여 간단하게 
```

**[Next Permutation](https://leetcode.com/problems/next-permutation/)**
```
1. 끝에서부터 idx를 줄여가면서 최초로 숫자가 작아지는 지점(i)을 찾는다.
2. 끝에서 그 지점까지 idx를 줄여가면서 그 지점(i)의 숫자보다 커지는 지점(j)를 찾는다.
3. i부터 j까지 숫자를 뒤집는다.
```

**[Longest Valid Parentheses](https://leetcode.com/problems/longest-valid-parentheses/)**
```
1. stack에 -1 먼저 push (pop할때 stack이 비어있지 않은 상태면 maxn을 계산하기 위함)
```

**[Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array/)**
```
1. lenear search (배열의 크기가 커지면 탐색 시간이 길어짐)
2. binary search
```

**[Climbing Stairs](https://leetcode.com/problems/climbing-stairs/)**
```
1. dynamic programming으로 간단하게 풀 수 있는 
```

**[Edit Distance](https://leetcode.com/problems/edit-distance/)**
```
1. dynamic programming으로 해결.(top-down)
2. 주어진 조건 3개에 주목(삽입,삭제,치환)
2-1. 두 str의 끝 idx부터 비교하는데 같다면 idx를 서로 줄여서 재귀호출
2-2. 그렇지 않다면 (m-1,n)와(m,n-1)을 비교(삽입,삭제) + (m-1,n-1)와 비교(치환)
2-3. 재귀호출을 통해 진행하면서 dp의 값이 존재한다면 return하여 중복계산을 피한다.
```

**[Sort Colors](https://leetcode.com/problems/sort-colors/)**
```
1. two-pointer algorithm으로 해결
1-1. low,high,i 3개의 idx를 잡고 시작
1-2. i<=high일때까지 루프를 반복하며
1-3. 0이면 i와 l의 위치를 swap , 2면 i와 high의 위치를 swap, 1이면 continue
```

**[Minimum Window Substring](https://leetcode.com/problems/minimum-window-substring/)**
```
1. sliding window 기법으로 해결
2. 처음에 map에 t의 문자 하나씩을 넣음.
2-1. right를 증가시키면서 map의 count를 줄이고 len==0이면 최소 길이인지 판별
2-2. 그 동안 len==0이 아닐때까지 left를 증가.
```

**[Subsets](https://leetcode.com/problems/subsets/)**
```
1. dfs로 해결.
```

**[Word Search](https://leetcode.com/problems/word-search/)**
```
1. dfs로 탐색하면서 ans가 true면 다른 경로는 탐색할 필요가 없다는 것에 주의.( 그렇지 않으면 시간초과 발생)
```

**[Largest Rectangle in Histogram](https://leetcode.com/problems/largest-rectangle-in-histogram/)**
```
**hard**
**다시보기**
1. stack을 이용하여 해결.
2. stack에 heights[i]를 넣는데 새로 넣을 것이 stack.top보다 작으면 검사 시작
2-1. 새로 넣을 것과 stack.top이 같아질때까지 pop하면서 max를 구한다.
3. heights를 다 넣고 stack이 비어질 때까지 검사하면서 max계산.
```

**[Maximal Rectangle](https://leetcode.com/problems/maximal-rectangle/)**
```
**hard**
**다시보기**
1. Largest Rectangle in Histogram 푼 풀이를 적용해야함.
2. 주어진 nxm 크기의 matrix를 가로방향으로 -> 방향으로 바라봤을때, 1이 쌓이는 개수를 누적하여 map에 저장.
3. col의 크기만큼 루프를 돌면서 각 세로줄에 1의 기법을 적용.
```

**[Validate Binary Search Tree](https://leetcode.com/problems/validate-binary-search-tree/)**
```
1. dfs로 탐색하는데 인자로 low,high값을 주면서 탐색.
```

**[Symmetric Tree](https://leetcode.com/problems/symmetric-tree/)**
```
1. t1,t2의 값이 같은지 확인
2. t1->left, t2->right 가 같은지 확인
3. t1->right, t2->left가 같은지 확인.
```

**[Binary Tree Level Order Traversal](https://leetcode.com/problems/binary-tree-level-order-traversal/)**
```
1. bfs algorithm 적용.
2. q가 empty일때까지 루프를 돌면서 q내부에서 먼저 q의size를 구하고(해당 level에 있는 node의 개수) 루프를 돌면서 검사.
```

**[Maximum Depth of Binary Tree](https://leetcode.com/problems/maximum-depth-of-binary-tree/)**
```
1. bfs로 탐색하면서 depth 증가 시켜나간다. (queue가 비어질때까지 탐색)
```

**[Construct Binary Tree from Preorder and Inorder Traversal](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)**
```
1. preorder의 값이 inorder의 값에 매칭되는 시점(idx)에 idx보다 작은 index는 그 값보다 왼쪽에 있고, 큰 index는 그 값보다 오른쪽에 있다.
```

**[Flatten Binary Tree to Linked List](https://leetcode.com/problems/flatten-binary-tree-to-linked-list/)**
```
1. 재귀적으로 호출하면서 cur의 left를 cur의 right로 옮기고 기존의 cur의 right를 새로 옮긴 cur->right의 끝에 이어 붙임.
```

**[Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)**
```
1. min_prices와 비교해서 prices[i]가 작으면 값을 바꾼다.
2. min_price보다 큰 값이 나왔을때 그 차이가 maxprofit보다 크면 값을 바꾼다.
```

**[Binary Tree Maximum Path Sum](https://leetcode.com/problems/binary-tree-maximum-path-sum/)**
```
**다시보기**
**hard**
1. 재귀 호출 방식으로 품.
2. leaf node 부분에서 현 node의 left와 right 값을 비교하여 max인 것을 node->val과 더하여 return(그래야 전체 모양이 binary tree 구조임)
3. 2과정마다 left와 right를 구할때 0과 비교하여 음수값은 걸러주므로 ans과 3 node의 합을 비교하여 ans 갱신.
```

**[Longest Consecutive Sequence](https://leetcode.com/problems/longest-consecutive-sequence/)**
```
1. set에 숫자를 넣는다.(꺼낼때 자동으로 오름차순되는 것을 이용)
2. 루프를 돌면서 maxn을 결정.
3. 루프가 끝난 후, maxn과 cnt를 한번 더 비교해준다.(루프 내에서 모든 숫자가 연속적인 오름차순일 수도 있기 
```

**[Single Number](https://leetcode.com/problems/single-number/)**
```
1. map에 숫자를 넣고, 루프를 돌면서 확인할때 map의 value가 1이면 ans
```

**[Word Break](https://leetcode.com/problems/word-break/)**
```
1. bottom-up 방식으로 구현 -> dp
2. s의 길이 만큼 dp 배열을 잡고, idx에 wordDict의 len을 더한 것이 wordDict에 존재한다면 해당 위치에서는 가능하다.
3. 2와 같은 방식으로 idx에 len을 더해가며 idx가 s의 길이와 같아지면 true
4. 그 과정중에 dp값이 1 또는 -1 이면 추가적으로 재귀호출 할 필요 없이 true와 false를 return 한다.
```

**[Maximum Product Subarray](https://leetcode.com/problems/maximum-product-subarray/)**
```
1. idx 0부터 nums.size까지 숫자를 누적해서 곱하면서 maxn을 갱신해준다.
2. 반대방향으로 1의 방법을 똑같이 해준다.
```

**[Majority Element](https://leetcode.com/problems/majority-element/)**
```
1. 루프를 돌면서 map에 key,value를 저장한다.
2. map의 루프를 돌면서 value가 최대인 key를 찾아서 
```

**[House Robber](https://leetcode.com/problems/house-robber/)**
```
1. dp문제
2. dp[0]=nums[0], dp[1]에는 nums[0],nums[1]중 큰값을 넣는다.
```

**[Number of Islands](https://leetcode.com/problems/number-of-islands/)**
```
1. 이중루프를 돌면서 '1'이고 방문하지 않았다면 탐색 시작 , ans++
2. 탐색시, queue에 (x,y) 좌표를 넣고 상하좌우로 idx를 변경하면서 탐색
2-1. 방문하지 않았거나 '1'이면 push.
```

**[Course Schedule](https://leetcode.com/problems/course-schedule/)**
```
1. 주어진 전제조건에 따라 edge에 push_back( edge[x].push_back(y) -- x를 방문해야 y도 방문 가능)
2. 1의 과정을 수행하면서 동시에 y에 딸린 조건이 몇개인지 저장하는 indegree 도 갱신.
3. indegree가 0인 수들을 queue에 넣고 q가 빌때까지 루프 반복
4. indegree-1 == 0 인 수들을 다시 queue에 넣는다.
5. numCourses와 visited가 같다면 모든 수들이 가능한 것이므로 true
```

**[Word Search II](https://leetcode.com/problems/word-search-ii/)**
```
1. words의 루프를 돌면서 존재하는지 확인  function exist.
2. word[0]와 board[i][j]가 같으면 dfs 시작.
3. dfs시 방문했던 문자는 다시 방문 x
```

**[Kth Largest Element in an Array](https://leetcode.com/problems/kth-largest-element-in-an-array/)**
```
1. nums를 오름차순으로 sort후, k번째로 큰 수를 return
2. priority_queue 이용하여 k-1번 pop한 후에 pq.top() return.
```

**[Maximal Square](https://leetcode.com/problems/maximal-square/)**
```
1. dynamic programming 이용.
2. (i,j)에서 1일때 검사하는데 (i-1,j-1),(i-1,j),(i,j-1) 중 작은 값에 + 1 ( 셋중 하나라도 0 이면 정사각형이 안되기 때문)
```

**[Product of Array Except Self](https://leetcode.com/problems/product-of-array-except-self/)**
```
1. 루프를 돌면서 0이 아닌 전체의 곱을 계산
1-1. 1의 과정중 0의 개수를 카운트 한다.(cnt)
2. cnt==2이면 0을 제외하고도 또 다른 0이 있으므로 배열의 모든 값은 0이된다.
3. cnt==1이면 0을 제외한 부분은 전체의 곱이고 이외 부분은 0
4. cnt==0이면 tot에서 nums[i]를 나누면 됨.
```

**[10912. 외로운 문자](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AXVJuEvqLAADFASe&categoryId=AXVJuEvqLAADFASe&categoryType=CODE)**
```
1. map에 문자열의 각 char을 카운트 하여 넣는다.
2. map에서 value의 값을 2로 나눈 나머지 값을 다시 넣는다.(둘씩 짝지어야 하기 때문)
3. value가 0이 아닌 값들을 ans에 
```

**[10804. 문자열의 거울상](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AXTC0x16D8EDFASe&categoryId=AXTC0x16D8EDFASe&categoryType=CODE)**
```
1. 단순구현
```

**[10761. 신뢰](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AXSVc1TqEAYDFAQT)**
```
1. blue,orange의 각 pos와 time , 전체 time을 변수로 잡는다.
2. N만큼의 루프를 돌면서 'B' or 'O' 일때, 새로 이동할 위치(pos)와 현재위치(b_pos,o_pos)와의 차이가 전체 time과 각 time(b_time,o_time)의 차이보다 크다면
time = abs(pos-b_pos,o_pos)+1(버튼누름)+b_time,o_time(현재위치의 시간)
2-1. 그렇지 않다면 버튼만 누르면 되므로 time+=1
```

**[10726. 이진수 표현](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AXRSXf_a9qsDFAXS&categoryId=AXRSXf_a9qsDFAXS&categoryType=CODE&&&)**
```
1. N만큼 M을 2로 나누면서 나머지가 1이 나오면 조건 만족.
```

**[10570. 제곱 팰린드롬 수](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AXO72aaqPrcDFAXS&categoryId=AXO72aaqPrcDFAXS&categoryType=CODE)**
```
1. dp 배열을 만들어서 i*i<=B까지 루프를 돌면서 제곱 팰린드롬수이면 dp[i*i]=true
```

**[10580. 전봇대](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AXO8QBw6Qu4DFAXS&categoryId=AXO8QBw6Qu4DFAXS&categoryType=CODE)**
```
1. 입력받은 a,b 를 a가 작은 순으로 오름차순 정렬.
2. i를 증가시키면서 j=i-1로 잡고 j--하면서 v[i].second보다 큰값이 나오면 ans++;
```

**[10505. 소득 불균형](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AXNP4CvauaMDFAXS&categoryId=AXNP4CvauaMDFAXS&categoryType=CODE)**
```
1. 입력을 받으면서 vector에 저장하면서 전체 숫자의 합 tot을 구함.
2. tot을 통해 평균을 구하고 vector을 돌면서 평균이하의 것들 ans++
```

**[10200. 구독자 전쟁](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AXMCXV_qVgkDFAWv&categoryId=AXMCXV_qVgkDFAWv&categoryType=CODE)**
```
1. A와 B중 최소값이 최댓값
2. A+B>N이면 A+B-N 값이 교차점이 
```

**[10059. 유효기간](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AXK6YRNaKq0DFAU3&categoryId=AXK6YRNaKq0DFAU3&categoryType=CODE)**
```
1. 주어진 입력을 2자리씩 나누어서 판별.
```

**[10805. 야바위](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AXTC3GH6D-EDFASe)**
```
1. 공의 위치 pos=1로 잡고 속임수를 써서 가능한 후보 candidate 배열을 시작과 동시에 q의 루프를 돌때마다 갱신시켜준다.
2. pos가 n보다 작으면 pos+1로 순간이동 가능, pos가 1보다 크면 pos-1로 순간이동 가능
```

**[10571. 잔디 깎기](https://swexpertacademy.com/main/code/problem/problemSolverCodeDetail.do)**
```
1. row,col 배열을 각각 100씩 초기화
2. 2중루프를 돌면섯 100-land[i][j] 최소값을 각각의 위치에 저장. ( land의 가장 높은 위치 알 수 있음)
3. 2중루프를 돌면서 각 위치에서 row와 col의 최솟값중 100에서 뺀 값이 land[i][j]와 같은지 확인.
```

**[9942. 순열2](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AXHx5_FK0UUDFAXR&categoryId=AXHx5_FK0UUDFAXR&categoryType=CODE)**
```
1. 길이가 N인 한 수열의 배치는 N!
2. 다른 수열은 내림차순으로 시작하여 dfs 탐색하면됨.
3. score>=k인 시점에서 방문하지 않은 개수(m) 탐색후 factorial을 구해서 누적(m!가지의 배치 경우의수)
```

**[9708. 가장 긴 수열](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AXDNGXlKagUDFAVX)**
```
1. dp[num[i]]=1로 초기화, num[i]를 계속 더하면서 num[N-1]보다 같거나 작을때까지 반복하면서 dp배열 갱신.
```

**[5293. 이진 문자열 복원](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWUiwoe6o00DFAVT)**
```
1. 문자열이 0,1로 시작하는 2가지 경우로 나누어서 dfs 시작.
2. 01,10 같은 경우에는 010 ,101 처럼 0과 1이 번갈아 나와야만 하므로 01의 개수 b와 10의 개수 c는 서로 같거나 차이가 1이여야한다.
```

**[4371. 항구에 들어오는 배](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWMedCxalW8DFAXd)**
```
1. N만큼 입력을 받으면서 해당 날에는 check[num]=true로 초기화, num-1을 vector에 push
2. vector 루프를 돌면서 1에서 v[i]만큼 계속 증가시키면서 check[num]이 true라면 총개수 n(N-1,1을 제회한 즐거운날)에서 1씩 뺀다, check[num]=true로 바꿈.
3. 2과정을 통해 true로 바꾼 날이 존재하면 bool up=true로 바꾸고 ans++
```

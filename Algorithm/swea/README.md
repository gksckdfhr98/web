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

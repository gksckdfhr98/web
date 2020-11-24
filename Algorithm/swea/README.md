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

**main.js(node.js의 웹서버 구현)**
```
1. request.url로 url 정보를 얻는다.
2. response.end()로 결과를 실행.
```

**url_parse.js(url를 parsing한 data를 이용)**
```
1. url.parse().query method를 이용하여 queryData 값을 얻는다.
1-1) option으로 true를 주면 Object로 반환한다.
2. response.end(queryData.id)로 결과 확인.
```

**dynamic_web.js(동적으로 웹페이지 구현)**
```
1. url query의 id에 동적으로 값을 준다.
2. 그 값을 title 변수에 저장하여 template에 이용한다.
3. ${title} 형식으로 query id 값에 따라 동적으로 웹페이지 구현.
```

**read_file.js(파일 읽기)**
```
1. 같은 디렉토리 내에 파일을 만들어두고 그 값을 읽는다.
2. fs 변수 선언해주고 readFile method를 통해 파일을 읽는다.
```

**read_file2.js(파일 읽어서 본문 구현)**
```
1. url의 id값에 변화를 주면서 페이지를 로드한다.
2. cmd창에서 node read_file2.js 명령을 재실행 하지 않고도 data 디렉토리 안의 내용을 바꿔도 바로 반영이 된다.
```

**console_input.js(콘솔창에서의 입력)**
```
1. process.argv를 통해 사용자 입력을 받는다.
2. index 2부터 사용자 입력을 받게 됨을 주의한다.
```

**not_found.js(Not Found 오류 구현)**
```
1. url.parse().pathname을 이용하여 '/'가 아닌 다른 경로로 들어온다면 'Not Found' message가 보이게 한다. 
```

**homepage.js(홈페이지 구현)**
```
1. not_found.js에서의 구현을 보면 '/'로 들어오면 title과 descripttion이 undefined로 실행된다.
1-1. 또 다른 조건문을 주어 id의 값이 없을때 homepage가 나오도록 구현하였다.
```

**read_dir.js(파일 목록 알아내기)**
```
1. homepage.js에서 template 부분의 ul의 li는 유동적으로 바뀔수 있다.
1-1. 그러기 위해서 data folder의 파일 목록을 알아낸다면 적용시킬 수 있다.
```

**read_dir2.js(글목록 출력하기)**
```
1. read_dir.js에서 이용한 readdir method를 통해 실제로 적용시켜본다.
2. data folder에 Node.js를 추가하면 재실행하지 않고도 새로고침을 통해 페이지가 동적으로 변한 것을 확인 할 수 있다.
```

**function.js(함수를 이용해서 정리 정돈하기)**
```
1. 전체적으로 반복되는 코드가 많아서 전체 코드의 길이가 길어진다.
1-1. function을 이용하여 길어진 코드를 보기 깔끔하게 수정한다.
```

**sync.js(동기적 수행)**
```
1. 동기적으로 수행하여 A, B, C 순으로 출력한다.
```

**async.js(비동기적 수행)**
```
1. 비동기적으로 수행하여 A, C, B 순으로 출력한다.
```

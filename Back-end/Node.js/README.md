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

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

```
----------------------------------
main.js(node.js의 웹서버 구현)

1. request.url로 url 정보를 얻는다.
2. response.end()로 결과를 실행.
----------------------------------
```

```
-----------------------------------------------------------
url_parse.js(url를 parsing한 data를 이용)

1. url.parse().query method를 이용하여 queryData 값을 얻는다.
1-1) option으로 true를 주면 Object로 반환한다.
2. response.end(queryData.id)로 결과 확인.
-----------------------------------------------------------
```

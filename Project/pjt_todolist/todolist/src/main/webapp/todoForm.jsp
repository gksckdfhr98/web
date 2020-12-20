<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ page isELIgnored="false" %>    

<!DOCTYPE html>
<html lang="en" dir="ltr">
  <head>
    <meta charset="utf-8">
    <title></title>
    <link rel="stylesheet" href="./css/todoForm.css">
  </head>
  <body>
    <header>
      <h1>할일 등록</h1>
    </header>
    <section>
      <form class="form" action="todoForm" method="post">
        <ul id="ul">
          <li id="li_1">
            <p>어떤일인가요?</p>
            <input type="text" name="title" value="" maxlength="24" style="width:600px; height:40px;">
          </li>
          <li id="li_2">
            <p>누가 할일인가요?</p>
            <input type="text" name="name" value="" style="width:200px; height:40px;">
          </li>
          <li id="li_3">
            <p>우선순위를 선택하세요</p>
            <input type="radio" name="order" value="1"><strong>1순위</strong>
            <input type="radio" name="order" value="2"><strong>2순위</strong>
            <input type="radio" name="order" value="3"><strong>3순위</strong><br><br><br>
          </li>
          <li id="li_4">
            <p id="before"><strong>< 이전</strong></p>
            <input id="submit" type="submit" name="" value="제출">
            <input id="reset" type="reset" name="" value="내용지우기">
          </li>
        </ul>
      </form>
    </section>
  </body>
  <script type="text/javascript" src="./js/todoForm.js">  
  </script>
</html>

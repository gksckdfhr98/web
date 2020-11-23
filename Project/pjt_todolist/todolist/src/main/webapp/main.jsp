<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ page isELIgnored="false" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>

<script>
var list=[];

<c:forEach var="item" items="${list}" varStatus="status">
	list[${status.index+1}] = {
		id : ${item.id},
		name : "${item.name}",
		regDate : "${item.regDate}",
		sequence : ${item.sequence},
		title : "${item.title}",
		type : "${item.type}"
	}
</c:forEach>
</script>

<!DOCTYPE html>
<html lang="en" dir="ltr">
  <head>
    <meta charset="utf-8">
    <title></title>
    <link rel="stylesheet" href="./css/main.css">
  </head>
  <body>
    <header>
      <div>
        <span id="title">나의 해야할 일들</span>
        <span id="todo">새로운 TODO 등록</span>
      </div>
    </header>
    <section>
      <ul>
        <li id="li_todo">
          TODO
          <ul id="todo_ul">
          	<c:forEach var="item" items="${list}">
				<c:if test="${item.type=='TODO'}">
					<li>
						<p><strong>${item.title}</strong></p>
						<span>등록날짜:${item.regDate}, ${item.name}, 우선순위 ${item.sequence}
							<button id="${item.id}" onClick="change(list[this.id])">-></button>
						</span>
					</li>
				</c:if>
			</c:forEach>
          </ul>
        </li>
        <li id="li_doing">
          DOING
          <ul id="doing_ul">
          	<c:forEach var="item" items="${list}">
				<c:if test="${item.type=='DOING'}">
					<li>
						<p><strong>${item.title}</strong></p>
						<span>등록날짜:${item.regDate}, ${item.name}, 우선순위 ${item.sequence}
							<button id="${item.id}" onClick="change(list[this.id])">-></button>
						</span>
					</li>
				</c:if>
			</c:forEach>
          </ul>
        </li>
        <li id="li_done">
          DONE
          <ul id="done_ul">
          	<c:forEach var="item" items="${list}">
				<c:if test="${item.type=='DONE'}">
					<li>
						<p><strong>${item.title}</strong></p>
						<span>등록날짜:${item.regDate}, ${item.name}, 우선순위 ${item.sequence}</span>
					</li>
				</c:if>
			</c:forEach>
          </ul>
        </li>
      </ul>
    </section>
  </body>
  <script type="text/javascript" src="./js/main.js"></script>
</html>

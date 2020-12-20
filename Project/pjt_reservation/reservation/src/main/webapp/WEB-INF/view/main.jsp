<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>

<%@ page isELIgnored="false" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>



<!DOCTYPE html>
<html lang="ko">

<head>
    <meta charset="utf-8">
    <meta name="description" content="숭실 예약, 숭실 예약이 연동된 곳 어디서나 바로 예약하고, 숭실 예약 홈(나의예약)에서 모두 관리할 수 있습니다.">
    <meta name="viewport" content="width=device-width,initial-scale=1,maximum-scale=1,minimum-scale=1,user-scalable=no">
    <title>숭실 예약</title>
    <link href="./resources/css/main.css" rel="stylesheet">
</head>

<body>
    <div id="container">
        <div class="header">
            <header class="header_tit">
                <h1 class="logo">
                    <a href="${pageContext.request.contextPath}/main" class="lnk_logo" title="Home"> <span class="spr_bi ico_n_logo">숭실</span> </a>
                    <%-- <a href="${pageContext.request.contextPath}/main" class="lnk_logo" title="예약"> <span class="spr_bi ico_bk_logo">예약</span> </a> --%>
                </h1>
                <a href="${pageContext.request.contextPath}/bookinglogin" class="btn_my" style="right:100px;"> <span class="viewReservation" title="예약확인">예약확인</span> </a>
                <a href="${pageContext.request.contextPath}/logout" class="btn_my"> <span class="logout" title="로그아룻">로그아웃</span> </a>
            </header>
        </div>
        <hr>
        <div class="event">
            <div class="section_visual">
                <div class="group_visual">
                    <div class="container_visual">
                        <div class="prev_e" style="display:none;">
                            <div class="prev_inn">
                                <a href="#" class="btn_pre_e" title="이전"> <i class="spr_book_event spr_event_pre">이전</i> </a>
                            </div>
                        </div>
                        <div class="nxt_e" style="display:none;">
                            <div class="nxt_inn">
                                <a href="#" class="btn_nxt_e" title="다음"> <i class="spr_book_event spr_event_nxt">다음</i> </a>
                            </div>
                        </div>
                        <div>
                            <div class="container_visual">
                                <!-- 슬라이딩기능: 이미지 (type = 'th')를 순차적으로 노출 -->
                                <ul class="visual_img">
                                	<c:forEach items="${promotion.items}" var="promotion" varStatus="status">
                                		<li id="promotion_slide" class="item" style="background-image: url(./resources/${promotion.productImageUrl}); width: 100%; overflow:hidden;">
									       <a href="#"> <span class="img_btm_border"></span> <span class="img_right_border"></span> <span class="img_bg_gra"></span>
									           <div class="event_txt">
									               <h4 class="event_txt_tit"></h4>
									               <p class="event_txt_adr"></p>
									               <p class="event_txt_dsc"></p>
									           </div>
									       </a>
									   </li>
                                	</c:forEach>
                                </ul>
                            </div>
                            <span class="nxt_fix" style="display:none;"></span>
                        </div>
                    </div>
                </div>
            </div>
            <div class="section_event_tab">
                <ul class="event_tab_lst tab_lst_min">
                    <li class="item" data-category="0">
                        <a id="0" class="anchor active" onClick="total(this.id)"> <span>전체리스트</span> </a>
                    </li>
                    <c:forEach var="item" items="${categoryResponse.items}" varStatus="status">
                    	<li class=item" data-category="${status.index+1}">
                    		<a id="${status.index+1}" class="anchor" onClick="total(this.id)"> <span>${item.name}</span> </a>
                    	</li>
                    </c:forEach>
                    
                    <!-- li class="item" data-category="7">
                        <a class="anchor"> <span>클래스</span> </a>
                    </li>
                    <li class="item" data-category="8">
                        <a class="anchor"> <span>체험</span> </a>
                    </li>
                    <li class="item" data-category="9">
                        <a class="anchor last"> <span>키즈</span> </a>
                    </li -->
                </ul>
            </div>
            <div class="section_event_lst">
            	<p class="event_lst_txt">바로 예매 가능한 행사가 <span class="pink">${totalCount}</span> 있습니다</p>
                <div class="wrap_event_box">
                    <!-- [D] lst_event_box 가 2컬럼으로 좌우로 나뉨, 더보기를 클릭할때마다 좌우 ul에 li가 추가됨 -->
                    <ul class="lst_event_box">
                    </ul>
                    <ul class="lst_event_box">
                    </ul>
                    <!-- 더보기 -->
                    <div class="more">
                        <button class="btn" onClick="more()"><span>더보기</span></button>
                    </div>
                </div>
            </div>
        </div>
    </div>
    <footer>
        <div class="gototop">
            <a class="lnk_top" onclick="window.scrollTo(0,0);"> <span class="lnk_top_text">TOP</span> </a>
        </div>
        <div class="footer" id="footer">
            <p class="dsc_footer">숭실(주)는 통신판매의 당사자가 아니며, 상품의정보, 거래조건, 이용 및 환불 등과 관련한 의무와 책임은 각 회원에게 있습니다.</p>
            <span class="copyright">© SOONGSIL Corp.</span>
        </div>
    </footer>


    <script type="rv-template" id="promotionItem">
    <li class="item" style="background-image: url(./resources/{url});">
        <a href="#"> <span class="img_btm_border"></span> <span class="img_right_border"></span> <span class="img_bg_gra"></span>
            <div class="event_txt">
                <h4 class="event_txt_tit"></h4>
                <p class="event_txt_adr"></p>
                <p class="event_txt_dsc"></p>
            </div>
        </a>
    </li>
    </script>

    <script type="rv-template" id="itemList">
        <li class="item">
            <a href="${pageContext.request.contextPath}/detail?id={{displayInfoId}}" class="item_book">
                <div class="item_preview">
                    <img alt="{{productDescription}}" class="img_thumb" src="./resources/{{productImageUrl}}">
                    <span class="img_border"></span>
                </div>
                <div class="event_txt">
                    <h4 class="event_txt_tit"> <span>{{productDescription}}</span> <small class="sm">{{placeName}}</small> </h4>
                    <p class="event_txt_dsc">{{productContent}}</p>
                </div>
            </a>
        </li>
    </script>
    <script src="http://code.jquery.com/jquery-1.11.2.min.js"></script>
    <script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/handlebars.js/4.7.6/handlebars.min.js"></script>
    <script type="text/javascript" src="./resources/js/main.js"></script>
</body>

</html>

window.addEventListener("load",function(){
	var query = "id="+id;
	$.ajax({
		url : "/api/detail",
		type : "get",
		data : query,
		success : function(result){
			if(result){
			}
			else{
				$(".btn_prev").css("display","none");
				$(".btn_nxt").css("display","none");
			}
		}
	});
});

document.addEventListener("DOMContentLoaded",function(){
	var graph = document.querySelector(".graph_value");
	
	graph.style.width = graph_val + "%";
})


function fold(){
	var unfold = document.querySelector(".bk_more._open");
	var fold = document.querySelector(".bk_more._close");
	var details_close = document.querySelector(".store_details.close3");
	var details = document.querySelector(".store_details");
	
	if(unfold.style.display==""){
		unfold.style.display="none";
		details_close.className="store_details";
		fold.style.display="";
	}
	else if(fold.style.display==""){
		fold.style.display="none";
		details.className="store_details close3";
		unfold.style.display="";
	}
};

$('.nxt_inn').click(function(){
	var img1 = document.querySelector(".visual_img.detail_swipe");
	img1.style.right = " +100%";
	img1.style.transition = "all 1s";
	document.querySelector(".num").innerText = "2";
});

$('.prev_inn').click(function(){
	var img1 = document.querySelector(".visual_img.detail_swipe");
	img1.style.right = "0%";
	img1.style.transition = "all 1s";
	document.querySelector(".num").innerText = "1";
});

$('.section_btn').click(function(){
	location.href="/reserve?id="+id;
});

$('.item.active._detail').click(function(){
	$('.info_tab_lst li:nth-child(1) a').attr('class','anchor active');
	$('.info_tab_lst li:nth-child(2) a').attr('class','anchor');
	console.log($('.section_info_tab:nth-child(2)'));
	$('.section_info_tab > div:nth-child(2)').attr('class','detail_area_wrap');
	$('.section_info_tab > div:nth-child(3)').attr('class','detail_location hide');
});



$('.item._path').click(function(){
	$('.info_tab_lst li:nth-child(1) a').attr('class','anchor');
	$('.info_tab_lst li:nth-child(2) a').attr('class','anchor active');
	$('.section_info_tab > div:nth-child(2)').attr('class','detail_area_wrap hide');
	$('.section_info_tab > div:nth-child(3)').attr('class','detail_location');
});


var categoryid=0;
var more_start=4;

window.addEventListener("load",function(){
	$('#0').click();
});

function total(id){
	document.querySelector(".btn").style.display = "";
	var query = "id="+id;
	$.ajax({
		url : "/api/category",
		type : "get",
		data : query,
		dataType : "json",
		success : function(result){
			var html = document.querySelector(".pink");
			html.innerHTML = result.count + "개";
		},
		error : function(){
			alert("error");
		}
	});
	
	var menu = document.querySelectorAll(".event_tab_lst li a");
	for(var i=0,len=menu.length; i<len;i++){
		var cur = menu[i];
		if(id == i){
			cur.style.color = "#29b5b5";
			cur.style.borderBottom = "2px solid #29b5b5";
		}
		else{
			cur.style.color = "#000000";
			cur.style.borderBottom = "2px solid #ffffff";
		}
	}
	var query2 = "categoryId="+id;
	$.ajax({
		url : "/api/product",
		type : "get",
		data : query2,
		dataType : "json",
		success : function(result){
			var product = result.items;
			var html = document.querySelector("#itemList").innerHTML;
			
			var firstUl = document.querySelector(".wrap_event_box ul:nth-child(1)");
			var secondUl = document.querySelector(".wrap_event_box ul:nth-child(2)");
			
			var resultHTML="";
			
			var bindTemplate = Handlebars.compile(html);
			for(var i=0;i<3;i+=2){
				resultHTML+= bindTemplate(product[i]);
			}
			firstUl.innerHTML = resultHTML;
			resultHTML="";
			
			for(var i=1;i<4;i+=2){
				resultHTML+= bindTemplate(product[i]);
			}
			secondUl.innerHTML = resultHTML;
		},
		error : function(){
			alert("error");
		}
	});
	categoryid=id;
	more_start=4;
}

function more(){
	var query = "categoryId="+categoryid+"&start="+more_start;
	$.ajax({
		url : "/api/product",
		type : "get",
		data : query,
		success : function(result){
			var product = result.items;
			if(product === null || product.length == 0){
				document.querySelector(".btn").style.display = "none";
			}
			else{
				var len = product.length;
				var html = document.querySelector("#itemList").innerHTML;
				var firstUl = document.querySelector(".wrap_event_box ul:nth-child(1)");
				var secondUl = document.querySelector(".wrap_event_box ul:nth-child(2)");
				var resultHTML="";
				
				var bindTemplate = Handlebars.compile(html);
				
				for(var i=0;i<len;i=i+2){
					resultHTML+= bindTemplate(product[i]);
				}
				firstUl.innerHTML += resultHTML;
				resultHTML="";
				
				for(var i=1;i<len;i=i+2){
					resultHTML+= bindTemplate(product[i]);
				}
				secondUl.innerHTML += resultHTML;
			}
		},
		error : function(){
			alert("error");
		}
	})
	event.stopPropagation();
	more_start+=4;
};


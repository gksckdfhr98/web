var total_count=0;
var agreement_btn=0;


function minus(id){
	var count = document.getElementById(id).parentNode.children[1].value;
	count--;
	var plus_btn = document.getElementById(id).parentNode.children[2];
	if(count<0) count=0;
	else if(count>10) count=10;
	else{
		if(count == 0){
			document.getElementById(id).className = "btn_plus_minus spr_book2 ico_minus3 disabled";
		}
		else if(count == 10){
			document.getElementById(id).className = "btn_plus_minus spr_book2 ico_minus3";
			plus_btn.className = "btn_plus_minus spr_book2 ico_plus3 disabled";
		}
		else{
			document.getElementById(id).className = "btn_plus_minus spr_book2 ico_minus3";
			plus_btn.className = "btn_plus_minus spr_book2 ico_plus3";
		}
		total_count--;
	}
	document.getElementById(id).parentNode.children[1].value = count;
	var price_id = id.substring(6);
	var price = parseInt(document.getElementById(price_id).innerText);
	document.querySelector("#total_"+price_id).innerText = price*count;
	document.querySelector("#totalCount").innerText = total_count;
};

function plus(id){
	var count = parseInt(document.getElementById(id).parentNode.children[1].value);
	count++;
	var minus_btn = document.getElementById(id).parentNode.children[0];
	
	if(count<0) count=0;
	else if(count>10) count=10;
	else{
		if(count == 0){
			minus_btn.className = "btn_plus_minus spr_book2 ico_minus3 disabled";
		}
		else if(count == 10){
			minus_btn.className = "btn_plus_minus spr_book2 ico_minus3";
			document.getElementById(id).className = "btn_plus_minus spr_book2 ico_plus3 disabled";
		}
		else{
			minus_btn.className = "btn_plus_minus spr_book2 ico_minus3";
			document.getElementById(id).className = "btn_plus_minus spr_book2 ico_plus3";
		}
		total_count++;
	}
	document.getElementById(id).parentNode.children[1].value = count;
	
	var price_id = id.substring(5);
	var price = parseInt(document.getElementById(price_id).innerText);
	document.querySelector("#total_"+price_id).innerText = price*count;
	document.querySelector("#totalCount").innerText = total_count;
};

function agreement(cur){
	if(agreement_btn==0){
		cur.parentNode.className = "agreement open";
		agreement_btn=1;
	}
	else{
		cur.parentNode.className = "agreement";
		agreement_btn=0;
	}
};


$(document).ready(function(){
	$('#chk3').change(function(){
		validCheck();
	});
	$('#name').click(function(){
		validCheck();
	});
	$('#email').click(function(){
		validCheck();
	});
	$('#tel').click(function(){
		validCheck();
	});
	$('.count_control').click(function(){
		validCheck();
	});
});

function validCheck(){
	var count = parseInt($('#totalCount').text());
	var name = $('#name').val();
	var email = $('#email').val();
	var tel = $('#tel').val();
	if($('#chk3').prop("checked") && count >= 1 && name != "" && email != "" && tel != ""){
		$('.box_bk_btn').children('div').attr('class','bk_btn_wrap');
	}
	else{
		$('.box_bk_btn').children('div').attr('class','bk_btn_wrap disable');
	}
}

document.querySelector(".bk_btn").addEventListener("click",function(){
	if($('.box_bk_btn').children('div').attr('class') == "bk_btn_wrap"){
		valid();
	}
});

function valid(){
	var telephone = $('#tel').val();
	var bvalid = (/01[01789]-\d{3,4}-\d{4}/).test(telephone);
	var email = $('#email').val();
	var email_valid = (/^[0-9a-zA-Z]([-_.]?[0-9a-zA-Z])*@[0-9a-zA-Z]([-_.]?[0-9a-zA-Z])*.[a-zA-Z]{2,3}$/i).test(email);
	if(!email_valid){
		alert('이메일 형식이 잘못되었습니다.');
		return;
	}
	if(!bvalid){
		alert($('.warning_msg').text());
		return;
	}
	else{
		var form = document.querySelector(".form_horizontal");
		for(var i=0;i<size;i++){
			var input = document.createElement('input');
			var val = $('#minus_'+i).parent().children('input').val();
			input.style.display="none";
			input.type="text";
			input.name = "price_"+i;
			input.value = val;
			form.appendChild(input);
		}
		$('.form_horizontal').submit();
	}
}
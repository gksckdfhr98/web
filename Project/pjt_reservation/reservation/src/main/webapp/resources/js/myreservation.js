function cancel(cur){
	$('.popup_booking_wrapper').css('display','block');
	var id = cur.id;
	var productName = $('#'+id).parent().children('h4').text();
	var schedule = $('#'+id).parent().children('ul').children('li:nth-child(1)').children('em').text();
	$('.pop_tit').children('span').text(productName);
	$('.pop_tit').children('small').text(schedule);
	
	$('.btn_gray').click(function(){
		$('.popup_booking_wrapper').css('display','none');
	});
	$('.popup_btn_close').click(function(){
		$('.popup_booking_wrapper').css('display','none');
	});
	
	$('.btn_green').click(function(){
		$('#'+id).closest('li').attr('class','card used');
		$('#'+id).closest('li').children('div').children('div').children('div:nth-child(2)').children('i').attr('class','spr_book2 ico_cancel');
		$('#'+id).closest('li').children('div').children('div').children('div:nth-child(2)').children('span').text("취소된 예약");
		$('#'+id).css('display','none');
		$('.popup_booking_wrapper').css('display','none');
		var reserve_id = $('#'+id).closest('li').attr('id');
		renew();
		sendServer(reserve_id);
	});
};

function renew(){
	var reservation_count = parseInt($('.spr_book2.ico_book_ss').parent().children('span').text());
	reservation_count--;
	$('.spr_book2.ico_book_ss').parent().children('span').text(reservation_count);
	
	var cancel_count = parseInt($('.spr_book2.ico_back').parent().children('span').text());
	cancel_count++;
	$('.spr_book2.ico_back').parent().children('span').text(cancel_count);
};

function sendServer(reserve_id){
	$.ajax({
		url : "/reservations/"+reserve_id,
		type : "get",
		contentType : "application/json",
		dataType : "json",
		success : function(result){
			if(result){
				alert('예약이 취소되었습니다.');
				location.reload();
			}
		}
	});
}
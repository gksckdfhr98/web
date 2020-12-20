$('.rating input').click(function(){
	var count = parseInt($(this).val());
	$(this).parent().children('input').attr('class','rating_rdo').attr('checked',false);
	$(this).attr('class','rating_rdo checked').prevAll('input').attr('class','rating_rdo checked');
	if(count>0){
		$('.rating span:last-child').attr('class','star_rank').text(count);
	}
	else{
		$('.rating span:last-child').attr('class','star_rank gray_star').text(count);
	}
})

$('.review_write_info').click(function(){
	$(this).css('display','none');
	$('.review_textarea').focus();
})

const elImage = document.querySelector('#reviewImageFileOpenInput');

elImage.addEventListener("change",function(evt){
	file = evt.target.files[0];
	const image1 = document.querySelector('.item_thumb');
	image1.src = window.URL.createObjectURL(file);
});

$('.anchor').click(function(){
	$(this).parent().children('img').attr('src','');
});

$(function(){
	$('.review_textarea').keyup(function(){
		var content = $(this).val();
		$(this).height(((content.split('\n').length + 1) * 1.5) + 'em'); 
		$('.guide_review > span:nth-child(1)').html(content.length);
	});
	$('.review_textarea').keyup();
});

$('.box_bk_btn').click(function(){
	var score = $('.rating span:last-child').text();
	var comment = $('.review_textarea').val();
	$('#productId').val(product_id);
	$('#score').val(score);
	$('#comment').val(comment);
	$('#upload').submit();
})


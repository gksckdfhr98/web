$("#btn1").click(function(e){
	e.preventDefault();
	var email = $('#resrv_id').val();
	var bvalid = (/^[0-9a-zA-Z]([-_.]?[0-9a-zA-Z])*@[0-9a-zA-Z]([-_.]?[0-9a-zA-Z])*.[a-zA-Z]{2,3}$/i).test(email);
	if(!bvalid){
		alert('잘못된 이메일 형식입니다.');
	}
	else{
		$('#form1').submit();
	}
})

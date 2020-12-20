
$('#check').click(function(){
	var email = $('#resrv_id').val();
	var obj = {
			"id" : email
	};
	$.ajax({
		url : "/api/signup",
		type : "post",
		data : JSON.stringify(obj),
		contentType : "application/json",
		dataType : "json",
		success : function(data){
			if(data){
				alert("사용가능한 아이디입니다.");
			}
			else{
				alert("중복된 아이디입니다.");
				location.reload();
			}
		},
		error : function(){
			alert("에러발생");
		}
	})
});

$("#submit_btn").click(function(e){
	e.preventDefault();
	var email = $('#resrv_id').val();
	var tel = $('#resrv_tel').val();
	var bvalid_tel = (/01[01789]-\d{3,4}-\d{4}/).test(tel);
	var bvalid_email = (/^[0-9a-zA-Z]([-_.]?[0-9a-zA-Z])*@[0-9a-zA-Z]([-_.]?[0-9a-zA-Z])*.[a-zA-Z]{2,3}$/i).test(email);
	if(!bvalid_email){
		alert('잘못된 이메일 형식입니다.');
		return;
	}
	if(!bvalid_tel){
		alert("잘못된 전화번호 형식입니다.");
		return;
	}
	else{
		alert('전송');
		$('#form1').submit();
	}
});

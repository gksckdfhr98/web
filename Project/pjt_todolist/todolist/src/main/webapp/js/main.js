var reg = document.getElementById('todo');

reg.addEventListener("click",function(){
	location.href = "todoForm.jsp";
})

function change(data){
	var ajax = new XMLHttpRequest();
	var id = data.id;
	var name = data.name;
	var regDate = data.regDate;
	var sequence = data.sequence;
	var title = data.title;
	var type = data.type;
	var query = "id="+id+"&name="+name+"&regDate="+regDate+
	"&sequence="+sequence+"&title="+title+"&type="+type;
	ajax.addEventListener("load",function(){
		location.reload();
	});
	ajax.open("GET","http://localhost:8080/todolist/main?"+query);
	ajax.setRequestHeader('Content-Type','application/json;charset=UTF-8');
	ajax.send();
}
const form = document.querySelector(".js-form");
  input = form.querySelector("input");
  greeting = document.querySelector(".js-greetings");

const USER_LS = "currentUser";
  SHOWING_CN = "showing";

//localstorage에 user 저장.
function saveName(text){
  localStorage.setItem(USER_LS,text);
}

function handleSubmit(event) {
  // form의 submit을 막음.
  event.preventDefault();
  const currentValue = input.value;
  paintGreeting(currentValue);
  saveName(currentValue);
}
// user가 없다면 이름 요청.
function askForName() {
  form.classList.add(SHOWING_CN);
  form.addEventListener("submit",handleSubmit);
}

// 화면에 user의 이름을 나타내는 함수.
function paintGreeting(text) {
  form.classList.remove(SHOWING_CN);
  greeting.classList.add(SHOWING_CN);
  greeting.innerText = `Hello ${text}`;
}

function loadName() {
  //local storage로부터 value값을 가져옴.
  const currentUser = localStorage.getItem(USER_LS);
  if(currentUser === null){
    askForName();
  }
  else{
    //user가 있다면
    paintGreeting(currentUser);
  }
}

function init(){
  loadName();
}

init();

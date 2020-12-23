console.log("I'm working");

//let,var
let a=221;
let b=a-5;
a=4;
console.log(b, a);

//const - 변하지 않음.
const c=221;
//c=4;

/*String
const what =  "❤";
console.log(what);
*/

/* Number
const what = 666;
console.log(what);
*/

/* Float
const wat - 33.5;
console.log(wat);
*/

// Array
// const daysOfWeek = [];

//Object
const myInfo = {
  name : "changrok",
  age:26,
  gender:"male"
}
// myInfo는 바꿀 수 없지만 그 안의 내용은 바꿀 수 있음.
myInfo.gender = "female";
console.log(myInfo.gender);

//function
//``(백틱) 사용시 ${} 이용.
function sayHello(name){
  console.log(`Hello, ${name}`);
}
sayHello('changrok');

const calculator ={
  plus :function(a,b){
    return a+b;
  }
}

const plus = calculator.plus(5,6);
console.log(plus);

const title = document.querySelector("#title");
// console.log(title);
//console.dir();
// title.innerHTML = "Hi! From JS";
// javascript에서 css 입히는건 별로 안좋음.
// css에 .click{ color : blah~} 를 추가하고 click시 event를 발생시켜 class 추가.
const BASE_COLOR = "rgb(52, 73, 94)";
const OTHER_COLOR ="red";

function handleClick(){
  const currentColor = title.style.color;
  console.log(currentColor);
  if(currentColor === BASE_COLOR){
    title.style.color = OTHER_COLOR;
  }
  else{
    title.style.color = BASE_COLOR;
  }
}
function init(){
    title.style.color = BASE_COLOR;
    title.addEventListener("mouseenter",handleClick);
}
init();

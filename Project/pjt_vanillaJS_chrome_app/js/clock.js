const clockContainer = document.querySelector(".js-clock");
clockTitle = clockContainer.querySelector("h1");


function getTime(){
  const date = new Date();
  const hour = date.getHours();
  const minutes = date.getMinutes();
  const seconds = date.getSeconds();
  // seconds가 10보다 작으면 01,02,... 이 아닌 1,2,3,... 므로 나타나므로 조건문 적용.
  clockTitle.innerText = `${hour}:${minutes < 10 ? `0${minutes}` : minutes}:${seconds < 10 ? `0${seconds}` : seconds}`;
}

function init(){
  getTime();
  //setInterval()을 이용해 1초마다 자동으로 업데이트 되도록 하기.
  setInterval(getTime,1000);
}

init();

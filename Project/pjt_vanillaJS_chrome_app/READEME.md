[VanillaJS]
```
이 Project는 Momentum을 직접 구현한 프로젝트이다.

1. 시계기능 구현
2. local storage를 이용해 사용자 정보를 입력해 나타내는 기능 구현

위의 기능을 Javascript로 구현하였다.
```

***1. js folder***

```
1. clock.js

- new Date()를 통해 현재 시간를 얻고 시/분/초를 각각 구해 setInterval() 함수를 통해 새로고침 없이 반복적으로 현재 시간의 정보를 얻을 수 있다.

2. greeting.js

- local Storage(key,value로 저장)로부터 value 값을 가져와서 user 정보가 있는지 없는지 확인한다.(loadName)

- user가 없다면 이름을 요청한다.(askForName)

-- form의 input이 showing으로 바뀜.

--- submit시에는 화면 전체가 새로고침 되기 때문에 이를 막기 위해 event.preventDefault() 함수를 이용(handleSubmit)
    그 후 화면에 user의 이름을 나타내고(paintGreeting), local Storage에 user를 저장한다.(saveName)
    
- user가 있다면 화면에 user의 이름을 나타낸다.(paintGreeting)
```

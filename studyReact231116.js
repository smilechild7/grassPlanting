// 단락 회로 평가 -> 왼쪽에서 오른쪽으로 진행하는 비교 연산자의 연산순서를 이용한 문법

// && : 첫 피 연산자가 false이면 바로 종료
// || : 첫 피 연산자가 true이면 바로 종료
const getName = (person) => {
  const name = person && person.name; // person이 thruthy면 person.name 으로 가서 해당 값을 name에 반환
                                      // person이 falsy 면 person.name은 null 값을 가짐
  return name || "객체가 아닙니다." // name 이 truthy 면 바로 종료
                                  // name 이 falsy 면 "객체가 아닙니다" 를 리턴
};

let person = {
  name  : "김성은",
  age : 24
};
const name = getName(person);
console.log(name);

//-----------------------------------------------------------------------------------------------------//

// 조건문 업그레이드
const meal = {
  한식 : "불고기",
  양식 : "파스타",
  일식 : "초밥",
  중식 : "멘보샤",
  인도식 : "카레"
};

const getMeal = (mealType) => {
  return meal[mealType] || "굶기";
}

console.log(getMeal("한식"));

//-----------------------------------------------------------------------------------------------------//

// 비 구조화 할당 (구조분해 할당) : 순서대로 배열의 요소를 변수에 쉽게 할당할 수 있음

let arr = [2, 4, 63];

let [first, second, third] = arr; 

let [f,s,t = "three",u] = [5,6]; // "three" : 기본값 할당당

console.log(first, second, third); // 2 4 63
console.log(f,s,t,u); // 5 6 "three" undefined

let a = 10;
let b = 20;
[a, b] = [b, a]; // swap 끝
console.log(a, b); // 20 10

let person = {
  name : "김성은",
  age : 23,
  school : "HYU",
  grade : "A+"
};

let { name : myName, age, grade : mathGrade, school, height = 163} = person; // key 값과 동일한 문자에 해당 value를 할당해준다. 순서가 달라도 무관하며 : 뒤에 원하는 이름으로 할당받을 수도 있다,
console.log( myName, age, school, mathGrade, height); // 김성은 23 HYU A+ 163

//-------------------------------------------------------------------------------------------------------------------------------------------------------------//

// spread 연산자 ... : 요소를 가져온다.
 
const cookies = {
  base : "cookies",
  madein : "korea",
};

const blueBerryCookies = {
  ...cookies,
  toping : "blueBerry"
};

const chocolateCookies = {
  ...cookies,
  toping : "chocolate"
};

const strawBerryCookies = {
  ...cookies,
  toping : "strawBerry"
};

console.log(cookies); // {base: "cookies", madein: "korea"}
console.log(blueBerryCookies); // {base: "cookies", madein: "korea", toping: "blueBerry"}
console.log(chocolateCookies); // {base: "cookies", madein: "korea", toping: "chocolate"}
console.log(strawBerryCookies); // {base: "cookies", madein: "korea", toping: "strawBerry"}

// 배열을 합칠 때도 도움이 됨

const topingCookies = ["바나나쿠키", "딸기 쿠키", "초코쿠키"];
const noTopingCookies = ["촉촉한쿠키", "퍽퍽한쿠키"];
const allCookies = [...topingCookies, "애매한쿠키", ...noTopingCookies];

console.log(allCookies); //["바나나쿠키", "딸기 쿠키", "초코쿠키", "애매한쿠키", "촉촉한쿠키", "퍽퍽한쿠키"]

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

// 동기(블로킹 방식) : 순서대로 작업을 처리하는데 이전 작업이 진행 중일 때 다른 작업을 수행하지 않고 기다림. 
// 자바스크립트는 일꾼(쓰레드) 가 하나임.
// 동기처리 방식의 문제점 : 하나의 작업이 너무 오래 걸리게 될 시, 전반적인 흐름이 느려진다.
// 비동기(논 블로킹 방식) : 여러개를 동시에 실행시키는 방식. 비동기 처리를 할 때는 콜백함수를 통해서 Task가 끝났는지를 출력해주어야함


function taskA() {
  setTimeout(()=>{ // 내장 비동기 함수. 지정한 시간 뒤에 작업을 수
    console.log("A TASK END")
  },2000)
  console.log("A 작업 끝");
}

taskA();
console.log("코드 끝");


// 콜 스택의 개념
// 비동기 스택은 Web APIs 에 넘긴다. (setTimeout 함수일 시) 정해진 시간 뒤에 setTimeout 내의 콜백함수가 콜백 큐에 들어가고 이벤트 루프에 의해 콜 스택으로 옮겨가게 된다.

function taskA(a, cb){
  setTimeout(()=>{
    const res = a*2;
    cb(res);
  },1000)
};

function taskB(b, cb){
  setTimeout(()=>{
    const res = b-4;
    cb(res);
  },2000)
};

function taskC(c, cb){
  setTimeout(()=>{
    const res = c/3; 
    cb(res);
  },3000)
};

taskA(20,(a_res)=>{
  console.log("Result of taskA : ", a_res);
  taskB(a_res,(b_res)=>{
    console.log("Result of taskB : ", b_res);
    taskC(b_res,(c_res)=>{
      console.log("Result of taskC : ", c_res);
    })
  })
})
console.log("코드 끝");
//코드 끝 
//Result of taskA : 40 
//Result of taskB : 36
//Result of taskC : 12

// 콜백 내의 콜백 내의 콜백 내의 콜백... - 콜백 지옥 -> 해결책 : Promise 객체

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------//



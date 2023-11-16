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

//-----------------------------------------------------------------------------------------------------//

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







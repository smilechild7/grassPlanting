// Truthy, Falsy : 실제로 boolean 값이 아니어도 참과 거짓으로 평가하는 것. 
// 예외처리를 할 때 아주 유용함.
let truthy = [[],{},42,"0","false",Infinity];

for (let i=0; i<truthy.length; i++){
  if (truthy[i]){ 
    console.log("TRUE");
  } else {
    console.log("FALSE");
  }
} // TRUE *6

let falsy = [null,undefined,0,-0,NaN,""];
for (let i=0; i<falsy.length; i++){
  if (falsy[i]){ 
    console.log("TRUE");
  } else {
    console.log("FALSE");
  }
} // FALSE *6

// 예외처리의 예시
const getName = (person) => {
  if(!person){
    return "객체가 아닙니다";
  } else {
    return person.name;
  }
}

let person = {
  name : "김성은"
};
console.log(getName(person)); // 김성은

person = null;
console.log(getName(person)); // 객체가 아닙니다

//---------------------------------------------------------------------------------//
// 삼항 연산자
let a =3;
a>=0 ? console.log("양수") : console.log("음수"); // (조건식) ? (참일 때 수행할 식) : (거짓일 때 수행할 식)













// 객체
let person_ = new Object(); // 생성자 방식
let person = {
  key: "value", // 프로퍼티 (객체 프로퍼티)
  key1: 123,
  key2: "true",
  key3: "undefined",
  key4: [1,2],
  name: "김성은", // 다양한 값을  가질 수 있다
  say: function(){
    console.log('안녕 나는 ${this.name}'); // this는 person과 동일일
  }, // 메서드 -> 방법법
  age: 23 // 멤버 라고 지칭
}; // 객체 리터럴 방식 - 간단해서 많이 쓰임
console.log(person.key2); // 점 표기법법
console.log(person["key1"]); // 괄호표기법 - 반드시 "문자열" 형태로 넣어주어야 함.
// get함수를 쓸 때 유용함
function getPropertyValue(key){
  return person[key];
}
console.log(getPropertyValue("name"));

person.location = "한국"; // 이렇게 객체에 프로퍼티를 추가할 수 있다.
person["age"] = 22; // 이 표기로도 가능하다. 변경도 가능
delete person.age; // 프로퍼티를 삭제. 대괄호도 쓸 수 있음. 연결을 끊는 것 뿐이라 실제로 사라지지 않음.
person.name = null; // 차라리 이렇게 지우는 것을 추천 (메모리에서 날라감)
person.name = "김성은!";
console.log(person.name);
person.say(); //객체 함수 호출

console.log('name : ${"name" in person}');// in 연산자를 활용해서 프로퍼티의 존재여부를 알 수 있다.

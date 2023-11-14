// 배열

let arr=[1,2,3,4]; // 수 이외에도 문자, null, undefined, 함수 등등 다 가능. 한 종류만으로 이루어질 필요없음.
console.log(arr);

arr.push(5); // 배열의 마지막에 요소 추가 가능
console.log(arr); 
console.log("배열의 길이 : "+arr.length);

//-------------------------------------------------------------------------------------------------------------//

//반복문

for (let i=0; i<100; i++){
  console.log(i+1);
} // c++ 과 거의 똑같다.

let person = {
  name : "김성은",
  age : 23,
  grade : "a",
  tall : 163,
  gender : "male"
};

const personKeys = Object.keys(person); // Object.keys 라는 내장함수 활용

for (let i=0;i<personKeys.length;i++){
  const currentKey = personKeys[i]; // 현재 key 
  const currentValue = person[currentKey]; // key 값에 해당하는 value
  console.log(currentKey +" : "+ currentValue);
}
const personValues = Object.values(person); // value를 받는 내장함수도 존재한다.

//-------------------------------------------------------------------------------------------------------------//

//배열 내장함수

const arr = [1,2,3,4];

arr.forEach((elm) => {console.log(elm*2)}); // forEach 내장함수 : 요소 하나씩 함수의 파라미터로 전달

const newArr = arr.map((elm) => { // map 배열 내장함수 : 새로운 배열로 리턴받을 수 있음음
  return arr * 2;
});

let number = 3;

console.log(arr.includes(number)); // includes 내장함수 : 배열에 파라미터로 받은 값이 존재하는지 true / false 값을 리턴
console.log(arr.indexOf(3)); // indexOf 내장함수 : 배열에 파라미터로 받은 값이 존재하면 인덱스를 리턴 없으면 -1

const colorArr = [
  {num : 1, color : "red"},
  {num : 2, color : "black"},
  {num : 3, color : "blue"},
  {num : 4, color : "green"},
  {num : 5, color : "blue"}
];
console.log(colorArr.findIndex((elm) => elm.color === "green")); // findIndex는 배열을 순회하며 만족하는 가장 처음 인덱스를 반환환

const element = colorArr.find((elm) => { // find 내장함수 : 조건에 맞는 요소를 가져온다.
  return elm.color === "blue";
});
console.log(element); // {color: "blue"}

console.log(colorArr.filter((elm)=>elm.color === "blue")); // filter 내장함수 : 조건에 맞는 배열을 배열로 반환받고 싶을 때

console.log(colorArr.slice(0, 4)); // slice 내장함수 : 각각 begin, end 이며 begin 부터 end-1 인덱스 까지만 배열로 반환 

const arr1 = [1,2,3,4];
const arr2 = [4,5,6];

console.log(arr1.concat(arr2)); // concat 내장함수 : 배열 뒤에 배열을 붙여서 출력

let chars = ["나", "다", "가"];
chars.sort(); // 원본 배열을 사전순으로 정렬, 기본적으로 문자로 생각하므로 숫자는 자동으로 안됨

let nums = [0,1,3,4,10,30,20]; 
const compare = (a,b) => { // 따라서 비교함수를 만들어주어야 함. 
  if (a>b){return 1;} // 1이면 a를 뒤로 보내고 
  else if (a<b){return -1;} // -1이면 a를 앞으로 보냄 => 오름차순
  else {return 0;}
};
nums.sort(compare); 
console.log(nums);

const arr3 = ["김성은", "님 ", "안녕하세요. ", "또 오셨군요."];

console.log(arr3.join("")); // join 내장함수 : 문자열 하나로 합쳐서 리턴 / 파라미터는 요소 사이사이에 들어감


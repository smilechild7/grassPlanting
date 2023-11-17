// Promise 예제

function isPositive(number, resolve, reject){
  setTimeout(()=>{
    if (typeof number === "number"){
      // 성공 - resolve
      resolve(number >= 0 ? "양수" : "음수");
      } else {
      // 실패 - reject
      reject("주어진 값이 숫자형 데이터가 아닙니다.");
    }
  },2000);
};

function isPositiveP(number){ // Promise 객체를 활용한 동일한 함수
  const executer = (resolve, reject)=>{ //실행자
    if (typeof number === "number"){
      // 성공 - resolve
      resolve(number >= 0 ? "양수" : "음수");
      } else {
      // 실패 - reject
      reject("주어진 값이 숫자형 데이터가 아닙니다.");
    }
  }
  const asyncTask = new Promise(executer); 
  // 프로미스 객체에 생성자로 실질적 비동기 함수의 실질적인 실행자 함수 executer 사용 -> 바로 executer 실행
  return asyncTask; // 함수의 반환값이 Promise 형태 -> 내장함수 then 과 catch 의 이용이 가능하다.
}

const res = isPositiveP(20);
res.then((result)=>{console.log("작업 성공 : ", result)}).catch((err)=>{console.log("작업 실패 : ", err)})
// Promise의 내장함수 then에서 resolve를 받아오고, catch에서 reject를 받아온다.

/*
isPositive(
  100,
  (res) => {
  console.log("성공적으로 수행됨 : ",res);
  },
  (err) => {
  console.log("실패하였음 : ", err);
  }
);
*/// 콜백을 이용한 비동기 함수의 실행 결과를 구분

//---------------------------------------------------------------------------------------------------------------------------------//

// Promise 를 이용해서 콜백 지옥 탈출하기

function taskA(a){
  return new Promise((resolve, reject)=>{
    setTimeout(()=>{
        const res = a*2;
        resolve(res);
      },1000)
  })
};

function taskB(b){
  return new Promise((resolve, reject)=>{
    setTimeout(()=>{
      const res = b-4;
      resolve(res);
    },2000)
  })
};

function taskC(c){
  return new Promise((resolve, reject)=>{
    setTimeout(()=>{
      const res = c/3; 
      resolve(res);
    },3000)
  })
};

// Promise 타입을 반환해서 또 Promise의 메소드를 사용해서 Promise 타입을 반환 -> 코드를 늘여놓을 수 있음
// 또한 상수로 Promise 타입 변수를 받아놓고, 다른 작업을 중간에 수행할 수도 있음.

taskA(20).then((a_res)=>{ 
  console.log("RESULT OF taskA : ", a_res);
  return taskB(a_res);
}).then((b_res)=>{
  console.log("RESULT OF taskB : ", b_res);
  return taskC(b_res);
}).then((c_res)=>{
  console.log("RESULT OF taskC : ", c_res);
})
console.log("코드 끝");

//---------------------------------------------------------------------------------------------------------------------------------//

// async (비동기)

function delay(ms){
  return new Promise((resolve)=>{
    setTimeout(resolve,ms);
    // 동일한 함수
    /* 
    setTimeout(()=>{
      resolve();
    },ms)
    */

  })
}

async function asyncHello(){ // 리턴값이 Promise의 resolve의 결과값이 됨. 결국 Promise를 반환하는 것.
  
  await delay(3000); 
  // await : 비동기 함수를 마치 동기적인 함수처럼 사용 가능. await 키워드가 붙은 함수는 함수가 끝나기 전까지 다음 코드를 실행하지 않음.
  // await 키워드는 async로 정의된 함수 내에서만 사용가능함.
  return "hello Async";
  /*
  return delay(2000).then((resolve)=>{
    return "hello Async";
  })
  */
}
console.log(asyncHello()); // Promise{<pending>}

asyncHello().then((res)=>{
  console.log(res); // 3초 뒤 hello Async
})

async function main(){ // await을 이용하여 main함수 만들기
  const res = await asyncHello(); 
  console.log(res); // 3초 뒤 hello Async
}
main();

//---------------------------------------------------------------------------------------------------------------------------------//

// API

let response = fetch("https://jsonplaceholder.typicode.com/posts"); // api를 받아올 수 있는 내장함수 (Promise를 반환)
response.then((res)=>{
  console.log(res); // Promise 객체를 반환 (편지를 개봉한 것이 아니라 편지봉투를 받은 것)
})

async function getData(){
  let rawResponse = await fetch("https://jsonplaceholder.typicode.com/posts");
  let jsonResponse = await rawResponse.json(); // json파일을 받는다. 이 api에서는 100개의 Object를 받음. (편지를 읽는 것)
  console.log(jsonResponse);
}

getData();





















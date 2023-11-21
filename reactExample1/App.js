import React from 'react';
// import './App.css';
import MyHeader from './MyHeader';
import Counter from './Counter';
import Container from './Container';
function App() {
  const numberProp = 5;

  const counterProps = {
    a: 1,
    b: 3,
    initialValue: 0,
  };

  return (
    <Container>
      <div>
      <MyHeader/>
      <Counter {...counterProps} /> 
    </div>
    </Container>
  );
}

export default App; // 내보내기

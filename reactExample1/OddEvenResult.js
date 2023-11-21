
const OddEvenResult = ({ count }) => {

    console.log(count);
    return (
        <div>
            <h2>{count} is {count%2===0? "Even" : "Odd"}</h2>
        </div>
    )
};

export default OddEvenResult;
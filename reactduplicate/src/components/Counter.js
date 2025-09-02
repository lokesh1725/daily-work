import React, { useState } from 'react';

function Counter() {
    const [count, setCount] = useState(0);
    
    return (
        <div className="card">
            <h3>🔢 Counter</h3>
            <div className="counter">{count}</div>
            <button className="button" onClick={() => setCount(count - 1)}>-</button>
            <button className="button" onClick={() => setCount(0)}>Reset</button>
            <button className="button" onClick={() => setCount(count + 1)}>+</button>
        </div>
    );
}

export default Counter;

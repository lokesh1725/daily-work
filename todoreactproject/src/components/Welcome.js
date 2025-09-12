import React, { useState } from 'react';

function Welcome() {
    const [name, setName] = useState('');
    
    return (
        <div className="card">
            <h3>👋 Welcome!</h3>
            <input
                className="input"
                type="text"
                placeholder="Enter your name..."
                value={name}
                onChange={(e) => setName(e.target.value)}
            />
            <p>{name ? `Hello, ${name}! Welcome to React!` : 'Please enter your name above'}</p>
        </div>
    );
}

export default Welcome;

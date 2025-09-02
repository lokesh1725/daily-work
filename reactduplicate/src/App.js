import React from 'react';
import Welcome from './components/Welcome';
import Counter from './components/Counter';
import TodoApp from './components/TodoApp';

function App() {
    return (
        <div className="app">
            <div className="header">
                <h1>🚀 My React Project</h1>
                <p>A simple webpage built with React</p>
            </div>
            <div className="content">
                <Welcome />
                <Counter />
                <TodoApp />
            </div>
        </div>
    );
}

export default App;

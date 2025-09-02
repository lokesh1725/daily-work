import React, { useState } from 'react';

function TodoApp() {
    const [todos, setTodos] = useState([
        { id: 1, text: 'Learn React basics', completed: false },
        { id: 2, text: 'Build a simple project', completed: true }
    ]);
    const [newTodo, setNewTodo] = useState('');

    const addTodo = () => {
        if (newTodo.trim()) {
            setTodos([...todos, {
                id: Date.now(),
                text: newTodo,
                completed: false
            }]);
            setNewTodo('');
        }
    };

    const toggleTodo = (id) => {
        setTodos(todos.map(todo =>
            todo.id === id ? { ...todo, completed: !todo.completed } : todo
        ));
    };

    return (
        <div className="card">
            <h3>✅ Todo List</h3>
            <input
                className="input"
                type="text"
                placeholder="Add a new todo..."
                value={newTodo}
                onChange={(e) => setNewTodo(e.target.value)}
                onKeyPress={(e) => e.key === 'Enter' && addTodo()}
            />
            <button className="button" onClick={addTodo}>Add Todo</button>
            
            <div style={{ marginTop: '20px' }}>
                {todos.map(todo => (
                    <div key={todo.id} className="todo-item">
                        <input
                            type="checkbox"
                            checked={todo.completed}
                            onChange={() => toggleTodo(todo.id)}
                        />
                        <span className={`todo-text ${todo.completed ? 'completed' : ''}`}>
                            {todo.text}
                        </span>
                    </div>
                ))}
            </div>
        </div>
    );
}

export default TodoApp;

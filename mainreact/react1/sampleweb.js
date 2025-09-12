import React from "react";

const foodItems = [
  {
    title: "Delicious Food",
    subtitle: "For Healthy Life",
    desc: "Our Chef’s special dish with eggs, curry, and vegetables.",
    img: "https://images.unsplash.com/photo-1546069901-ba9599a7e63c",
  },
  {
    title: "Fresh Chicken Breast",
    subtitle: "With Onions",
    desc: "Juicy grilled chicken served with fresh salad and onions.",
    img: "https://images.unsplash.com/photo-1553621042-f6e147245754",
  },
  {
    title: "Healthy Salad",
    subtitle: "With Greens",
    desc: "A fresh mix of vegetables, lettuce, and dressing.",
    img: "https://images.unsplash.com/photo-1504674900247-0877df9cc836",
  },
  {
    title: "Japanese Sushi",
    subtitle: "With Rice & Fish",
    desc: "Authentic sushi rolls with fresh fish and rice.",
    img: "https://images.unsplash.com/photo-1546069901-ba9599a7e63c",
  },

  
  {
    title: "Cheesy Pizza",
    subtitle: "With Toppings",
    desc: "Hot pizza with cheese, tomato sauce, and toppings.",
    img: "https://images.unsplash.com/photo-1553621042-f6e147245754",
  },
];

export default function App() {
  return (
    <div className="min-h-screen bg-gradient-to-r from-yellow-50 to-red-50 p-8">
      <h1 className="text-4xl font-bold text-center mb-8">🍴 Taste The Best</h1>
      <div className="grid sm:grid-cols-2 lg:grid-cols-3 gap-8 max-w-6xl mx-auto">
        {foodItems.map((food, index) => (
          <div
            key={index}
            className="rounded-2xl shadow-lg bg-white overflow-hidden hover:scale-105 transition-transform duration-300"
          >
            <img src={food.img} alt={food.title} className="w-full h-56 object-cover" />
            <div className="p-4">
              <h2 className="text-xl font-bold">{food.title}</h2>
              <p className="text-gray-500 text-sm">{food.subtitle}</p>
              <p className="mt-2 text-gray-600">{food.desc}</p>
              <div className="mt-4 flex gap-3">
                <button className="px-4 py-2 bg-red-500 text-white rounded-lg hover:bg-red-600">
                  View Menu
                </button>
                <button className="px-4 py-2 border rounded-lg hover:bg-gray-100">
                  Book A Table
                </button>
              </div>
            </div>
          </div>
        ))}
      </div>
    </div>
  );
}

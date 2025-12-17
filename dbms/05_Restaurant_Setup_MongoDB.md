# 🍝 Program 5: Restaurant Database (MongoDB) Setup

## 🛠️ Collection & Data Creation

```javascript
use restaurant_db

db.restaurant.drop()

db.restaurant.insertMany([
  {
    id: 1,
    name: "Truffles",
    cuisine: "American",
    address: { building: "123", street: "St Marks Road", area: "CBD", pincode: "560001", city: "Bangalore" },
    nearby_landmarks: ["Museum", "Metro"],
    online_delivery: "yes",
    famous_for: "Burgers"
  },
  {
    id: 2,
    name: "Empire",
    cuisine: "North Indian Thali",
    address: { building: "456", street: "Church Street", area: "CBD", pincode: "560001", city: "Bangalore" },
    nearby_landmarks: ["Metro Station"],
    online_delivery: "yes",
    famous_for: "Ghee Rice"
  },
  {
    id: 3,
    name: "Chianti",
    cuisine: "Italian",
    address: { building: "789", street: "Indiranagar", area: "12th Main", pincode: "560038", city: "Bangalore" },
    nearby_landmarks: ["Park"],
    online_delivery: "no",
    famous_for: "Pasta"
  },
  {
    id: 4,
    name: "Meghana Foods",
    cuisine: "Andhra",
    address: { building: "101", street: "Koramangala", area: "5th Block", pincode: "560095", city: "Bangalore" },
    nearby_landmarks: ["Forum Mall"],
    online_delivery: "yes",
    famous_for: "Biryani"
  },
  {
    id: 5,
    name: "Little Italy",
    cuisine: "Italian",
    address: { building: "202", street: "Indiranagar", area: "100ft Road", pincode: "560038", city: "Bangalore" },
    nearby_landmarks: ["Starbucks"],
    online_delivery: "yes",
    famous_for: "Pizza"
  },
  {
    id: 6,
    name: "Nagarjuna",
    cuisine: "Andhra",
    address: { building: "303", street: "Residency Road", area: "CBD", pincode: "560025", city: "Bangalore" },
    nearby_landmarks: ["Galaxy Theatre"],
    online_delivery: "yes",
    famous_for: "Meals"
  },
  {
    id: 7,
    name: "Toit",
    cuisine: "Continental",
    address: { building: "404", street: "Indiranagar", area: "100ft Road", pincode: "560038", city: "Bangalore" },
    nearby_landmarks: ["Metro"],
    online_delivery: "no",
    famous_for: "Pizza"
  },
  {
    id: 8,
    name: "Gramin",
    cuisine: "North Indian Thali",
    address: { building: "505", street: "Koramangala", area: "7th Block", pincode: "560095", city: "Bangalore" },
    nearby_landmarks: ["Raheja Arcade"],
    online_delivery: "yes",
    famous_for: "Roti"
  },
  {
    id: 9,
    name: "Corner House",
    cuisine: "Desserts",
    address: { building: "606", street: "Indiranagar", area: "12th Main", pincode: "560038", city: "Bangalore" },
    nearby_landmarks: ["School"],
    online_delivery: "yes",
    famous_for: "DBC"
  },
  {
    id: 10,
    name: "MTR",
    cuisine: "South Indian",
    address: { building: "707", street: "Lalbagh Road", area: "Mavalli", pincode: "560004", city: "Bangalore" },
    nearby_landmarks: ["Lalbagh"],
    online_delivery: "yes",
    famous_for: "Dosa"
  }
]);
```

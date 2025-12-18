# 🍝 Program 5: Restaurant Database (MongoDB) Setup

## 🛠️ Collection & Data Creation

```javascript
use restaurant_db

db.restaurant.drop()

db.restaurant.insertmany([
  {
    id: 1,
    name: "truffles",
    cuisine: "american",
    address: { building: "123", street: "st marks road", area: "cbd", pincode: "560001", city: "bangalore" },
    nearby_landmarks: ["museum", "metro"],
    online_delivery: "yes",
    famous_for: "burgers"
  },
  {
    id: 2,
    name: "empire",
    cuisine: "north indian thali",
    address: { building: "456", street: "church street", area: "cbd", pincode: "560001", city: "bangalore" },
    nearby_landmarks: ["metro station"],
    online_delivery: "yes",
    famous_for: "ghee rice"
  },
  {
    id: 3,
    name: "chianti",
    cuisine: "italian",
    address: { building: "789", street: "indiranagar", area: "12th main", pincode: "560038", city: "bangalore" },
    nearby_landmarks: ["park"],
    online_delivery: "no",
    famous_for: "pasta"
  },
  {
    id: 4,
    name: "meghana foods",
    cuisine: "andhra",
    address: { building: "101", street: "koramangala", area: "5th block", pincode: "560095", city: "bangalore" },
    nearby_landmarks: ["forum mall"],
    online_delivery: "yes",
    famous_for: "biryani"
  },
  {
    id: 5,
    name: "little italy",
    cuisine: "italian",
    address: { building: "202", street: "indiranagar", area: "100ft road", pincode: "560038", city: "bangalore" },
    nearby_landmarks: ["starbucks"],
    online_delivery: "yes",
    famous_for: "pizza"
  },
  {
    id: 6,
    name: "nagarjuna",
    cuisine: "andhra",
    address: { building: "303", street: "residency road", area: "cbd", pincode: "560025", city: "bangalore" },
    nearby_landmarks: ["galaxy theatre"],
    online_delivery: "yes",
    famous_for: "meals"
  },
  {
    id: 7,
    name: "toit",
    cuisine: "continental",
    address: { building: "404", street: "indiranagar", area: "100ft road", pincode: "560038", city: "bangalore" },
    nearby_landmarks: ["metro"],
    online_delivery: "no",
    famous_for: "pizza"
  },
  {
    id: 8,
    name: "gramin",
    cuisine: "north indian thali",
    address: { building: "505", street: "koramangala", area: "7th block", pincode: "560095", city: "bangalore" },
    nearby_landmarks: ["raheja arcade"],
    online_delivery: "yes",
    famous_for: "roti"
  },
  {
    id: 9,
    name: "corner house",
    cuisine: "desserts",
    address: { building: "606", street: "indiranagar", area: "12th main", pincode: "560038", city: "bangalore" },
    nearby_landmarks: ["school"],
    online_delivery: "yes",
    famous_for: "dbc"
  },
  {
    id: 10,
    name: "mtr",
    cuisine: "south indian",
    address: { building: "707", street: "lalbagh road", area: "mavalli", pincode: "560004", city: "bangalore" },
    nearby_landmarks: ["lalbagh"],
    online_delivery: "yes",
    famous_for: "dosa"
  }
]);
```

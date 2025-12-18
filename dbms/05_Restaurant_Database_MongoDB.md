# 🍝 Program 5: Restaurant Database (MongoDB)

**the vibe:** food tech. filtering by cuisine and location.

## 📋 Schema
- `name`, `id`, `cuisine`
- `address`: (`building`, `street`, `area`, `pincode`)
- `nearby landmarks`
- `online delivery` (yes/no)
- `famous for` (name of the dish)

---

## 🔍 Commands

### 1. List the names and addresses of all restaurants in Bangalore with Italian cuisine.
```javascript
db.restaurant.find(
  { "address.city": "bangalore", cuisine: "italian" },
  { name: 1, address: 1, _id: 0 }
)
```
*note: `_id: 0` suppresses the id from the output for a cleaner look.*

### 2. List the name, address and nearby landmarks of all restaurants in Bangalore where North Indian thali(cuisine) is available.
```javascript
db.restaurant.find(
  { "address.city": "bangalore", "famous_for": "north indian thali" },
  { name: 1, address: 1, nearby_landmarks: 1, _id: 0 }
)
```

### 3. List the name and address of restaurants and also the dish the restaurant is famous for, in Bangalore.
```javascript
db.restaurant.find(
  { "address.city": "bangalore" },
  { name: 1, address: 1, famous_for: 1, _id: 0 }
)
```

# 🍝 Program 5: Restaurant Database (MongoDB)

**The Vibe:** Food tech. Filtering by cuisine and location.

## 📋 Schema
- `Name`, `id`, `cuisine`
- `address`: (`building`, `street`, `area`, `pincode`)
- `nearby landmarks`
- `online delivery` (yes/no)
- `famous for` (name of the dish)

---

## 🔍 Commands

### 1. List the names and addresses of all restaurants in Bangalore with Italian cuisine.
```javascript
db.restaurant.find(
  { "address.city": "Bangalore", cuisine: "Italian" },
  { name: 1, address: 1, _id: 0 }
)
```
*Note: `_id: 0` suppresses the ID from the output for a cleaner look.*

### 2. List the name, address and nearby landmarks of all restaurants in Bangalore where North Indian thali(cuisine) is available.
```javascript
db.restaurant.find(
  { "address.city": "Bangalore", "famous_for": "North Indian Thali" },
  { name: 1, address: 1, nearby_landmarks: 1, _id: 0 }
)
```

### 3. List the name and address of restaurants and also the dish the restaurant is famous for, in Bangalore.
```javascript
db.restaurant.find(
  { "address.city": "Bangalore" },
  { name: 1, address: 1, famous_for: 1, _id: 0 }
)
```

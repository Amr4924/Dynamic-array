<div align="center">

<!-- Animated Header -->
<img src="https://readme-typing-svg.demolab.com?font=Fira+Code&weight=700&size=28&duration=3000&pause=1000&color=00D9FF&center=true&vCenter=true&width=600&lines=🚀+Dynamic+Array+Implementation;Built+from+Scratch+in+C%2B%2B;No+STL+Containers+Used!" alt="Typing SVG" />

<br/>

<!-- Animated Badges -->
<img src="https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white" />
<img src="https://img.shields.io/badge/Data_Structures-FF6B6B?style=for-the-badge&logo=databricks&logoColor=white" />
<img src="https://img.shields.io/badge/Memory_Management-4CAF50?style=for-the-badge&logo=buffer&logoColor=white" />
<img src="https://img.shields.io/badge/Templates-9B59B6?style=for-the-badge&logo=cplusplus&logoColor=white" />

<br/><br/>

<!-- Snake Animation -->
<picture>
  <source media="(prefers-color-scheme: dark)" srcset="https://raw.githubusercontent.com/platane/platane/output/github-contribution-grid-snake-dark.svg">
  <source media="(prefers-color-scheme: light)" srcset="https://raw.githubusercontent.com/platane/platane/output/github-contribution-grid-snake.svg">
  <img alt="github contribution grid snake animation" src="https://raw.githubusercontent.com/platane/platane/output/github-contribution-grid-snake.svg">
</picture>

</div>

---

## 📖 About

A **generic, vector-like Dynamic Array** built completely from scratch in C++.  
This project was created to deeply understand how **core data structures** and **memory management** work behind the scenes, without relying on STL containers like `std::vector`.

---

## ⚡ How It Works

```
┌─────────────────────────────────────────────────────────────────┐
│                    🔄 DYNAMIC ARRAY LIFECYCLE                    │
└─────────────────────────────────────────────────────────────────┘

   ┌──────────────────────────────────────────────────────────┐
   │  1️⃣  INITIALIZE                                          │
   │  ┌───┬───┬───┬───┬───┬───┬───┬───┐                       │
   │  │   │   │   │   │   │   │   │   │  Capacity: 8          │
   │  └───┴───┴───┴───┴───┴───┴───┴───┘  Size: 0              │
   └──────────────────────────────────────────────────────────┘
                           ⬇️
   ┌──────────────────────────────────────────────────────────┐
   │  2️⃣  PUSH ELEMENTS                                       │
   │  ┌───┬───┬───┬───┬───┬───┬───┬───┐                       │
   │  │ 5 │ 3 │ 8 │ 1 │   │   │   │   │  Capacity: 8          │
   │  └───┴───┴───┴───┴───┴───┴───┴───┘  Size: 4              │
   └──────────────────────────────────────────────────────────┘
                           ⬇️
   ┌──────────────────────────────────────────────────────────┐
   │  3️⃣  AUTO RESIZE (when full)                             │
   │  ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐│
   │  │ 5 │ 3 │ 8 │ 1 │ 7 │ 2 │ 9 │ 4 │ 6 │   │   │   │   │   ││
   │  └───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┘│
   │  Capacity: 16 (doubled!)    Size: 9                      │
   └──────────────────────────────────────────────────────────┘
```

---

## ✨ Features

<div align="center">

| Feature | Description |
|:-------:|:------------|
| 🔹 | **Dynamic memory allocation** using `new[]` / `delete[]` |
| 🔹 | **Generic design** using Templates (supports `int`, `long long`, `string`, etc.) |
| 🔹 | **Automatic resizing** with capacity growth strategy (×2) |
| 🔹 | **`push()` / `pop()`** operations |
| 🔹 | **Index-based access** via `operator[]` |
| 🔹 | **`Front()` / `Back()`** helpers |
| 🔹 | **`Size()`, `Max_size()`, `empty()`, `clear()`** |
| 🔹 | **Ascending & descending sorting** (`Sort` / `rSort`) |
| 🔹 | **`Search()`** to find elements |
| 🔹 | **`Min()` / `Max()`** to get min/max values |
| 🔹 | **`insert()`** to add element at any position |
| ⛔ | **No STL containers used** |

</div>

---

## 🧩 Usage Example

```cpp
#include "DynamicArray.h"
#include <iostream>

int main() {
    // 🔢 With numbers
    clsDynamicArray<long long> numbers;
    numbers.push(1000000000LL);
    numbers.push(42);
    numbers.push(99);
    
    std::cout << "Front: " << numbers.Front() << std::endl;  // 1000000000
    std::cout << "Back: " << numbers.Back() << std::endl;    // 99
    std::cout << "Size: " << numbers.Size() << std::endl;    // 3
    
    // 📝 With strings
    clsDynamicArray<std::string> names;
    names.push("Alice");
    names.push("Bob");
    names.push("Charlie");
    
    // 🔄 Sort ascending
    numbers.Sort();
    
    // 🔄 Sort descending  
    numbers.rSort();
    
    // � Search for element
    if (numbers.Search(42)) {
        std::cout << "Found 42!" << std::endl;
    }
    
    // 📊 Get Min and Max values
    std::cout << "Min: " << numbers.Min() << std::endl;
    std::cout << "Max: " << numbers.Max() << std::endl;
    
    // 📍 Insert at position
    numbers.insert(1, 500);  // Insert 500 at index 1
    
    // �📍 Access by index
    std::cout << names[0] << std::endl;  // Alice
    
    return 0;
}
```

---

## 🔧 API Reference

```
╔══════════════════════════════════════════════════════════════════╗
║                         📚 CLASS METHODS                          ║
╠══════════════════════════════════════════════════════════════════╣
║  Constructor      │  clsDynamicArray<T>()                        ║
║  Constructor      │  clsDynamicArray<T>(capacity)                ║
║  Destructor       │  ~clsDynamicArray()                          ║
╠══════════════════════════════════════════════════════════════════╣
║  push(T)          │  Add element to end           → void         ║
║  pop()            │  Remove last element          → bool         ║
║  Front()          │  Get first element            → T&           ║
║  Back()           │  Get last element             → T&           ║
║  operator[](i)    │  Access element at index      → T&           ║
╠══════════════════════════════════════════════════════════════════╣
║  Size()           │  Current number of elements   → ll           ║
║  Max_size()       │  Current capacity             → ll           ║
║  empty()          │  Check if empty               → bool         ║
║  clear()          │  Remove all elements          → void         ║
╠══════════════════════════════════════════════════════════════════╣
║  Sort()           │  Sort ascending               → void         ║
║  rSort()          │  Sort descending              → void         ║
║  Search(T)        │  Search for element           → bool         ║
║  Min()            │  Get minimum element          → T            ║
║  Max()            │  Get maximum element          → T            ║
║  insert(i, T)     │  Insert element at index      → void         ║
╚══════════════════════════════════════════════════════════════════╝
```

---

## 🧠 What I Learned

<div align="center">

```
    ╭────────────────────────────────────────────────────────────╮
    │  💡 Understanding core memory management                   │
    │  💡 The real difference between size & capacity            │
    │  💡 Why templates are essential for reusability            │
    │  💡 How resizing strategies affect performance             │
    │  💡 Array vs Stack behavior differences                    │
    │  💡 Why STL containers exist                               │
    ╰────────────────────────────────────────────────────────────╯
```

</div>

---

## 🛠️ Tech Stack

<div align="center">

<img src="https://skillicons.dev/icons?i=cpp,visualstudio,git" />

</div>

| Technology | Purpose |
|:----------:|:--------|
| **C++** | Core implementation language |
| **Templates** | Generic programming |
| **Manual Memory** | `new[]` / `delete[]` management |

---

## 🌱 Roadmap

- [x] ✅ Insert at position
- [x] ✅ Search functionality
- [x] ✅ Min/Max element retrieval
- [ ] 🚧 Bounds checking & safer access
- [ ] 🚧 Copy constructor & assignment operator (Rule of 3 / 5)
- [ ] 🚧 Move semantics
- [ ] 🚧 Iterators support
- [ ] 🚧 Stack & Queue implementations
- [ ] 🚧 Shrink-to-fit functionality
- [ ] 🚧 Remove at position

---

## 📁 Project Structure

```
📦 Dynamic Array
 ┣ 📜 DynamicArray.h           # Main template class
 ┣ 📜 ConsoleApplication22.cpp # Test/Demo file
 ┗ 📜 README.md                # Documentation
```

---

<div align="center">

## 💭 Philosophy

<img src="https://readme-typing-svg.demolab.com?font=Fira+Code&weight=500&size=16&duration=4000&pause=1000&color=FFD700&center=true&vCenter=true&width=700&lines=Building+core+data+structures+manually+isn't+about+replacing+the+STL;It's+about+understanding+the+fundamentals+that+everything+else+is+built+on" alt="Philosophy" />

---

### ⭐ Star this repo if you found it helpful!

<img src="https://readme-typing-svg.demolab.com?font=Fira+Code&weight=600&size=20&duration=2000&pause=500&color=00FF00&center=true&vCenter=true&width=500&lines=🚀+More+implementations+coming+soon...;📚+Stay+tuned+for+updates!" alt="Coming Soon" />

---

## 🤝 Connect with Me

<a href="https://www.linkedin.com/in/sa3dwy/">
  <img src="https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white" alt="LinkedIn" />
</a>

---

<img src="https://capsule-render.vercel.app/api?type=waving&color=gradient&customColorList=6,11,20&height=100&section=footer" width="100%" />

</div>

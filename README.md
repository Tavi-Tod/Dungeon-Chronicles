# ⚜️ Dungeon Chronicles - C++ WebAssembly RPG

![C++](https://img.shields.io/badge/Language-C++17-blue?style=for-the-badge&logo=c%2B%2B)
![WebAssembly](https://img.shields.io/badge/Tech-WebAssembly-purple?style=for-the-badge&logo=webassembly)
![Frontend](https://img.shields.io/badge/Frontend-HTML5%20%2F%20CSS3%20%2F%20JS-orange?style=for-the-badge&logo=html5)

**Dungeon Chronicles** is a turn-based RPG running natively in the browser. The core game logic is written entirely in **C++** and compiled to **WebAssembly** (Wasm) using Emscripten. This project demonstrates how to bridge the gap between high-performance system programming and modern web interfaces.

🎮 **[Play Live Demo](https://dungeon-chronicles.netlify.app/)**

## 🌟 Key Features

* **C++ Powered Logic:** Combat calculations, enemy AI, RNG, and state management are handled by the C++ backend.
* **3 Playable Classes:**
    * 🛡️ **Knight:** High health tank, physical damage.
    * 🏹 **Archer:** Balanced stats, high critical hit chance.
    * 🔥 **Mage:** Glass cannon, massive magic damage, low health.
* **Progression System:**
    * 10 Unique enemies with increasing difficulty.
    * Final Boss Fight (The Dragon).
    * Leveling system, Gold economy, and Item Shop (Potions).
* **Modern UI/UX:**
    * Responsive design (Mobile & Desktop friendly).
    * Pixel art graphics with CSS animations.
    * Real-time combat log.

## 🛠️ Tech Stack

* **Core Logic:** C++ (OOP, STL, Inheritance, Polymorphism).
* **Compiler:** Emscripten SDK (emsdk) -> Compiles C++ to `.wasm`.
* **Frontend:** HTML5, CSS3 (Flexbox, Media Queries), JavaScript (Glue code).
* **Assets:** FontAwesome Icons, Google Fonts.

## 💻 Architecture: How it works

This project uses a hybrid architecture:

1.  **Frontend (JS):** Captures user input (e.g., clicking the "Attack" button).
2.  **Bridge:** JavaScript calls the exposed functions from the **WebAssembly module**.
3.  **Backend (C++):** The engine processes the turn, calculates damage/healing, updates the entity states, and returns the result.
4.  **Update:** JavaScript receives the new state and updates the DOM (Health bars, Logs, Animations).

## 🚀 How to Run Locally

Since browsers restrict loading `.wasm` files from the local file system (`file://`) due to CORS policies, you need a local server.

1.  **Clone the repository:**
    ```bash
    git clone [https://github.com/Tavi-Tod/Dungeon-Chronicles.git](https://github.com/Tavi-Tod/Dungeon-Chronicles.git)
    cd dungeon-chronicles
    ```

2.  **Start a local server (using Python):**
    ```bash
    python3 -m http.server
    ```

3.  Open your browser and navigate to `http://localhost:8000/index.html`.

## ⚙️ Compilation (For Developers)

If you modify the `.cpp` source files, you need to recompile the project using Emscripten:

```bash
emcc main.cpp Entitate.cpp Jucator.cpp Inamic.cpp GameEngine.cpp \
-o joc.html \
-s WASM=1 \
--bind \
-s ALLOW_MEMORY_GROWTH=1

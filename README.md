

# 🌐 Browser History Manager (C++ Double Stack Implementation)

This C++ console application simulates the navigation history feature found in modern web browsers, utilizing a **Double Stack** data structure to manage `Back` and `Forward` functionality.

The project demonstrates core concepts of Object-Oriented Programming (OOP) and fixed-size stack management in C++.

## ✨ Features

  * **Page Navigation:** Allows the user to "visit" new URLs.
  * **Back Functionality:** Navigates to the previously visited page, pushing the current page onto the `forwardStack`.
  * **Forward Functionality:** Navigates to a page previously visited and then moved back from, popping from the `forwardStack`.
  * **Forward History Clearing:** Visiting a new page automatically clears the `forwardStack`, mirroring real browser behavior.
  * **Fixed History Size:** Uses fixed-size arrays (`MAX_HISTORY = 100`) to manage the history stacks.
  * **Full History Display:** Shows the entire sequence of pages in the back history and available forward pages.
  * **History Clear:** Resets the history and returns the user to the starting page (`home`).

## ⚙️ How the History Works (Double Stack)

The `BrowserHistory` class manages navigation using three main components:

1.  **`backStack`:** Stores URLs visited *before* the current page.
2.  **`forwardStack`:** Stores URLs that were in the back history but were moved *back* from.
3.  **`current`:** The URL the user is currently viewing.

| Action | `current` | `backStack` | `forwardStack` |
| :--- | :--- | :--- | :--- |
| **Visit** | New URL | `current` is pushed onto `backStack` | Cleared (`forwardTop = -1`) |
| **Go Back** | Pops from `backStack` | Decreases `backTop` | `current` is pushed onto `forwardStack` |
| **Go Forward** | Pops from `forwardStack` | `current` is pushed onto `backStack` | Decreases `forwardTop` |

## 🛠️ Requirements

The program requires a standard C++ compiler (like g++ or Clang) that supports C++ standards.

## 🚀 How to Compile and Run

1.  **Save the Code:** Save the provided C++ code into a file named `browser_history.cpp`.

2.  **Compile:** Open your terminal or command prompt and compile the code:

    ```bash
    g++ browser_history.cpp -o browser_app
    ```

3.  **Run:** Execute the compiled program:

    ```bash
    ./browser_app
    ```

## 🖥️ Menu and Usage

The application presents a simple console menu for interaction:

```
--- Browser History Manager ---
1. Visit New Page
2. Go Back
3. Go Forward
4. Show Current Page
5. Show Full History
6. Clear History
7. Exit
Enter choice: 
```

### Example Workflow

1.  **Start:** `Current page: home`
2.  **Visit `google.com` (Choice 1):** `Visited: google.com`
3.  **Visit `youtube.com` (Choice 1):** `Visited: youtube.com`
4.  **Go Back (Choice 2):** `Went back to: google.com`
5.  **Go Forward (Choice 3):** `Went forward to: youtube.com`
6.  **Go Back (Choice 2):** `Went back to: google.com`
7.  **Visit `github.com` (Choice 1):** `Visited: github.com` (The forward history is now cleared)
8.  **Show History (Choice 5):**
    ```
    --- Full History ---
    home -> google.com -> github.com
    ```
    (No forward pages are shown.)

#include <iostream>
#include <string>
using namespace std;

const int MAX_HISTORY = 100;

class BrowserHistory {
private:
    string backStack[MAX_HISTORY];
    string forwardStack[MAX_HISTORY];
    int backTop;
    int forwardTop;
    string current;

public:
    BrowserHistory() {
        backTop = -1;
        forwardTop = -1;
        current = "home"; // Start at home page
    }

    void visitPage(const string& url) {
        if (backTop >= MAX_HISTORY - 1) {
            cout << "Back history full. Cannot visit new page.\n";
            return;
        }
        backStack[++backTop] = current;
        current = url;
        forwardTop = -1; // Clear forward history
        cout << "Visited: " << current << endl;
    }

    void goBack() {
        if (backTop == -1) {
            cout << "No previous page to go back to.\n";
            return;
        }
        if (forwardTop < MAX_HISTORY - 1)
            forwardStack[++forwardTop] = current;
        current = backStack[backTop--];
        cout << "Went back to: " << current << endl;
    }

    void goForward() {
        if (forwardTop == -1) {
            cout << "No forward page to go to.\n";
            return;
        }
        if (backTop < MAX_HISTORY - 1)
            backStack[++backTop] = current;
        current = forwardStack[forwardTop--];
        cout << "Went forward to: " << current << endl;
    }

    void currentPage() const {
        cout << "Current page: " << current << endl;
    }

    void showHistory() const {
        cout << "\n--- Full History ---\n";
        for (int i = 0; i <= backTop; ++i) {
            cout << backStack[i] << " -> ";
        }
        cout << current << endl;

        if (forwardTop != -1) {
            cout << "--- Forward Pages ---\n";
            for (int i = forwardTop; i >= 0; --i) {
                cout << forwardStack[i] << (i == 0 ? "\n" : " -> ");
            }
        }
    }

    void clearHistory() {
        backTop = -1;
        forwardTop = -1;
        current = "home";
        cout << "All history cleared. Back to home page.\n";
    }
};

int main() {
    BrowserHistory bh;
    int choice;
    string url;

    do {
        cout << "\n--- Browser History Manager ---\n";
        cout << "1. Visit New Page\n";
        cout << "2. Go Back\n";
        cout << "3. Go Forward\n";
        cout << "4. Show Current Page\n";
        cout << "5. Show Full History\n";
        cout << "6. Clear History\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter URL: ";
                cin >> url;
                bh.visitPage(url);
                break;
            case 2:
                bh.goBack();
                break;
            case 3:
                bh.goForward();
                break;
            case 4:
                bh.currentPage();
                break;
            case 5:
                bh.showHistory();
                break;
            case 6:
                bh.clearHistory();
                break;
            case 7:
                cout << "Exiting Browser History Manager.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 7);

    return 0;
}
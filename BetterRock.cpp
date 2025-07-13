#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main() {
    char user1, user2;
    int return1;
    int user1score = 0, user2score = 0, draw = 0;

    srand(time(0));

    cout << "----------------- ROCK PAPER SIZER GAME -----------------\n";
    cout << "Choose one at a time: (rock -> r, paper -> p, sizer -> s)\n\n";

    do {
        // Get valid user input
        cout << "User1: ";
        cin >> user1;
        if (user1 != 'r' && user1 != 'p' && user1 != 's') {
            cout << "❌ Invalid input. Please enter only 'r', 'p', or 's'.\n\n";
            continue;
        }
 
        // AI random choice
        int ai = rand() % 3;
        if (ai == 0) user2 = 'r';
        else if (ai == 1) user2 = 's';
        else user2 = 'p';

        // Show AI choice
        cout << "Computer: ";
        if (user2 == 'r') cout << "Rock\n";
        else if (user2 == 'p') cout << "Paper\n";
        else cout << "Sizer\n";

        // Determine result
        if (user1 == user2) {
            cout << "\n🤝 Match Draw!\n";
            draw++;
        } else if ((user1 == 'p' && user2 == 'r') ||
                   (user1 == 'r' && user2 == 's') ||
                   (user1 == 's' && user2 == 'p')) {
            cout << "\n🎉 Winner => YOU (User1)!\n";
            user1score++;
        } else {
            cout << "\n💻 Winner => COMPUTER!\n";
            user2score++;
        }

        // Show scores
        cout << "\n🏁 Scoreboard:\n";
        cout << "User1: " << user1score << "\n";
        cout << "Computer: " << user2score << "\n";
        cout << "Draws: " << draw << "\n";

        // Ask to restart
        cout << "\n🔁 Press 9 to play again, or any other key to exit: ";
        cin >> return1;
        cout << "\n----------------------------------------\n";

    } while (return1 == 9);

    // Final result
    cout << "\n===== 🎮 Final Results =====\n";
    cout << "Your Score: " << user1score << "\n";
    cout << "Computer Score: " << user2score << "\n";
    cout << "Draws: " << draw << "\n";

    if (user1score > user2score)
        cout << "🏆 You are the overall winner!\n";
    else if (user2score > user1score)
        cout << "😔 Computer wins overall. Try again!\n";
    else
        cout << "🤝 It's a tie overall!\n";

    cout << "\nThanks for playing!\n";
    return 0;
}
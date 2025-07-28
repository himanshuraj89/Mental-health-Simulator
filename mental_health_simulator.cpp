#include <bits/stdc++.h>

using namespace std;

class user {
    string name;
    vector<string> moodHistory;
public:
    user(string name) {
        this->name = name;
    }

    string getName() {
        return this->name;
    }

    void showMoodHistory() {
        for (int i = 0; i < moodHistory.size(); i++) {
            cout << moodHistory[i] << ",";
        }
        cout << endl;
    }

    void addMoodHistory(string mood) {
        moodHistory.push_back(mood);
    }
};

class QuoteProvider {
    vector<string> quotes = {
        "You are stronger than you think.",
        "This too shall pass.",
        "Take it one step at a time.",
        "Breathe, You're doing okay.",
        "It's okay to ask for help.",
        "You matter, Your feelings are valid.",
        "Progress, not perfection."
    };
public:
    string getRandomQuotes() {
        return quotes[rand() % quotes.size()];
    }
};

class CalmActivity {
public:
    void breathingExercise() {
        for (int i = 0; i < 3; i++) {
            cout << "Breath in..." << endl;
            std::this_thread::sleep_for(std::chrono::seconds(3));
            cout << "Hold..." << endl;
            std::this_thread::sleep_for(std::chrono::seconds(2));
            cout << "Breath out..." << endl;
            std::this_thread::sleep_for(std::chrono::seconds(3));
        }
    }
};

class MoodTracker {
public:
    string askMood(user* user) {
        cout << "Hi " << user->getName() << "," << " How are you feeling today" << endl;
        cout << "Options: Happy, Sad, Anxious, Angry, Tired, Excited, Okay" << endl;
        string ans;
        cin >> ans;
        return ans;
    }
};

class Assistant {
    user* obj = NULL;
    MoodTracker mt;
    QuoteProvider qp;
    CalmActivity ca;

public:
    Assistant(string name) {
        obj = new user(name);
    }

    void startSession() {
        string mood = mt.askMood(obj);
        obj->addMoodHistory(mood);

        cout << "Quote: " << qp.getRandomQuotes() << endl;

        cout << "Would you like to do some breathing exercise(y/n)..." << endl;
        char ch;
        cin >> ch;
        if (ch == 'y') {
            ca.breathingExercise();
        } else {
            cout << "Thank you for starting the sessions..." << endl;
        }
    }

    void showMoodHistory() {
        obj->showMoodHistory();
    }
};

int main() {
    srand(time(0));
    cout << "Hi, Welcome for Mental Health checkin.." << endl;
    cout << "What is your name?" << endl;
    string name;
    cin >> name;
    Assistant as(name);

    while (1) {
        cout << "*** Mental Health Checkin Menu ***" << endl;
        cout << "1. Start Session" << endl;
        cout << "2. Show mood History" << endl;
        cout << "3. Exit" << endl;

        int ch;
        cin >> ch;

        switch (ch) {
        case 1:
            as.startSession();
            break;
        case 2:
            as.showMoodHistory();
            break;
        case 3:
            return 0;
        default:
            cout << "Enter a valid choice..." << endl;
            break;
        }
    }

    return 0;
}

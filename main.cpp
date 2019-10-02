#include <iostream>
#include <vector>
using namespace std;

struct Player {
  /*your code here*/
  string playerName;
    int playerJersey;
    int playerRating;

};

void initialize(vector<Player> &players) {
    unsigned int i;
    string playerNameIn;
    int playerJerseyIn;
    int playerRatingIn;
    char menuOp;
    for (i = 0; i < players.size(); ++i) {

        cout << "Enter player " << i + 1 << "'s name:" << endl;
        cin >> playerNameIn;
        players[i].playerName = playerNameIn;

        cout << "Enter player " << i + 1 << "'s jersey number:" << endl;
        cin >> playerJerseyIn;
        players[i].playerJersey = playerJerseyIn;

        cout << "Enter player " << i + 1 << "'s rating:" << endl;
        cin >> playerRatingIn;
        players[i].playerJersey = playerRatingIn;
        cout << endl;
    }

    cout << "ROSTER" << endl;
    for (i = 0; i < players.size(); ++i) {
        cout << "Player " << i + 1 << " -- Name: " << players[i].playerName << " -- Jersey number: "
             << players[i].playerJersey << ", Rating: " << players[i].playerRating << endl;
    }
    cout << endl;

}

void output(const vector<Player> &v) {
    for (int i = 0; i < v.size(); ++i) {
        cout << "Player " << i + 1 << " -- Name: " << v[i].playerName << " -- Jersey number: "
             << v[i].playerJersey << ", Rating: " << v[i].playerRating << endl;
    }
}

void addPlayer(vector<Player> &v, Player player1) {
    string playerNameIn;
    int playerJerseyIn;
    int playerRatingIn;
    cout << "Enter a new player's name:" << endl;
    cin >> playerNameIn;
    player1.playerName = playerNameIn;


    cout << "Enter a new player's jersey number:" << endl;
    cin >> playerJerseyIn;
    player1.playerJersey = playerJerseyIn;

    cout << "Enter the player's rating:" << endl;
    cin >> playerRatingIn;
    player1.playerRating = playerRatingIn;


    v.push_back(player1);

}

void deletePlayer(vector<Player> &v, int playerJersy) {

    //find the player using her/his jersey number
    for (int i = 0; i < v.size(); ++i) {
        if (playerJersy == v[i].playerJersey) {
            playerJersy = i;
        }
    }
    //shift the vectors' elements up to remove the element
    for (int i = 0; i < v.size() - 1; ++i) {
        if (i >= playerJersy) {
            v[i].playerName = v[i + 1].playerName;
            v[i].playerJersey = v[i + 1].playerJersey;
            v[i].playerRating = v[i + 1].playerRating;
        }
    }
    v.pop_back();
    cout << endl;
}

void updateRating(vector<Player> &v, int playerNumber, int rating) {
    for (int i = 0; i < v.size(); ++i) {
        if (v[i].playerJersey == playerNumber) {
            v[i].playerRating = rating;
        }
    }
}

void aboveRating(const vector<Player> &v, int rating) {
    for (int i = 0; i < v.size(); ++i) {
        if (v[i].playerRating > rating) {
            cout << "Player " << i + 1 << " -- Jersey number: "
                 << v[i].playerJersey << ", Rating: "
                 << v[i].playerRating << endl;
        }
    }
}

int main() {
    vector<Player> players(5);

    unsigned int i;
    string playerNameIn;
    int playerJerseyIn;
    int playerRatingIn;
    char menuOp;


    //initialize the roasters
    initialize(players);

    do {
        cout << "MENU" << endl;
        cout << "a - Add player" << endl;
        cout << "d - Remove player" << endl;
        cout << "u - Update player rating" << endl;
        cout << "r - Output players above a rating" << endl;
        cout << "o - Output roster" << endl;
        cout << "q - Quit" << endl << endl;

        cout << "Choose an option:" << endl;
        cin >> menuOp;

        Player player1;
        //Add
        if (menuOp == 'a') {
            addPlayer(players, player1);
        }
            //Delete
        else if (menuOp == 'd') {
            cout << "Enter a jersey number:" << endl;
            int playerJersey;
            cin >> playerJersey;
            deletePlayer(players, playerJersey);
        }

            //Update
        else if (menuOp == 'u') {
            cout << "Enter a jersey number:" << endl;
            cin >> playerJerseyIn;

            cout << "Enter a new rating for player:" << endl;
            cin >> playerRatingIn;

            updateRating(players, playerJerseyIn, playerRatingIn);
            cout << endl;
        }

            // > Rating
        else if (menuOp == 'r') {
            cout << "Enter a rating:" << endl;
            cin >> playerRatingIn;
            cout << endl;

            cout << "ABOVE " << playerRatingIn << endl;
            aboveRating(players, playerRatingIn);
            cout << endl;

        }

        //output
        else if (menuOp == 'o') {
            cout << "ROSTER" << endl;
            output(players);
            cout << endl;
        }

    } while(menuOp != 'q');

    return 0;
}

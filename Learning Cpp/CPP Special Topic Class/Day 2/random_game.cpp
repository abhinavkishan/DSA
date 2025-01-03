#include <bits/stdc++.h>
using namespace std;

class User {
    string name;
    int lb;
    int ub;
    vector<int> inputs;
    public:
    User(int lb, int ub, string name):lb(lb), ub(ub), name(name){}
    int get_lb(){return lb;}
    int get_ub(){return ub;}
    string get_name() { return name;}
    void update_input(int g) { inputs.push_back(g); }
    bool check_guesses(int g) {
        for(auto i: inputs) {
            if(i == g) {
                cout << "Warning repeated guess!" << endl;
                return false;
            }
        }
        return true;
    }
    int num_guesses(){ return inputs.size(); }
    void all_guesses(){ 
        for(auto i: inputs) {
            cout << i << " ";
        }
        cout << endl;
    }
};

namespace game_func {
    int rand_num(int lb, int ub) {
        // srand(time(0));
        return (rand() % (ub - lb + 1)) + lb;
    }
    int result(int g, User &u) {
        if(u.check_guesses(g)) {
            u.update_input(g);
        }
        int lb = u.get_lb();
        int ub = u.get_ub();
        int gen_num = game_func::rand_num(lb, ub);
        cout << "Generated number was: " << gen_num << endl;
        if(g > gen_num) {
            cout << "The guess is higher than generated number!" << endl;
            return 1;
        }
        if(g < gen_num) {
            cout << "The guess id lower than generated number!" << endl;
            return -1;
        }
        cout << R"(
             ___________
            '._==_==_=_.'
            .-\:      /-.
           | (|:.     |) |
            '-|:.     |-'
              \::.    /
               '::. .'
                 ) (
               _.' '._
              `"""""""`
        )"<< '\n';
        cout << "You have Won the Game!" << endl;
        cout << "Username: " << u.get_name() << endl;
        cout << "Number of guesses " << u.num_guesses() << endl;
        cout << "All the guesses: " << endl;
        u.all_guesses();
        return 0;
    }
}

int main()
{
    cout << "Welcome to The Random Game!" << '\n';
    int res = -2;
    int user_guess = 0;
    int ub = 0,  lb = 0;
    string name;
    cout << "Please enter your name: " << endl;
    cin >> name;
    cout << "Decide Upper bound: " << endl;
    cin >> ub;
    cout << "Decide Lower Bound: " << endl;
    cin >> lb;
    while (ub <= lb) {
        cout << "Invalid bounds Please enter the bounds again!" << endl;
        cout << "Decide Upper bound: " << endl;
        cin >> ub;
        cout << "Decide Lower Bound: " << endl;
        cin >> lb;
    }
    cout << "Let's start the game!" << endl;

    User u(lb, ub, name);
    int gen_num;

    while(res != 0) {
        cout << "Please enter your guess: " << endl;
        cin >> user_guess;
        if(user_guess)
        gen_num = game_func::rand_num(u.get_lb(), u.get_lb());
        res = game_func::result(user_guess, u);
    }

    return 0;
}
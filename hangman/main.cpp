#include <iostream>
#include <time.h>
#include <string>
#include <vector>
#include <ctype.h>
using namespace std;
char colour[4][10] = { "blue", "red", "orange", "yellow" };
int colour_length = sizeof(colour)/sizeof(colour[0]);
int main(int argc, const char * argv[]) {
    srand(time(0));
    int lives = 9;
    cout<< "Welcome to Hangman!"<<endl;
    cout << "_________" << endl
    << " |     | " << endl
    << " | " << endl
    << " | " << endl
    << " | " << endl
    << " | " << endl
    << "``````````" << endl;
    cout<< "If you would like to quit, type 'quit'"<<endl;
    vector<string> guessed_letters;
    vector<string> correct_letters;
    int r = rand() % 4;
    string w = colour[r];
    int word_length = 0;
    string guess;
    bool play = true;
    while (play)
    {
        if( lives == 0)
        {
            srand(time(0));
            cout<< "You lost the game!"<<endl;
            cout<<"\n";
            cout<< "the right word is " << w <<endl;
            cout<<"\n";
            cout<< "Would you like to play again?"<<endl;
            cout<< "'y' for yes, any other key for no."<<endl;
            cout<<"\n";
            string reset;
            cin>> reset;
            transform(reset.begin(), reset.end(), reset.begin(), ::tolower);
            if (reset.compare("y") == 0)
            {
                guessed_letters.clear();
                correct_letters.clear();
                r = rand() % colour_length;
                w = colour[r];
                lives = 9;
                word_length = 0;
            }
            else
            {
                break;
            }
        }
        if (word_length == w.length())
        {
            cout<< "You Won the Game!"<<endl;
            cout<<"\n";
            cout<< "The Word is "<< w<<endl;
            cout<< "Would you like to play again?"<<endl;
            cout<< "'y' for yes, any other key for no."<<endl;
            cout<<"\n";
            string reset;
            cin>> reset;
            transform(reset.begin(), reset.end(), reset.begin(), ::tolower);
            if (reset.compare("y") == 0)
            {
                guessed_letters.clear();
                correct_letters.clear();
                r = rand() % colour_length;
                w = colour[r];
                lives = 9;
                word_length = 0;
            }
            else
            {
                break;
            }
        }
        word_length = 0;
        bool already_guessed = false;
        cout<< "Guess a letter:"<< endl;
        cout<<"\n";
        cin >> guess;
        for (string c: guessed_letters)
        {
            if (c == guess)
            {
                already_guessed = true;
            }
        }
        if (already_guessed == true)
        {
            cout<< "guess a different letter!"<< endl;
            cout<<"\n";
        }
        else if (isalpha(guess[0]) == false)
        {
            cout<< "Only letters allowed!"<< endl;
            cout<<"\n";
        }
        else if (guess.length() > 1)
        {
            cout<< "Only letters allowed!"<< endl;
            cout<<"\n";
        }
        else
        {
            transform(guess.begin(), guess.end(), guess.begin(), ::tolower);
            guessed_letters.push_back(guess);
            size_t found = w.find(guess);
            if (found != w.npos)
            {
                correct_letters.push_back(guess);
                cout<< "The letter is in the word!"<<endl;
                cout<<"\n";
                for(int i = 0; i < w.size(); i++)
                {
                    int yes = 0;
                    for (string c: correct_letters)
                    {
                        size_t letter_pos = i;
                        letter_pos = w.find(c, i);
                        if (i  == letter_pos)
                        {
                            cout<< c;
                            word_length += 1;
                            yes = 1;
                        }
                    }
                    if (yes == 0)
                    {
                        cout<< "_";
                    }
                }
                cout<<"\n";
            }
            else
            {
                cout<< "The letter is not in the word!"<<endl;
                cout<<"\n";
                lives -= 1;
                cout<< "you now have " << lives << " lives"<< endl;
                cout<<"\n";
                if ( lives == 8)
                {
                    cout << "_________" << endl
                    << " |     | " << endl
                    << " |   (   )" << endl
                    << " | " << endl
                    << " | " << endl
                    << " | " << endl
                    << "``````````" << endl;
                }
                if (lives == 7)
                {
                    cout << "_________" << endl
                    << " |     | " << endl
                    << " |   (o_o)" << endl
                    << " |     " << endl
                    << " |     " << endl
                    << " | " << endl
                    << "``````````" << endl;
                }
                
                if (lives == 6)
                {
                    cout << "_________" << endl
                    << " |     | " << endl
                    << " |   (o_o)" << endl
                    << " |     | " << endl
                    << " |     |" << endl
                    << " | " << endl
                    << "``````````" << endl;
                }
                if (lives == 5)
                {
                    cout << "_________" << endl
                    << " |     | " << endl
                    << " |   (o_o)" << endl
                    << " |    _| " << endl
                    << " |     |" << endl
                    << " | " << endl
                    << "``````````" << endl;
                }
                if (lives == 4)
                {
                    cout << "_________" << endl
                    << " |     | " << endl
                    << " |   (o_o)" << endl
                    << " |    _|_ " << endl
                    << " |     |" << endl
                    << " |     " << endl
                    << "``````````" << endl;
                }
                if (lives == 3)
                {
                    cout << "_________" << endl
                    << " |     | " << endl
                    << " |   (o_o)" << endl
                    << " |    _|_ " << endl
                    << " |     |" << endl
                    << " |    / " << endl
                    << "``````````" << endl;
                }
                if (lives == 2)
                {
                    cout << "_________" << endl
                    << " |     | " << endl
                    << " |   (O_O)" << endl
                    << " |    \\|/ " << endl
                    << " |     |" << endl
                    << " |    / \\" << endl
                    << "``````````" << endl;
                }
                if (lives == 1)
                {
                    cout << "_________" << endl
                    << " |     | " << endl
                    << " |   (x_x)" << endl
                    << " |     | " << endl
                    << " |    /|\\" << endl
                    << " |    / \\" << endl
                    << " ````\\" << endl
                    << "      \\" << endl;
                }
                if (lives == 0)
                {
                    cout << endl
                    << "    (^_^)" << endl
                    << "     \\|/ " << endl
                    << "      |" << endl
                    << "     / \\" << endl;
                }
            }
        }
    }
}

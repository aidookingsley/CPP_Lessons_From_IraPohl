#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class PokerHand
{
    vector<int> card_values;

public:
    PokerHand(vector<string> cards)
    {
        for (string card : cards)
        {
            char value = card[0];
            switch (value)
            {
            case 'A':
                card_values.push_back(14);
                break;
            case 'K':
                card_values.push_back(13);
                break;
            case 'Q':
                card_values.push_back(12);
                break;
            case 'J':
                card_values.push_back(11);
                break;
            case 'T':
                card_values.push_back(10);
                break;
            default:
                card_values.push_back(value - '0');
                break;
            }
        }
        sort(card_values.begin(), card_values.end());
    }

    bool is_straight()
    {
        int count = 1;
        for (int i = 0; i < card_values.size() - 1; ++i)
        {
            if (card_values[i] == card_values[i + 1])
            {
                continue; // Skip over pairs, trips, etc
            }
            if (card_values[i] == card_values[i + 1] - 1)
            {
                count++;
            }
            else
            {
                count = 1; // Reset count if there's a gap between cards
            }
            if (count == 5)
            {
                return true;
            }
        }
        if (card_values == vector<int>{2, 3, 4, 5, 14})
        {
            return true;
        }
        return false;
    }
    // Special cases for A-5 straight
};

int main()
{
    vector<string> cards1{"2H", "3C", "4D", "5S", "6H"};
    PokerHand hand1(cards1);
    cout << boolalpha << hand1.is_straight() << endl;

    vector<string> cards2{"AH", "JC", "KD", "QS", "TC"};
    PokerHand hand2(cards2);
    cout << boolalpha << hand2.is_straight() << endl;

    vector<string> cards3{"2H", "3H", "4H", "5H", "7H"};
    PokerHand hand3(cards3);
    cout << boolalpha << hand3.is_straight() << endl;

    vector<string> cards4{"2H", "3C", "4D", "5S", "7H"};
    PokerHand hand4(cards4);
    cout << boolalpha << hand4.is_straight() << endl;

    return 0;
}
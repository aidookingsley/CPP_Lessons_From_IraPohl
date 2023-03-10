#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <random>
#include <chrono>
using namespace std;

enum class suit : short
{
    SPADE,
    HEART,
    DIAMOND,
    CLUB
};
class pips
{
public:
    pips(int val) : v(val) { assert(v > 0 && v < 14); }
    friend ostream &operator<<(ostream &out, const pips &p);
    int get_pips() { return v; }

private:
    int v;
};

class card
{
public:
    card() : s(suit::SPADE), v(1) {}
    card(suit s, pips v) : s(s), v(v) {}
    friend ostream &operator<<(ostream &out, const card &c);
    suit get_suit() { return s; }
    pips get_pips() { return v; }

private:
    suit s;
    pips v;
};

ostream &operator<<(ostream &out, const suit &s)
{
    switch (s)
    {
    case suit::CLUB:
        out << "C";
        break;
    case suit::DIAMOND:
        out << "D";
        break;
    case suit::HEART:
        out << "H";
        break;
    case suit::SPADE:
        out << "S";
        break;
    default:
        out << "Invalid Suit";
        break;
    }
    return out;
}

ostream &operator<<(ostream &out, const card &c)
{
    cout << c.v << c.s; // presumes << overloaded for pips and suit
    return out;
}
ostream &operator<<(ostream &os, const pips &p)
{
    os << p.v;
    return os;
}
void init_deck(vector<card> &d)
{
    for (int i = 1; i < 14; ++i)
    {
        card c(suit::SPADE, i);
        d[i - 1] = c;
    }
    for (int i = 1; i < 14; ++i)
    {
        card c(suit::HEART, i);
        d[i + 12] = c;
    }
    for (int i = 1; i < 14; ++i)
    {
        card c(suit::DIAMOND, i);
        d[i + 25] = c;
    }
    for (int i = 1; i < 14; ++i)
    {
        card c(suit::CLUB, i);
        d[i + 38] = c;
    }
}

void print(vector<card> &deck)
{
    for (auto cardval : deck)
        cout << cardval;
    cout << endl;
}
bool is_flush(vector<card> &hand)
{
    suit s = hand[0].get_suit();
    for (auto p = hand.begin(); p != hand.end(); ++p)
        if (s != p->get_suit())
            return false;
    return true;
}

bool is_straight(vector<card> &hand)
{
    int pips_v[5], i = 0;
    for (auto p = hand.begin(); p != hand.end(); ++p)
        pips_v[i++] = (p->get_pips()).get_pips();
    sort(pips_v, pips_v + 5); // stl iterator range
    if (pips_v[0] != 1)       // non-aces
        return ((pips_v[0] == pips_v[1] - 1 && pips_v[1] == pips_v[2] - 1) && (pips_v[2] == pips_v[3] - 1 && pips_v[3] == pips_v[4] - 1));
    else // aces have a special logic
        return ((pips_v[0] == pips_v[1] - 1 && pips_v[1] == pips_v[2] - 1 && (pips_v[2]) == pips_v[3] - 1 && pips_v[3] == pips_v[4] - 1) || (pips_v[1] == 10) && (pips_v[2] == 11) && (pips_v[3] == 12) && (pips_v[4] == 13));
}
// straight flush
bool is_straight_flush(vector<card> &hand)
{
    return is_flush(hand) && is_straight(hand);
}

int main()
{
    vector<card> deck(52);
    srand(time(0));
    init_deck(deck);
    int how_many;
    int flush_count = 0;
    int str_count = 0;
    int str_flush_count = 0;
    cout << "How Many shuffles? ";
    cin >> how_many;

    for (int loop = 0; loop < how_many; ++loop)
    {
        std::shuffle(deck.begin(), deck.end(), std::mt19937(std::chrono::steady_clock::now().time_since_epoch().count())); // STL algorithm
        vector<card> hand(5);
        int i = 0;
        for (auto p = deck.begin(); i < 5; ++p)
        {
            hand[i++] = *p;
            if (is_flush(hand))
                flush_count++;
            if (is_straight(hand))
                str_count++;
            if (is_straight_flush(hand))
                str_flush_count++;
        }
        cout << "Flushes " << flush_count << " out of " << how_many << endl;
        cout << " Straights " << str_count << " out of " << how_many << endl;
        cout << " Straight Flushes " << str_flush_count << " out of " << how_many << endl;
    }
}
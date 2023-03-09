#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <fstream>
#include <cassert>
// using namespace std;
enum class Suit : short
{
    SPADE,
    HEART,
    DIAMOND,
    CLUB
};

class Pips
{
public:
    Pips(int val) : value(val) { assert(value > 0 && value < 14); }
    friend std::ostream &operator<<(std::ostream &out, const Pips &p);
    int get_pips() const { return value; }
    int get_value() const { return value; }

private:
    int value;
};

class Card
{
public:
    Card() : suit(Suit::SPADE), pips(Pips(1)) {}
    Card(Suit suit, Pips pips) : suit(suit), pips(pips) {}
    friend std::ostream &operator<<(std::ostream &out, const Card &c);
    Suit get_suit() const
    {
        return suit;
    }
    Pips get_pips() const
    {
        return pips;
    }

private:
    Suit suit;
    Pips pips;
};

std::ostream &operator<<(std::ostream &out, const Suit &s)
{
    switch (s)
    {
    case Suit::CLUB:
        out << "C";
        break;
    case Suit::DIAMOND:
        out << "D";
        break;
    case Suit::HEART:
        out << "H";
        break;
    case Suit::SPADE:
        out << "S";
        break;
    default:
        out << "Invalid Suit";
        break;
    }
    return out;
}

std::ostream &operator<<(std::ostream &out, const Card &c)
{
    out << c.get_pips() << c.get_suit(); // presumes<<overloaded for Pips and Suit
    return out;
}

std::ostream &operator<<(std::ostream &os, const Pips &p)
{
    os << p.get_pips();
    return os;
}

void init_deck(std::vector<Card> &deck)
{
    for (int i = 1; i < 14; ++i)
    {
        Card c(Suit::SPADE, Pips(i));
        deck[i - 1] = c;
    }
    for (int i = 1; i < 14; ++i)
    {
        Card c(Suit::HEART, Pips(i));
        deck[i + 12] = c;
    }
    for (int i = 1; i < 14; ++i)
    {
        Card c(Suit::HEART, Pips(i));
        deck[i + 25] = c;
    }
    for (int i = 1; i < 14; ++i)
    {
        Card c(Suit::CLUB, Pips(i));
        deck[i + 38] = c;
    }
}

void print(const std::vector<Card> &deck)
{
    for (const auto &card : deck)
        std::cout << card;
    std::cout << std::endl;
}

bool is_flush(const std::vector<Card> &hand)
{
    Suit s = hand[0].get_suit();
    for (auto it = hand.begin() + 1; it != hand.end(); ++it)
    {
        if (s != it->get_suit())
            return false;
    }
    return true;
}
bool is_straight(const std::vector<Card> &hand)
{
    int pips_v[5], i = 0;
    for (auto it = hand.begin(); it != hand.end(); ++it)
    {
        pips_v[i++] = it->get_pips().get_value();
    }
    std::sort(pips_v, pips_v + 5);

    if (pips_v[0] == 1 && pips_v[1] == 10 && pips_v[2] == 11 && pips_v[3] == 12 && pips_v[4] == 13)
        return true;
    for (int i = 0; i < 4; ++i)
        if (pips_v[i] != pips_v[i + 1] - 1)
            return false;
    return true;
}

// straight flush
bool is_straight_flush(std::vector<Card> &hand)
{
    return is_flush(hand) && is_straight(hand);
}

int main()
{
    std::vector<Card> deck(52);
    std::srand(std::time(nullptr));
    init_deck(deck);

    int how_many;
    std::cout << "How many shuffles? ";
    std::cin >> how_many;

    std::random_device rd;
    std::mt19937_64 gen(rd());

    int flush_count = 0;
    int str_count = 0;
    int str_flush_count = 0;

    for (int i = 0; i < how_many; ++i)
    {
        std::shuffle(deck.begin(), deck.end(), gen);
        std::vector<Card> hand(deck.begin(), deck.begin() + 5);

        if (is_flush(hand))
            ++flush_count;
        if (is_straight(hand))
            ++str_count;
        if (is_straight_flush(hand))
            ++str_flush_count;
    }

    std::cout << "Flushes " << flush_count << " out of " << how_many << std::endl;
    std::cout << "Straights " << str_count << " out of " << how_many << std::endl;
    std::cout << "Straight flushes " << str_flush_count << " out of " << how_many << std::endl;

    return 0;
}
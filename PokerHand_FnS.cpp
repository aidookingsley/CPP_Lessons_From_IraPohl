#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>

enum class Rank
{
    Two = 2,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
    Ace
};

enum class Suit : short
{
    Hearts,
    Diamonds,
    Clubs,
    Spades
};

class Card
{
public:
    Card(Rank rank, Suit suit) : rank(rank), suit(suit) {}

    Rank rank;
    Suit suit;
};

class PokerHand
{
public:
    PokerHand(std::vector<Card> cards) : cards(cards)
    {
        sort_cards();
        evaluate_hand();
        is_straight();
        is_straight_flush();
    }

    std::vector<Card> cards;
    std::vector<Rank> ranks;
    std::vector<Suit> suits;
    bool is_flush;

    void sort_cards()
    {
        std::sort(cards.begin(), cards.end(), [](Card a, Card b)
                  { return a.rank < b.rank; });
    }

    void evaluate_hand()
    {
        // Extract ranks and suits from the cards
        for (auto card : cards)
        {
            ranks.push_back(card.rank);
            suits.push_back(card.suit);
        }

        // Check for flush
        is_flush = std::adjacent_find(suits.begin(), suits.end(), std::not_equal_to<>()) == suits.end();
    }

    inline bool is_straight()
    {
        if (ranks.size() < 5)
        {
            return false;
        }
        for (size_t i = 0; i < ranks.size() - 1; i++)
        {
            if (static_cast<int>(ranks[i + 1]) - static_cast<int>(ranks[i]) != 1)
            {
                return false;
            }
        }
        return true;
    }

    inline bool is_straight_flush()
    {
        return is_straight() && is_flush;
    }
};

int main()
{
    std::vector<Card> cards = {
        Card(Rank::Two, Suit::Hearts),
        Card(Rank::Three, Suit::Hearts),
        Card(Rank::Four, Suit::Hearts),
        Card(Rank::Five, Suit::Hearts),
        Card(Rank::Six, Suit::Hearts)};

    std::vector<Card> cards2 = {
        Card(Rank::Ace, Suit::Spades),
        Card(Rank::King, Suit::Spades),
        Card(Rank::Queen, Suit::Spades),
        Card(Rank::Jack, Suit::Spades),
        Card(Rank::Ten, Suit::Spades)};

    std::vector<Card> cards3 = {
        Card(Rank::Ten, Suit::Spades),
        Card(Rank::King, Suit::Spades),
        Card(Rank::Queen, Suit::Spades),
        Card(Rank::Jack, Suit::Spades),
        Card(Rank::Ace, Suit::Hearts)};

    std::vector<Card> cards4 = {
        Card(Rank::Seven, Suit::Clubs),
        Card(Rank::Eight, Suit::Clubs),
        Card(Rank::Nine, Suit::Clubs),
        Card(Rank::Ten, Suit::Clubs),
        Card(Rank::Queen, Suit::Clubs)};

    PokerHand hand(cards);

    std::cout << "This hand is a " << (hand.is_straight_flush() ? "straight flush" : (hand.is_flush ? "flush" : (hand.is_straight() ? "straight" : "nothing"))) << std::endl;

    PokerHand hand2(cards2);
    std::cout << "This hand is a " << (hand2.is_straight_flush() ? "straight flush" : (hand2.is_flush ? "flush" : (hand2.is_straight() ? "straight" : "nothing"))) << std::endl;

    PokerHand hand3(cards3);
    std::cout << "This hand is a " << (hand3.is_straight_flush() ? "straight flush" : (hand3.is_flush ? "flush" : (hand3.is_straight() ? "straight" : "nothing"))) << std::endl;

    PokerHand hand4(cards4);
    std::cout << "This hand is a " << (hand4.is_straight_flush() ? "straight flush" : (hand4.is_flush ? "flush" : (hand4.is_straight() ? "straight" : "nothing"))) << std::endl;

    return 0;
}

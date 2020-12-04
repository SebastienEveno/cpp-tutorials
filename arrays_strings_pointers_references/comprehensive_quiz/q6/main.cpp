/*
https://www.learncpp.com/cpp-tutorial/6-x-chapter-6-comprehensive-quiz/
Question #6

Let’s pretend we’re writing a card game.
*/

#include <iostream>
#include <array>
#include <algorithm> // std::shuffle
#include <ctime> // for std::time
#include <random> // for std::mt19937

enum class CardRank
{
    Two,
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
    Ace,
    max_rank
};

enum class CardSuit
{
    Clubs,
    Diamonds,
    Hearts,
    Spades,
    max_suit
};

struct Card
{
    CardRank rank{};
    CardSuit suit{};   
};

void printCard(const Card& card)
{
    switch(card.rank)
    {
        case CardRank::Two:
            std::cout << '2';
            break;
        case CardRank::Three:
            std::cout << '3';
            break;
        case CardRank::Four:
            std::cout << '4';
            break;
        case CardRank::Five:
            std::cout << '5';
            break;
        case CardRank::Six:
            std::cout << '6';
            break;
        case CardRank::Seven:
            std::cout << '7';
            break;
        case CardRank::Eight:
            std::cout << '8';
            break;
        case CardRank::Nine:
            std::cout << '9';
            break;
        case CardRank::Ten:
            std::cout << 'T';
            break;
        case CardRank::Jack:
            std::cout << 'J';
            break;
        case CardRank::Queen:
            std::cout << 'Q';
            break;
        case CardRank::King:
            std::cout << 'K';
            break;
        case CardRank::Ace:
            std::cout << 'A';
            break;
        default:
            std::cout << '?';
            break;
    }
    switch(card.suit)
    {
        case CardSuit::Clubs:
            std::cout << 'C';
            break;
        case CardSuit::Diamonds:
            std::cout << 'D';
            break;
        case CardSuit::Hearts:
            std::cout << 'H';
            break;
        case CardSuit::Spades:
            std::cout << 'S';
            break;
        default:
            std::cout << '?';
            break;
    }
}

constexpr int numberOfCards {52};
using deck_type = std::array<Card, numberOfCards>;

deck_type createDeck()
{
    deck_type deck{};
    deck_type::size_type ind {0};

    for(int i{0}; i < static_cast<int>(CardSuit::max_suit); ++i)
    {
        for (int j{0}; j < static_cast<int>(CardRank::max_rank); ++j)
        {
            deck[ind].suit = static_cast<CardSuit>(i);
            deck[ind].rank = static_cast<CardRank>(j);
            ++ind;
        }
    }
    return deck;
}

void printDeck(const deck_type& deck)
{
    for (const auto & card : deck)
    {
        printCard(card);
        std::cout << ' ';
    }
}

void shuffleDeck(deck_type& deck)
{
    // mt is static so it only gets seeded once
    static std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
    std::shuffle(deck.begin(), deck.end(), mt);
}

int getCardValue(const Card& card)
{
    switch (card.rank)
    {
        case CardRank::Two:
            return 2;
        case CardRank::Three:
            return 3;
        case CardRank::Four:
            return 4;
        case CardRank::Five:
            return 5;
        case CardRank::Six:
            return 6;
        case CardRank::Seven:
            return 7;
        case CardRank::Eight:
            return 8;
        case CardRank::Nine:
            return 9;
        case CardRank::Ten:
        case CardRank::Jack:
        case CardRank::Queen:
        case CardRank::King:
            return 10;
        case CardRank::Ace:
            return 11;
        default:
            return 0;
    }
}

int main()
{
    auto deck{ createDeck() };
    shuffleDeck(deck);
    printDeck(deck);
    return 0;
}
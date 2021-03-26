#ifndef DECK_HPP
#define DECK_HPP

#include <algorithm> // for std::shuffle
#include <ctime> // for std::time
#include <random> // for std::mt19937

#include "card.hpp"

constexpr int number_of_cards{ 52 };
using vector_type = std::vector<Card>;
using index_type = vector_type::size_type;

class Deck
{
private:
    vector_type m_deck;
public:
    Deck()
    {
        vector_type deck(static_cast<index_type>(number_of_cards));
        int k{ 0 };
        for(int i{ 0 }; i < static_cast<int>(CardRank::max_ranks); ++i)
        {
            for(int j{ 0 }; j < static_cast<int>(CardSuit::max_suits); ++j)
            {
                deck[k].setRank(static_cast<CardRank>(i));
                deck[k].setSuit(static_cast<CardSuit>(j));
                ++k;
            }
        }
        m_deck = deck;
    }
    void printDeck() const
    {
        for(const auto& card : m_deck)
        {
            card.printCard();
            std::cout << ' ';
        }
        std::cout << '\n';
    }
    void shuffleDeck()
    {
        static std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
        std::shuffle(m_deck.begin(), m_deck.end(), mt);
    }
};

#endif
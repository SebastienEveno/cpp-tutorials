#ifndef DECK_HPP
#define DECK_HPP

#include <algorithm> // for std::shuffle
#include <ctime> // for std::time
#include <random> // for std::mt19937
#include <array>
#include <cassert> // for assert

#include "card.hpp"

class Deck
{
public:
    using array_type = std::array<Card, 52>;
    using index_type = array_type::size_type;

private:
    array_type m_deck{};
    index_type m_nextCardIndex{ 0 };
public:
    Deck()
    {
        index_type k{ 0 };
        for(int i{ 0 }; i < static_cast<int>(Card::CardRank::max_ranks); ++i)
        {
            for(int j{ 0 }; j < static_cast<int>(Card::CardSuit::max_suits); ++j)
            {
                m_deck[k].setRank(static_cast<Card::CardRank>(i));
                m_deck[k].setSuit(static_cast<Card::CardSuit>(j));
                ++k;
            }
        }
    }
    void print() const
    {
        for(const auto& card : m_deck)
        {
            card.print();
            std::cout << ' ';
        }
        std::cout << '\n';
    }
    void shuffle()
    {
        static std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
        std::shuffle(m_deck.begin(), m_deck.end(), mt);
        m_nextCardIndex = 0;
    }
    array_type getCards() const { return m_deck; }
    const Card& getNextCard()
    {
        assert(m_nextCardIndex < m_deck.size());
        return m_deck[m_nextCardIndex++];
    }
    int getNextCardValue() { return getNextCard().getValue(); }
};

#endif
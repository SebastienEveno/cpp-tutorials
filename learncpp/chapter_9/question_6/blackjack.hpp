#ifndef BLACKJACK_HPP
#define BLACKJACK_HPP

#include "deck.hpp"
#include "player.hpp"

class Blackjack
{
private:
    int m_target_score; // If the player goes over a score of 21, they lose immediately.
    int m_minimal_dealer_score; // The dealer repeatedly draws until they reach a score of 17 or more, at which point they stand.
    Deck m_deck;
public:
    Blackjack(int target_score=21, int minimal_dealer_score=17)
        : m_target_score{target_score}, m_minimal_dealer_score{minimal_dealer_score}
    {
        Deck d;
        m_deck = d;
    }
    bool playBlackjack()
    {
        // shuffle deck
        m_deck.shuffleDeck();
        // Dealer gets first card to start
        Dealer dealer{ m_minimal_dealer_score, m_deck.getNextCardValue() };
        dealer.showingScore();
        // Player gets two cards to start
        Player player{ m_deck.getNextCardValue() + m_deck.getNextCardValue() };
        player.showingScore();
        
        if(player.turn(m_deck, m_target_score))
            return false;
        
        if(dealer.turn(m_deck, m_minimal_dealer_score))
            return true;
        
        return player.getScore() > dealer.getScore();
    }
};

#endif
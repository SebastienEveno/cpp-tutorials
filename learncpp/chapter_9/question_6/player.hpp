#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "deck.hpp"

class Player
{
protected:
    int m_score;
    int m_ace_counter; // number of aces in the player's hands
public:
    Player(int score=0, int ace_counter=0) : m_score{score}, m_ace_counter{ace_counter} {}
    
    void setScore(int score) { m_score = score; }
    
    int getScore() const { return m_score; }
    
    virtual void showingScore() const { std::cout << "You have: " << m_score << '\n'; }
    
    Card drawCard(Deck& deck)
    {
        Card card { deck.getNextCard() };
        m_score += card.getValue();
        return card;
    }

    virtual void drawCardAndPrint(Deck& deck)
    {
        std::cout << "You draw a ";
        drawCard(deck).print();
        std::cout << '\n';
        showingScore();
    }

    bool wantsHit() const
    {
        while (true)
        {
            std::cout << "(h) to hit, or (s) to stand: ";
            char ch{};
            std::cin >> ch;
            switch (ch)
            {
            case 'h':
                return true;
            case 's':
                return false;
            }
        }
    }
    
    bool isBust(int target_score) const { return (m_score > target_score); }

    virtual bool turn(Deck& deck, int target_score)
    {
        while(true)
        {
            if(isBust(target_score))
            {
                std::cout << "You score is higher than 21!\n";
                return true;
            }
            else
            {
                if (wantsHit())
                {
                    drawCardAndPrint(deck);
                }
                else
                {
                    // The player did not go bust
                    return false;
                }
            }
        }
    }
};

class Dealer : public Player
{
private:
    int m_minimal_score;
public:
    Dealer(int minimal_score, int score=0, int ace_counter=0)
        : Player(score, ace_counter), m_minimal_score{minimal_score} {}
    
    void showingScore() const { std::cout << "The dealer is showing: " << getScore() << '\n'; }
    
    void drawCardAndPrint(Deck& deck)
    {
        std::cout << "The dealer turned up a ";
        drawCard(deck).print();
        std::cout << '\n';
        showingScore();
    }

    bool turn(Deck& deck, int target_score)
    {
        while(getScore() < m_minimal_score)
        {
            drawCardAndPrint(deck);
        }
        if(isBust(target_score))
        {
            std::cout << "The dealer busted!\n";
            return true;
        }
        return false;
    }
};

#endif
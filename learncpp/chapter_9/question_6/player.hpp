#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "deck.hpp"

enum class PlayerStatus
{
    hit,
    stand,
    none
};

class Player
{
private:
    int m_score;
public:
    Player(int score=0) : m_score{score} {}
    void addToScore(int a) { m_score += a; }
    void setScore(int score) { m_score = score; }
    int getScore() { return m_score; }
    virtual void showingScore() { std::cout << "You have: " << m_score << '\n'; }
    bool wantsHit()
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
    virtual bool turn(const Deck& deck, int target_score)
    {
        while(true)
        {
            if(m_score > target_score)
            {
                std::cout << "You score is higher than 21!\n";
                return true;
            }
            else
            {
                if (wantsHit())
                {
                    Card card{ deck.getNextCard() };
                    m_score += card.getCardValue();
                    std::cout << "You draw a ";
                    card.printCard();
                    std::cout << " and now have " << m_score << '\n';
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
    Dealer(int minimal_score, int score=0)
        : Player(score), m_minimal_score{minimal_score} {}
    void showingScore() { std::cout << "The dealer is showing: " << getScore() << '\n'; }
    bool turn(const Deck& deck, int target_score)
    {
        while(getScore() < m_minimal_score)
        {
            Card card{ deck.getNextCard() };
            addToScore(card.getCardValue());
            std::cout << "The dealer turned up a " << card.getCardValue() << " and now has " << getScore() << '\n';
        }
        if(getScore() > target_score)
        {
            std::cout << "The dealer busted!\n";
            return true;
        }
        return false;
    }
};

#endif
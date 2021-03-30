#ifndef CARD_HPP
#define CARD_HPP

#include <iostream>



class Card
{
public:
    enum class CardRank
    {
        rank_2,
        rank_3,
        rank_4,
        rank_5,
        rank_6,
        rank_7,
        rank_8,
        rank_9,
        rank_10,
        rank_jack,
        rank_queen,
        rank_king,
        rank_ace,

        max_ranks
    };

    enum class CardSuit
    {
        suit_club,
        suit_diamond,
        suit_heart,
        suit_spade,

        max_suits
    };
    // When using a std::array (or std::vector) where the elements are a class type, 
    // your element’s class must have a default constructor so the elements can be 
    // initialized to a reasonable default state. If you do not provide one, you’ll get 
    // a cryptic error about attempting to reference a deleted function.
    Card() = default;

    Card(CardRank rank, CardSuit suit) : m_rank{rank}, m_suit{suit} {}

    void setRank(const CardRank& rank){ m_rank = rank; }

    CardRank getRank() const { return m_rank; }
    
    void setSuit(const CardSuit& suit){ m_suit = suit; }
    
    void print() const
    {
        switch(m_rank)
        {
            case CardRank::rank_2:
                std::cout << '2';
                break;
            case CardRank::rank_3:
                std::cout << '3';
                break;
            case CardRank::rank_4:
                std::cout << '4';
                break;
            case CardRank::rank_5:
                std::cout << '5';
                break;
            case CardRank::rank_6:
                std::cout << '6';
                break;
            case CardRank::rank_7:
                std::cout << '7';
                break;
            case CardRank::rank_8:
                std::cout << '8';
                break;
            case CardRank::rank_9:
                std::cout << '9';
                break;
            case CardRank::rank_10:
                std::cout << "10";
                break;
            case CardRank::rank_ace:
                std::cout << 'A';
                break;
            case CardRank::rank_jack:
                std::cout << 'J';
                break;
            case CardRank::rank_king:
                std::cout << 'K';
                break;
            case CardRank::rank_queen:
                std::cout << 'Q';
                break;
            default:
                std::cout << '?';
                break;
        }
        switch(m_suit)
        {
            case CardSuit::suit_club:
                std::cout << 'C';
                break;
            case CardSuit::suit_diamond:
                std::cout << 'D';
                break;
            case CardSuit::suit_heart:
                std::cout << 'H';
                break;
            case CardSuit::suit_spade:
                std::cout << 'S';
                break;
            default:
                std::cout << '?';
                break;
        }
    }

    int getValue() const
    {
        switch(m_rank)
        {
            case CardRank::rank_2:
                return 2;
            case CardRank::rank_3:
                return 3;
            case CardRank::rank_4:
                return 4;
            case CardRank::rank_5:
                return 5;
            case CardRank::rank_6:
                return 6;
            case CardRank::rank_7:
                return 7;
            case CardRank::rank_8:
                return 8;
            case CardRank::rank_9:
                return 9;
            case CardRank::rank_10:
            case CardRank::rank_jack:
            case CardRank::rank_king:
            case CardRank::rank_queen:
                return 10;
            case CardRank::rank_ace:
                return 11;
            default:
                return 0; 
        }
    }
private:
    CardRank m_rank{};
    CardSuit m_suit{};
};

#endif
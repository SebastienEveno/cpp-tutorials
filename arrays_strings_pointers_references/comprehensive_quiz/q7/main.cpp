/*
https://www.learncpp.com/cpp-tutorial/6-x-chapter-6-comprehensive-quiz/
Question #7

BlackJack.
*/

#include <iostream>
#include <array>
#include <algorithm> // std::shuffle
#include <ctime> // for std::time
#include <random> // for std::mt19937
#include <numeric> // for std::accumulate

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
    std::cout << '\n';
}

constexpr int numberOfCards {52};
// Maximum score before losing.
constexpr int max_score {21};
// Minimum score that the dealer has to have.
constexpr int min_score_dealer {17};
using deck_type = std::array<Card, numberOfCards>;
using index_type = deck_type::size_type;

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

enum class Status
{
    Hit,
    Stand,
    None,
    max_status
};

struct Player 
{
    int score{};
};

bool playBlackJack(const deck_type& deck)
{
    index_type ind{ 0 };
    // Initialize dealer with 1 card
    Player dealer { getCardValue(deck[ind]) };
    std::cout << "The dealer's initial card is: ";
    printCard(deck[ind]);
    std::cout << "The dealer's score is: " << dealer.score << '\n';
    // Initialize player with 2 cards
    Player player {getCardValue(deck[ind + 1]) + getCardValue(deck[ind + 2])};
    std::cout << "Your initial cards are: " << '\n';
    printCard(deck[ind + 1]);
    printCard(deck[ind + 2]);

    ind += 3;
    // player goes first
    if (player.score > max_score)
    {
        // bust and lose immediately
        std::cout << "The sum of your cards is " << player.score << ". " << '\n';
        std::cout << "The sum of your cards are higher than 21." << '\n';
        return false;
    }
    else 
    {
        std::string hitOrStand{ "hit" };
        while ((hitOrStand != "stand") && (player.score <= max_score))
        {
            // check if player hit or stand
            std::cout << "The sum of your cards is " << player.score << ". " << '\n';
            std::cout << "Do you want to hit or stand? ";
            std::cin >> hitOrStand;
            if (hitOrStand == "hit")
            {
                std::cout << "You draw a card: ";
                printCard(deck[ind]);
                player.score += getCardValue(deck[ind]);
                ++ind;
            }
        }
    }

    // check if bust
    if (player.score > max_score)
    {
        std::cout << "The sum of your cards is: " << player.score << '\n';
        std::cout << "The sum of your cards is higher than 21." << '\n';
        return false;
    }

    // dealer turn
    do
    {
        std::cout << "The dealer draws a card: ";
        printCard(deck[ind]);
        dealer.score += getCardValue(deck[ind]);
        std::cout << "The sum of the dealer's cards is: " << dealer.score << '\n';
        ++ind;
    } while (dealer.score < min_score_dealer);

    if (dealer.score > max_score)
    {
        std::cout << "The sum of the dealer's cards is more than 21." << '\n';
        return true;
    }
    else
    {
        if (player.score > dealer.score)
        {
            std::cout << "Your sum is higher than the dealer's one." << '\n';
            return true;
        }
        else
        {
            std::cout << "The dealer's sum is equal or higher." << '\n';
            return false;
        }
    }
}

int main()
{
    deck_type deck{ createDeck() };
    shuffleDeck(deck);
    if (playBlackJack(deck))
    {
        std::cout << "You win!\n";
    }
    else
    {
        std::cout << "You lose!\n";
    }
    
    return 0;
}
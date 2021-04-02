#ifndef POTION_HPP
#define POTION_HPP

#include <array>
#include <sstream> // for std::stringstream
#include <string>
#include <string_view>

#include "random"

class Potion
{
public:
    enum class Effect
    {
        small,
        medium,
        large,
        
        max_effects
    };
    enum class Type
    {
        health,
        strength,
        poison,

        max_types
    };
    
    Potion(Type type, Effect effect) : m_type{type}, m_effect{effect} {}

    static Potion getRandomPotion() 
    { 
        int random_type{ getRandomNumber(0, static_cast<int>(Potion::Type::max_types) - 1) };
        int random_effect{ getRandomNumber(0, static_cast<int>(Potion::Effect::max_effects) - 1) };
        return Potion(static_cast<Type>(random_type), static_cast<Effect>(random_effect));
    }

    Effect getEffect() const { return m_effect; }
    Type getType() const { return m_type; }

    std::string_view getEffectName() const
    {
        static constexpr std::array effects{ "Small", "Medium", "Large" };
        return effects.at(static_cast<std::size_t>(m_effect));
    }

    std::string_view getTypeName() const
    {
        static constexpr std::array types{ "Health", "Strength", "Poison" };
        return types.at(static_cast<std::size_t>(m_type));
    }

    std::string getName() const
    {
        std::stringstream result{};
        result << getEffectName() << " potion of " << getTypeName();
        return result.str();
    }

private:
    Effect m_effect;
    Type m_type;
};

#endif
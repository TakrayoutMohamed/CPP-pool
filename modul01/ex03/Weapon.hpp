#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <iostream>

class Weapon
{
    private:
        /* data */
        std::string type;
    public:
        Weapon(/* args */);
        ~Weapon();
        std::string &getType(void);
        void    setType(std::string newType);
};

#endif
#include "SimpleBanana.hpp"

SimpleBanana::SimpleBanana(const char *name, bool isHidden, bool isRotten, bool toEat, bool watchOnly, const char sort[MAX_SORT_LENGTH])
    : Banana(name, isHidden, isRotten, toEat, watchOnly)
{
    if (sort == '\0' || strlen(sort) > 5)
    {
        throw std::invalid_argument("Invalid inout");
    }
    
    strcpy(this->sort, sort);
}

void SimpleBanana::operator+(const char *info)
{
    //TO DO
}

unsigned SimpleBanana::getWeight() const
{
    return ;
}

std::ostream &operator<<(std::ostream &out, const SimpleBanana &simpleBanana)
{
    return out << simpleBanana.Id << '-' << simpleBanana.sort << '-' << simpleBanana.name << '-' 
        << '-' << simpleBanana.isHidden << '-' << simpleBanana.isRotten << '-'
        << simpleBanana.toEat << '-' << simpleBanana.watchOnly << '\n';
}

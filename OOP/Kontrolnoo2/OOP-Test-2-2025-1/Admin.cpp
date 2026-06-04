#include "Admin.hpp"

Admin::Admin(const char *email, const char *password, int yearsInPosition, int competence)
    : User(email, password)
{
    if (yearsInPosition < 0 || yearsInPosition > MAX_YEARS_IN_POSITION || competence < MIN_COMPETENCE || competence > MAX_COMPETENCE)
    {
        throw std::invalid_argument("Invalid input in admin");
    }

    this->yearsInPosition = yearsInPosition;
    this->competence = competence;
}

Admin::Admin(const Admin &other)
    : User(other), yearsInPosition(other.yearsInPosition), competence(other.competence)
{}

Admin &Admin::operator=(const Admin &other)
{
    if (this != &other)
    {
        User::operator=(other);
        this->yearsInPosition = other.yearsInPosition;
        this->competence = other.competence;
    }
    
    return *this;
}

int Admin::operator++()
{
    if (this->competence >= MAX_COMPETENCE)
    {
        return this->competence = MAX_COMPETENCE;
    }
    
    return this->competence++;
}

int Admin::operator--()
{
    if (this->competence <= MIN_COMPETENCE)
    {
        return this->competence = MIN_COMPETENCE;
    }
    
    return this->competence--;
}

Admin *Admin::clone() const
{
    return new Admin(*this);
}

std::ostream &operator<<(std::ostream &out, const Admin &user)
{
    out << user.email << ' ' << user.password << ' ' << user.yearsInPosition << ' ' << user.competence << '\n';
    return out;
}

std::istream &operator>>(std::istream &in, Admin &user)
{
    char tempEmail[512];
    char tempPassword[512];
    int tempYearsInPosition;
    int tempCompetence;

    in >> tempEmail >> tempPassword >> tempYearsInPosition >> tempCompetence;
    
    if (!IsValidEmail(tempEmail) || !IsValidPassword(tempPassword) || 
        tempYearsInPosition < 0 || tempYearsInPosition > MAX_YEARS_IN_POSITION ||
        tempCompetence < MIN_COMPETENCE || tempCompetence > MAX_COMPETENCE)
    {
        throw std::invalid_argument("invlaid reading");
        return in;
    }
    
    user.email = new char[strlen(tempEmail) + 1];
    strcpy(user.email, tempEmail);

    user.password =  new (std::nothrow) char[strlen(tempPassword) + 1];
    if (!user.password)
    {
        delete[] user.email;
        throw std::bad_alloc();
    }
    strcpy(user.password, tempPassword);

    user.yearsInPosition = tempYearsInPosition;
    user.competence = tempCompetence;

    return in;
}

bool operator>(const Admin &one, const Admin &two)
{
    if (one.GetCompetence() > two.GetCompetence())
    {
        return true;
    }
    else if (one.GetCompetence() < two.GetCompetence())
    {
        return false;
    }
    
    if (one.GetYearsInPosition() > two.GetYearsInPosition())
    {
        return true;
    }
    else if (one.GetYearsInPosition() < two.GetYearsInPosition())
    {
        return false;
    }
    
    return false;
}

bool operator<(const Admin &one, const Admin &two)
{
    if (two.GetCompetence() > one.GetCompetence())
    {
        return true;
    }
    else if (two.GetCompetence() < one.GetCompetence())
    {
        return false;
    }
    
    if (two.GetYearsInPosition() > one.GetYearsInPosition())
    {
        return true;
    }
    else if (two.GetYearsInPosition() < one.GetYearsInPosition())
    {
        return false;
    }
    
    return false;
}
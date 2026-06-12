#include "Silence.hpp"

template <typename T, T M>
inline Silence<T, M>::Silence(size_t duration)
{
    //lets just say that u cant stay in silence for 100. You will go mad
    if (duration < 0 || duration > 1000)
    {
        throw std::invalid_argument("Invlaid");
    }
    
    this->duration = duration;
}

template <typename T, T M>
inline size_t Silence<T, M>::getDuration() const
{
    return this->duration;
}

template <typename T, T M>
inline T Silence<T, M>::operator[](size_t index) const
{
    return 0;
}

template <typename T, T M>
inline Silence<T, M> *Silence<T, M>::clone() const
{
    return new Silence(*this);
}

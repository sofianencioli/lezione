#include <concepts>
#include <iostream>
using namespace std;
#include <numeric>

template<typename I> requires std::integral<I>
class rational {
    I num_;
    I den_;   

public:
    
    //costruttore di default
    rational()
            : num_(I{0}), den_(I{1})
    {}

    //controllo di 0 al denominatore e/o al numeratore
    bool is_nan() const { return (den_==0 && num_ == 0); }
    bool is_inf() const { return (den_==0 && num_ != 0); }

    // funzione per semplificare i razionali (se ho Inf o NaN continua a dare Inf o NaN)
    void simpl(){
        if (den_==0) {
            return ;
        }
        I max_comune_den = gcd(num_,den_); //per avere massimo comune divisore
        num_ /= max_comune_den;
        den_ /= max_comune_den;

    }

    //costruttore user defined
    rational(const I& pnum, const I& pden)
         : num_(pnum), den_(pden) 
    {simpl();}
    I num() const {return num_; }
    I den() const {return den_; }

    
    //implementazione dell'incremento somma
    rational& operator+=(const rational& other) {
        if (this->is_nan() || other.is_nan()){ //se uno o l'altro sono NaN il risultato è NaN
            num_=0;
            den_=0;
            return *this;
        }
        if (this->is_inf() || other.is_inf()) { // per gestire gli inf
            num_= 1;
            den_=0;
            return *this;
        }  
        num_ = other.den_*num_ + den_*other.num_;
        den_ = den_ * other.den_;
        simpl();
       return *this;
    }
    
    //implementazione della somma
    rational operator+(const rational& other) const{
        rational ret= *this;
        ret += other;
        return ret;
    }

    //implementazione incremento differenza
    rational& operator-=(const rational& other) {
         if (this->is_nan() || other.is_nan()){ //se uno o l'altro sono NaN il risultato è NaN
            num_=0;
            den_=0;
            return *this;
        }
        if (this->is_inf() || other.is_inf()) { // per gestire gli inf (se c'è +inf-inf sarebbe indefinito)
            num_=1;
            den_=0;
            return *this;
        } 
        num_ = other.den_*num_ - den_*other.num_;
        den_ = den_ * other.den_;
        simpl();
       return *this;
    }
    
    //implementazione della differenza
    rational operator-(const rational& other) const{
        rational ret= *this;
        ret -= other;
        return ret;
    }
    
    //implementazione del prodotto
    rational& operator*=(const rational& other) {
        //se uno o l'altro sono NaN il risultato è NaN
         if (this->is_nan() || other.is_nan()){ 
            num_=0;
            den_=0;
            return *this;
        }
        // per gestire gli inf, se uno dei due è inf e l'altro è 0 metto NaN, mentre se sono entrambi inf metto inf
        if ((this->num_==0 && other.is_inf() )||( this->is_inf() && other.num_==0)) { 
            num_=0;
            den_=0;
            return *this;
        } 
        if (this->is_inf() || other.is_inf()) {
            num_=1;
            den_=0;
            return *this ;
        }
        num_ = other.num_*num_ ;
        den_ = den_ * other.den_;
        simpl();
       return *this;
    }
    
    rational operator*(const rational& other) const{
        rational ret= *this;
        ret *= other;
        return ret;
    }

    //implementazione della divisione
    rational& operator/=(const rational& other) {
        if (this->is_nan() || other.is_nan()) {
        num_ = 0;
        den_ = 0;
        return *this;
		}
		// divido per 0 e da infinito
		if (other.num_ == 0 && other.den_ != 0) {
        num_ = 1; 
        den_ = 0;
        return *this;
		}
		// facendo 0/inf ho 0 , metto un denominatore casuale per farlo tornare
		if (this->num_ == 0 && other.is_inf()) {
        num_ = 0; 
        den_ = 1;
        return *this;
		}
        num_ = other.den_*num_;
        den_ = den_ * other.num_;
        simpl();
       return *this;
    }
    
    rational operator/(const rational& other) const{
        rational ret= *this;
        ret /= other;
        return ret;
    }
};
//implementazione output
template<typename I>
std::ostream&
operator<<(std::ostream& os, const rational<I>& r)
{
    if (r.is_inf()) 
    os << "Inf";
    else if (r.is_nan())
    os << "NaN";
    else
    os << r.num() << "/" << r.den() ;
    return os;
}

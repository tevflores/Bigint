/*
A class to represent arbitrarily large integers
*/
#include "bigint.h"


void bigint::strip_zeros() {
    while (!number.empty() && number.back() == 0){
     number.pop_back();
    }
    if (number.empty()){
        number.push_back(0);
    }
}

/* Constructors
 *
 * */

bigint::bigint() {
    number.push_back(0);
}

bigint::bigint(const std::vector<vec_bin> &that) {
    number = that;
    this->strip_zeros();
}

bigint::bigint(unsigned long long i) {
    do {
    number.push_back((vec_bin)(i % 10));
  }
    while(i /= 10);
}

bigint::bigint(std::string str) {
    for(int i=str.size();i>0;i--) {
        number.push_back((vec_bin)((i-1)));
        this->strip_zeros();
    }
}



bigint::bigint(std::ifstream &infile) {
  if(!infile.fail()) {
    std::string line, file_contents;
    while(getline(infile, line)){
      file_contents += line;
      *this = file_contents;
    }
  }
  else{
    std::cerr << "Could not open the file." << std::endl;
  }
}

bigint::bigint(const bigint &that) {
    *this=that;
}


/* Number Access
 *
 * */
const std::vector<vec_bin> &bigint::getNumber() const {
    return number;
}

vec_bin bigint::operator[](size_t index) const {
    return number[index];
}


/** Comparators
 *
 * */
bool bigint::operator==(const bigint &that) const {
    // return number == that.number;
        if (number.size() == that.number.size()){
        return true;
        }
        else if (number.size() != that.number.size()){
        return false;
    }
        else {
        for (size_t i = number.size(); i>0; i--){
            if (number[i-1]==that[i-1]) {
                return true;
            }
            else if (that[i-1]!=number[i-1]){
                return false;
            }
        }
    }
    return false;
}

bool bigint::operator!=(const bigint &that) const {
    return !(that==*this);
}

bool bigint::operator<(const bigint &that) const {
    if (number.size() < that.number.size()){
        return true;
    }
    else if (that.number.size() < number.size()){
        return false;
    }
    else {
        for (size_t i = number.size(); i>0; i--){
            if (number[i-1]<that[i-1]) {
                return true;
            }
            else if (that[i-1]<number[i-1]){
                return false;
            }
        }
    }
    return false;
}

bool bigint::operator<=(const bigint &that) const {
    return !(that < *this);
}

bool bigint::operator>(const bigint &that) const {
    return that < *this;
}

bool bigint::operator>=(const bigint &that) const {
return !(that < *this);
}


/** Addition
 *
 * */

// bigint bigint::add(const bigint &that) const {

// }

// bigint bigint::operator+(const bigint &that) const {

// }

// bigint &bigint::operator+=(const bigint &that) {

// }

// bigint &bigint::operator++() {

// }

// bigint bigint::operator++(int) {

// }


// /** Subtraction
//  *
//  * */

// bigint bigint::subtract(const bigint &that) const {

// }

// bigint bigint::operator-(const bigint &that) const {

// }

// bigint &bigint::operator-=(const bigint &that) {

// }

// bigint &bigint::operator--() {

// }

// bigint bigint::operator--(int) {

// }


// /** Multiplication
//  *
//  * */

// bigint bigint::multiply(const bigint &that) const {

// }

// bigint bigint::operator*(const bigint &that) const {

// }

// bigint &bigint::operator*=(const bigint &that) {

// }


// /** Division
//  *
//  * */

// bigint bigint::divide(const bigint &that) const {

// }

// bigint bigint::operator/(const bigint &that) const {

// }

// bigint &bigint::operator/=(const bigint &that) {

// }


// /** Modulo
//  *
//  * */

// bigint bigint::mod(const bigint &that) const {

// }

// bigint bigint::operator%(const bigint &that) const {

// }

// bigint &bigint::operator%=(const bigint &that) {

// }


// /** Power
//  *
//  * */

// bigint bigint::pow(unsigned long long n) {

// }


/** Display methods
 *
 * */

std::ostream &operator<<(std::ostream &os, const bigint &bigint1) {
    return os << bigint1.to_string(true);
}

std::string bigint::to_string(bool commas) const {
    std::string result;
  for (size_t i = number.size() - 1; i > 0; --i){
    if (i % 3 == 0 && commas){
        result += ',';
    }
    result += (static_cast<char>(number[i-1] + '0'));
  }

  return result;
}

std::string bigint::scientific(unsigned int decimal_points) const {
  std::string result;
  for (unsigned int i = 0; i <= decimal_points; ++i){
    if (i == 1){
      result += '.';
    }
    result += std::to_string((i < number.size()) ? number[number.size()-i-1] : 0);
  }
    result += "E";
    result += std::to_string(number.size() - 1);
    return result;
}

void bigint::to_file(std::ofstream &outfile, unsigned int wrap) {
  std::string result = this->to_string();
  for (int i = 0; i < (int)result.length(); ++i){
    outfile << result[i];
    if (i % wrap == wrap - 1){
      outfile << std::endl;
    }
  }
}

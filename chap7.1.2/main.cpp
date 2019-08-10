#include <iostream>
#include <string>
using std::istream;
using std::ostream;
struct sales_data
{
    sales_data() = default;
    sales_data(const std::string &s): bookNO(s){}
    sales_data(const std::string &s, unsigned n, double p):
    bookNO(s), units_sold(n), revenue(p*n){};


    std::string isbn() const
    {
        return bookNO;
    }
    sales_data& combine(const sales_data& rhs)
    {
        units_sold += rhs.units_sold;
        revenue += rhs.revenue;
        return *this;
    }
    std::string bookNO;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

istream &read(istream &is, sales_data &item);
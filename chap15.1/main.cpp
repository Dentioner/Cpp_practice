#include<iostream>
#include<string>

using namespace std;


class quote
{
public:
	string isbn() const { return bookNo; };
	virtual double net_price(size_t n) const { return  n * price; };
	quote() = default;
	quote(const string &book, double sales_price):
		bookNo(book), price(sales_price){}
	virtual ~quote() = default;

private:
	string bookNo;

protected:
	double price = 0.0;
};

class bulk_quote : public quote
{
public:
	bulk_quote() = default;
	bulk_quote(const string&, double, size_t, double);
	double net_price(size_t cnt) const override
	{
		if (cnt >= min_qty)
			return cnt * (1 - discount) * price;
		else
			return cnt * price;
	}

private:
	size_t min_qty = 0;
	double discount = 0.0;

};

class disc_quote : public quote
{
public:
	disc_quote() = default;
	disc_quote(const string & book, double price, size_t qty, double disc):
		quote(book, price), quantity(qty), discount(disc) {}
	double net_price(size_t) const = 0;

protected:
	size_t quantity = 0;
	double discount = 0.0;

};

class bulk_quote2 :public disc_quote
{
public:
	bulk_quote2() = default;
	bulk_quote2(const string & book, double price, size_t qty, double disc):
		disc_quote(book, price, qty, disc){}
	double net_price(size_t) const override;
};

double print_total(ostream& os, const quote& item, size_t n)
{
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: "
		<< ret << endl;
	return ret;
}


int main()
{
	quote a;
	bulk_quote b;
	double da, db;
	
	da = print_total(cout, a, 5);
	db = print_total(cout, b, 7);
	return 0;
}
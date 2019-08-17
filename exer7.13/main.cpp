#include<iostream>
#include<string>


using namespace std;

class screen
{
    private:
        unsigned height;
        unsigned width;
        unsigned cursor;
        string contents;
    
    public:
        screen() = default;
        screen(unsigned h, unsigned w):height(h), width(w), contents(h*w, ' '){}
        screen(unsigned h, unsigned w, char c):height(h), width(w), contents(h*w, c){};
        
        double avg_practice() const;
};

inline double screen::avg_practice() const
{
    

}
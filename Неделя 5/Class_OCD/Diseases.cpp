#pragma once
#include "Diseases.h"

std::string  Diseases::Disease::storytelling()
{
    return "i'm sick :(";
}

int Diseases::Disease::apathy()
{
    return -1;
};




int Diseases::OCD::excessive_pedantry()
{
    return 7;
};
int Diseases::OCD::frightening_drives()
{
    return 5;
}
int Diseases::OCD::apathy()
{
    return 3;
};
std::string  Diseases::OCD::storytelling()
{
    return "Did i close the door?";
};


int Diseases::PanicAttacks::frightening_drives()
{
    return 10;
};
int Diseases::PanicAttacks::panic_attacks()
{
    return 10;
}
int Diseases::PanicAttacks::apathy()
{
    return 6;
};


int Diseases::Anorexia::fasting()
{
    return 10;
}
int Diseases::Anorexia::apathy()
{
    return 8;
};


int Diseases::Bulimia::overeating()
{
    return 10;
}
int Diseases::Bulimia::apathy()
{
    return 9;
};





























/*namespace Diseases
{

    class Disease {
    public:

        virtual int apathy()
        {
            return -1;
        };

        virtual std::string storytelling()
        {
            return "i'm sick :(";
        };
    };

    class OCD : public Disease {
    private:
        int excessive_pedantry()
        {
            return 7;
        };
    public:
        virtual int frightening_drives()
        {
            return 5;
        }

        int apathy() override
        {
            return 3;
        };

        std::string storytelling() override
        {
            return "Did i close the door?";
        };

    };

    class PanicAttacks : public OCD {
        int frightening_drives() override
        {
            return 10;
        };

        int panic_attacks()
        {
            return 10;
        }
        int apathy() override
        {
            return 6;
        };
    };

    class Anorexia : public Disease {
        int fasting()
        {
            return 10;
        }
        int apathy() override
        {
            return 8;
        };
    };

    class Bulimia : public Disease {
        int overeating()
        {
            return 10;
        }
        int apathy() override
        {
            return 9;
        };
    };
};*/
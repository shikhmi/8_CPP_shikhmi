#pragma once
#include <iostream>
#include <string>




namespace Diseases
{

    class Disease {
    public:

        int apathy();

        std::string storytelling();
    };

    class OCD
    {
    private:
        int excessive_pedantry();

    public:
        int frightening_drives();
        int apathy();
        std::string storytelling();
    };

    class PanicAttacks
    {
        int frightening_drives();
        int panic_attacks();
        int apathy();
    };

    class Anorexia
    {
        int fasting();
        
        int apathy();
        
    };

    class Bulimia
    {
        int overeating();
       
        int apathy();
        
    };
};
#include <iostream>
#include <limits>

int main()
{
    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }
}
// PROMPTING AI Rules:
// CONTEXT:
//What am I building ?
//
//GOAL :
//    What am I trying to accomplish ?
//
//    CURRENT BEHAVIOR :
//What happens now ?
//
//EXPECTED BEHAVIOR :
//What should happen ?
//
//CONSTRAINTS :
//    What course / project rules must be followed ?
//
//    HELP REQUESTED :
//Explain / review / debug / suggest.
//
//Do not rewrite my entire project.


// AFTER AI RESPONDS:
//-Do I understand this ?
//
//-Does it match my existing project ?
//
//-Does it follow the assignment requirements ?
//
//-Did it introduce something we are not allowed to use ?
//
//-Did it change more than necessary ?
//
//-Can I explain why this works ?
//
//-Can I test it ?
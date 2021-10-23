#ifndef TODO_H_INCLUDED
#define TODO_H_INCLUDED

#include "Interaction.h"
#include "Date.h"

class Todo
{
    private:

        Interaction *lienInteraction;
        std::string contenu;
        struct tm * date;


    public:

        std::string getContenu();


};

#endif // TODO_H_INCLUDED

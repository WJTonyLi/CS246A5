#ifndef CLI_VIEW_H
#define CLI_VIEW_H

#include <iostream>
#include "subject.h"

class CliView : public Subject<std::string> {
    std::istream& is;
    std::string command;
    public:
        CliView(std::istream& is);
        std::string getInfo() const override;
        void readCommands();
};

#endif

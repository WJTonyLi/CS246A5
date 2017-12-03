#ifndef CLI_VIEW_H
#define CLI_VIEW_H

#include <iostream>
#include "shared_ptr_subject.h"

class CliView : public SharedPtrSubject<std::string> {
    std::istream& is;
    bool done;
    std::string command;
    public:
        CliView(std::istream& is);
        bool isDone() const;
        std::string getInfo() const override;
        void readCommands();
};

#endif

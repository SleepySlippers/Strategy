//
// Created by Arseny's on 09.04.2020.
//

#ifndef STRATEGY_HANDLEABLE_H
#define STRATEGY_HANDLEABLE_H

#include <iostream>

#define NSC "No suitable command\n"

using std::string;

class Handleable {
public:

    virtual std::string HandleAction(const std::string &command) = 0;

    virtual std::string CommandsCanHandle() = 0;

    virtual std::string Help(){
        return CommandsCanHandle();
    }

};


#endif //STRATEGY_HANDLEABLE_H

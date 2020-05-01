//
// Created by Arseny's on 09.04.2020.
//

#ifndef STRATEGY_HANDLEABLE_H
#define STRATEGY_HANDLEABLE_H

#include <iostream>

#define NSC "No suitable command\n"

#include "../ColoredString.h"

#include <map>

#define NEED_INFO (false)

using std::string;
#define STANDARD_HELP_FUNCTION_BODY ColoredString ans; for (const auto& it : CommandsCanHandle()){ ans.Add(it.first, YELLOW); ans.Add(" "); ans.Add(it.second); ans.Add("\n"); } return ans;

#define MY_HANDLE_TYPE (1)
#define ENEMY_HANDLE_TYPE (MY_HANDLE_TYPE + 1)

class Handleable {
public:

    int myType = MY_HANDLE_TYPE;

    Handleable(int type = MY_HANDLE_TYPE) : myType(type) {

    }

    virtual bool CanHandle(int HandlerType) {
        return myType == HandlerType;
    }

    virtual int& GetMyType(){
        return myType;
    }

    virtual ColoredString HandleAction(const std::string &command) = 0;

    virtual std::vector<std::pair<string, string>> CommandsCanHandle()  = 0;

    virtual ColoredString Help(){
        STANDARD_HELP_FUNCTION_BODY
    }

    virtual ~Handleable() = default;
};


#endif //STRATEGY_HANDLEABLE_H

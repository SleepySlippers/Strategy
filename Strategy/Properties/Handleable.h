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

class Handleable {
public:

    virtual ColoredString HandleAction(const std::string &command) = 0;

    virtual std::vector<pair<string, string>> CommandsCanHandle()  = 0;

    virtual ColoredString Help(){
        STANDARD_HELP_FUNCTION_BODY
    }

};


#endif //STRATEGY_HANDLEABLE_H

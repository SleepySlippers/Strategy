//
// Created by Arseny's on 10.04.2020.
//

#ifndef MYSTRATEGY_WORKER_H
#define MYSTRATEGY_WORKER_H


#include "Unit.h"

class Worker : public Unit {
public:
    Worker();

    ColoredString HandleAction(const std::string &command) override;

    std::vector<pair<string, string>> CommandsCanHandle() override;

    virtual ~Worker() = default;
};


#endif //MYSTRATEGY_WORKER_H

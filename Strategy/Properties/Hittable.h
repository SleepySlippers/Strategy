//
// Created by Arseny's on 08.04.2020.
//

#ifndef STRATEGY_HITTABLE_H
#define STRATEGY_HITTABLE_H


class Hittable : public Handleable {
public:
    int hp = 100;
    int defence = 0;

    virtual void GetDamage(int dmg){
        if (hp <= 0) return;
        hp -= dmg * (100 - defence) / 100;
        if (hp <= 0){
            OnDeath();
        }
    }

    virtual void OnDeath(){}

    std::string HandleAction(const std::string& command) override{
        std::istringstream in(command);
        std::string cmnd;
        in >> cmnd;
        if (cmnd == "Info"){
            std::ostringstream ans;
            ans << "HP is " << hp << "\nDefence is " << defence << "%\n";
            return ans.str();
        }
        if (cmnd == "Help" || cmnd == "help"){
            return Help();
        }
        return NSC;
    }

    std::string CommandsCanHandle() override{
        return "Info\n";
    }
};


#endif //STRATEGY_HITTABLE_H

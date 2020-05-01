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

    ColoredString HandleAction(const std::string& command) override{
        std::istringstream in(command);
        std::string cmnd;
        in >> cmnd;
        if (cmnd == "Info"){
            ColoredString ans;
            ans.Add("HP is ");
            ans.Add(hp, YELLOW);
            ans.Add("\nDefence is ");
            ans.Add(defence, YELLOW);
            ans.Add("%\n");
            return ans;
        }
        if (cmnd == "Help" || cmnd == "help"){
            return Help();
        }
        return NSC;
    }

    std::vector<pair<string, string>> CommandsCanHandle() override {
        std::vector<pair<string, string>> ans;
        if (NEED_INFO) {
            ans.push_back({"Info", "- full information"});
        }
        return ans;
    }
};


#endif //STRATEGY_HITTABLE_H

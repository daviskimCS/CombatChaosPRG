#include "../header/stage.h"

Stage::Stage() {
    this->name = "null";
    this->description = "null";
}

Stage::Stage(string name, string description) {
    this->name = name;
    this->description = description;
}

void Stage::add_item(string item) {
    items.push_back(item);
}

void Stage::remove_item(string item) {
    for (auto it = items.begin(); it != items.end(); ++it) {
        if (*it == item) {
            items.erase(it);
            break;
        }
    }
}

bool Stage::has_item(string item) const {
    for (auto it = items.begin(); it != items.end(); ++it) {
        if (*it == item) {
            return true;
        }
    }
    return false;
}

string Stage::get_name() const {
    return name;
}

string Stage::get_description() const {
    return description;
}
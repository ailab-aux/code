#include <iostream>
#include <stdint.h>
#include <vector>
#include <string>
#include <list>

struct buffer_t {
    buffer_t(size_t size)
        : data_(size) {

    }

    void *pointer() { return (moved_ ? nullptr : &data_[0]); }

    std::vector<uint8_t> move() {
        std::vector<uint8_t> tmp;
        tmp.swap(data_);
        return tmp;
    }

    std::vector<uint8_t> const& ref() const { return data_; }
    std::vector<uint8_t>& ref() { return data_; }

private:
    std::vector<uint8_t> data_;
    bool moved_ = false;
};

struct blist_t {
    size_t append(buffer_t &buf) {
        blist_.push_back(buf.move());
        return blist_.size();
    }
    std::list<std::vector<uint8_t>> const& ref() const { return blist_; }
    std::list<std::vector<uint8_t>>& ref() { return blist_; }
private:
    std::list<std::vector<uint8_t>> blist_;
};

int main() {

    buffer_t data(100);
    void *pointer = data.pointer();
    size_t len = data.ref().size();
    std::cout << "data length: " << len << std::endl;

    blist_t bl;
    bl.append(data);

    pointer = data.pointer();
    len = data.ref().size();
    std::cout << "data length: " << len << std::endl;

    auto x = bl.ref();
    std::cout << "data list size: " << x.size() << std::endl;
    auto y = bl.ref().begin();
    std::cout << "data len: " << (*y).size() << std::endl;

    return 0;
}

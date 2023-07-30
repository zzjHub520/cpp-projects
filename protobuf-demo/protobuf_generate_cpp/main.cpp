#include <iostream>
#include "foo.pb.h"

using namespace std;

int main() {
    tutorial::Person person;

    // 设置字段值
    person.set_name("John Doe");
    person.set_id(123);
    person.set_email("johndoe@example.com");

    // 添加电话号码
    tutorial::PhoneNumber *phone1 = person.add_phones();
    phone1->set_number("1234567890");
    phone1->set_type(tutorial::PhoneType::MOBILE);

    tutorial::PhoneNumber *phone2 = person.add_phones();
    phone2->set_number("9876543210");
    phone2->set_type(tutorial::PhoneType::WORK);

    // 添加 map 数据
    person.mutable_mp()->insert({1, "Value1"});
    person.mutable_mp()->insert({2, "Value2"});

    // 获取字段值
    std::cout << "Name: " << person.name() << std::endl;
    std::cout << "ID: " << person.id() << std::endl;
    std::cout << "Email: " << person.email() << std::endl;

    // 获取电话号码
    for (const auto &phone: person.phones()) {
        std::cout << "Phone number: " << phone.number() << std::endl;
        std::cout << "Phone type: " << phone.type() << std::endl;
    }

    // 获取 map 数据
    for (const auto &pair: person.mp()) {
        std::cout << "Map key: " << pair.first << ", value: " << pair.second << std::endl;
    }

    cout << "============" << endl;
    auto phes=person.mutable_phones();
    phes->Add();
    // 获取电话号码
    for (const auto &phone: person.phones()) {
        std::cout << "Phone number: " << phone.number() << std::endl;
        std::cout << "Phone type: " << phone.type() << std::endl;
    }
    cout << "============" << endl;
    auto i1=person.mutable_phones(0);
    i1->set_number("asdf");
    for (const auto &phone: person.phones()) {
        std::cout << "Phone number: " << phone.number() << std::endl;
        std::cout << "Phone type: " << phone.type() << std::endl;
    }

    return 0;
}
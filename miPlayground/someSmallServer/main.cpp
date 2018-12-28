#include <iostream>
#include <memory>
#include <cstring>
// including sqlite ORM
#include "sqlite_orm/sqlite_orm.h"
// including RESTinio
// It is a header-only C++14 library that gives you an embedded HTTP/Websocket server.
#include "restinio/all.hpp"

#include "Models/Employee.h"

using namespace sqlite_orm;

void createDBandUserTable();

int main() {
    std::cout << "[CREATING A DB]" << std::endl;
    // testing sqlite orm
    createDBandUserTable();

    // testing websockets using restinio
    restinio::run(
            restinio::on_this_thread()
            .port(8080)
            .address("localhost")
            .request_handler([](auto request){
                return request->create_response()
                .set_body("[C++ RESPONSE]")
                .done();
            })
            );
    return 0;
}


void createDBandUserTable()
{
    // creating a data base or calling it
    auto storage = make_storage("/home/cheetos/Developer/CProgramming/Cpp-AdvancedTopics/miPlayground/someSmallServer/test.db",
                                make_table("users",
                                        // creating all columns inside users table
                                           make_column("id", &User::id, autoincrement(), primary_key()),
                                           make_column("first_name",&User::first_name),
                                           make_column("last_name", &User::last_name),
                                           make_column("age", &User::age),
                                           make_column("address", &User::address),
                                           make_column("salary", &User::salary),
                                           make_column("image_url", &User::imageUrl),
                                           make_column("type_id", &User::typeId)),
                                make_table("user_types",
                                           make_column("id", &UserType::id, autoincrement(), primary_key()),
                                           make_column("name", &UserType::name, default_value("name_placeholder"))
                                ));

    storage.sync_schema();
    storage.remove_all<User>();
    storage.remove_all<UserType>();
}
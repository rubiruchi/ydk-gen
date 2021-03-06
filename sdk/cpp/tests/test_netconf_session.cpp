/*  ----------------------------------------------------------------
 Copyright 2016 Cisco Systems

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

 http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
 ------------------------------------------------------------------*/
#include <string.h>
#include "../core/src/path/netconf_session.hpp"
#include "../core/src/errors.hpp"
#include <iostream>
#include "config.hpp"
#include "catch.hpp"
using namespace ydk;
using namespace std;



TEST_CASE("CreateP")
{
    ydk::path::Repository repo{};
    NetconfSession session{repo, "127.0.0.1", "admin", "admin", 12022};

    CHECK_NOTHROW(session.get_root_schema());
}


TEST_CASE("CreateNoRepoP")
{

    NetconfSession session{ "127.0.0.1", "admin", "admin", 12022};

    CHECK_NOTHROW(session.get_root_schema());
}

TEST_CASE("CreateNoRepoPTCP")
{
    NetconfSession session{ "127.0.0.1", "admin", "admin", 12307, "tcp"};
    CHECK_NOTHROW(session.get_root_schema());
}

TEST_CASE("CreateNoRepoPTimeOut")
{
    NetconfSession session{ "127.0.0.1", "admin", "admin", 12307, 99};
    CHECK_NOTHROW(session.get_root_schema());
}

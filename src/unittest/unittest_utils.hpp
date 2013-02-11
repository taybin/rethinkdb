// Copyright 2010-2013 RethinkDB, all rights reserved.
#ifndef UNITTEST_UNITTEST_UTILS_HPP_
#define UNITTEST_UNITTEST_UTILS_HPP_

#include <set>

#include "errors.hpp"
#include <boost/function.hpp>

#include "containers/scoped.hpp"
#include "rpc/serialize_macros.hpp"
#include "arch/address.hpp"

namespace unittest {

class temp_file_t {
public:
    explicit temp_file_t(const char *tmpl);
    const char *name() { return filename.data(); }
    ~temp_file_t();

private:
    scoped_array_t<char> filename;

    DISABLE_COPYING(temp_file_t);
};

void let_stuff_happen();

std::set<ip_address_t> get_unittest_addresses();

portno_t randport();

void run_in_thread_pool(const boost::function<void()>& fun, int num_workers = 1);

}  // namespace unittest

#endif /* UNITTEST_UNITTEST_UTILS_HPP_ */
#include <cstdio>
#include <gflags/gflags.h>

#include "ext/cpr.h"
#include "ext/json.h"
#include "ext/sprintf.h"

DEFINE_string(server_host, "localhost", "Server host");
DEFINE_int32(server_port, 1337, "Server port");

int main(int argc, char* argv[]) {
    gflags::ParseCommandLineFlags(&argc, &argv, true);
    auto to = StringPrintf("http://%s:%d/stop", FLAGS_server_host.c_str(),
                           FLAGS_server_port);
    auto ret = cpr::Post(cpr::Url(to), cpr::Body{},
                         cpr::Header{{"Content-Type", "text/plain"}});
    printf("Status code: %d\n", ret.status_code);
    printf("Body: %s\n", ret.text.c_str());
}

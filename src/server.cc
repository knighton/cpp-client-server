#include <cstdio>
#include <gflags/gflags.h>

#include "ext/crow.h"
#include "ext/json.h"

DEFINE_int32(port, 1337, "Port to serve on.");

int main(int argc, char* argv[]) {
    gflags::ParseCommandLineFlags(&argc, &argv, true);

    crow::SimpleApp app;

    CROW_ROUTE(app, "/")([]() {
        printf("/\n");
        return "Hello world!";
    });

    CROW_ROUTE(app, "/json")
            .methods("POST"_method)
            ([](const crow::request& req) {
        printf("/json\n");
        auto x = json::parse(req.body);
        json ret = {{"result", x["a"]}};
        return ret.dump();
    });

    CROW_ROUTE(app, "/stop").methods("POST"_method)([&app]() {
        printf("/stop\n");
        app.stop();
        return "";
    });

    auto port = static_cast<uint16_t>(FLAGS_port);
    app.loglevel(crow::LogLevel::Warning).port(port).multithreaded().run();
}

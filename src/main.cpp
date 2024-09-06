#include <filesystem>
#include <iostream>
#include <fstream>

#define let const auto
#define let_mut auto

int main(int argc, char *argv[]) {
    let_mut ao = false, to = false;
    std::string title = "", author = "";

    for (int i = 1; i < argc; i++) {
        if (ao) {
            author = argv[i];
            ao = false;
        } else if (to) {
            title = argv[i];
            to = false;
        } else {
            let x = (std::string)argv[i];

            if (x[0] == '-') {
                if (x.rfind("-a", 0) == 0) {
                    if (x[2] == '=')
                        author = x.substr(3);
                    else
                        ao = true;
                } else if (x.rfind("--author", 0) == 0) {
                    if (x[8] == '=')
                        author = x.substr(9);
                    else
                        ao = true;
                } else if (x.rfind("-t", 0)) {
                    if (x[2] == '=')
                        title = x.substr(3);
                    else
                        to = true;
                } else if (x.rfind("--title", 0)) {
                    if (x[7] == '=')
                        title = x.substr(8);
                    else
                        to = true;
                }
            } else if (std::filesystem::exists(std::filesystem::path(argv[i]))) {
                std::string rval = "";
            }
        }
    }
}

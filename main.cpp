using namespace std;
#ifndef STDLIBS
#define STDLIBS
#include <iostream>
#include <stdio.h>
#include <cmath>
#endif

#include "image.h"

extern "C" {
    #include "commander/src/commander.h"
}

static void action(command_t *self){
    cout << "commander" << endl;
}

int main(int argc, char **argv){
    command_t cmd;
    command_init(&cmd, argv[0], "0.0.1");
    command_option(&cmd,"-v", "--verbose", "enable verbose stuff", action);
    command_option(&cmd,"-r", "--required <arg>", "required arg", action);
    command_option(&cmd,"-o", "--optional [arg]", "optional arg", action);
    command_parse(&cmd, argc, argv);
    printf("additional args:\n");
    for (int i = 0; i < cmd.argc; ++i) {
        printf("  - '%s'\n", cmd.argv[i]);
    }

    command_free(&cmd);
    image I("image.png");
    cout << I.get_filename() << endl;
    return 0;
}

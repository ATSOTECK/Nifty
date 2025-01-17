/*
 * Nifty - Nifty Programming Language
 * Copyright (c) 2024 Skyler Burwell
 *
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software
 *    in a product, an acknowledgment in the product documentation would be
 *    appreciated but is not required.
 * 2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 * 3. This notice may not be removed or altered from any source distribution.
 *
 */

#include "help.h"

#include "str.h"

void printHelp(const char *cmd) {
    const int width = 25;
    const bool printAll = str_eq(cmd, "all");
    println("Nifty Programming Language\n");

    if (str_eq(cmd, "build") || printAll) {
        println("Usage: nifty build <inputs> <flags>");
        printStrsWithSpacer("\tnifty build <string>", '-', "Build the default or specified target.", width);
        dbln();
        println("Examples:");
        printStrsWithSpacer("\tnifty build", '-', "Builds the default target in 'build.toml'.", width); // TODO: NIFTY_BUILD_FILE
        printStrsWithSpacer("\tnifty build main.nifty", '-', "Builds 'main.nifty'.", width);
        printStrsWithSpacer("\tnifty build editor", '-', "Builds the target 'editor' in 'build.toml'.", width); // TODO: NIFTY_BUILD_FILE
        dbln();
        println("Build specific flags:");
        printStrsWithSpacer("\t--all", '-', "Builds all the targets in the build file.", width);

        if (!printAll) {
            return;
        }
    }

    if (str_eq(cmd, "run") || printAll) {
        if (printAll) {
            dbln();
        }

        println("Usage: nifty run <inputs> <flags>");
        printStrsWithSpacer("\tnifty run <string>", '-', "Build and run the default or specified target.", width);
        dbln();
        println("Examples:");
        printStrsWithSpacer("\tnifty run", '-', "Builds and runs the default target in 'build.toml'.", width); // TODO: NIFTY_BUILD_FILE
        printStrsWithSpacer("\tnifty run main.nifty", '-', "Builds and runs 'main.nifty'.", width);
        printStrsWithSpacer("\tnifty run editor", '-', "Builds and runs the target 'editor' in 'build.toml'.", width); // TODO: NIFTY_BUILD_FILE

        if (!printAll) {
            return;
        }
    }

    if (str_eq(cmd, "clean") || printAll) {
        if (printAll) {
            dbln();
        }

        println("Usage: nifty clean <inputs> <flags>");
        printStrsWithSpacer("\tnifty clean <string>", '-', "Delete compiled files for the project or target.", width);
        dbln();
        println("Examples:");
        printStrsWithSpacer("\tnifty clean", '-', "Cleans the default target in 'build.toml'.", width); // TODO: NIFTY_BUILD_FILE
        printStrsWithSpacer("\tnifty clean editor", '-', "Cleans the target 'editor' in 'build.toml'.", width); // TODO: NIFTY_BUILD_FILE
        dbln();
        println("Clean specific flags:");
        printStrsWithSpacer("\t--all", '-', "Cleans all the targets in the build file.", width);

        if (!printAll) {
            return;
        }
    }

    if (str_eq(cmd, "new") || printAll) {
        if (printAll) {
            dbln();
        }

        println("Usage: nifty new <flags>");
        printStrsWithSpacer("\tnifty new", '-', "Creates a new nifty project in the current directory.", width);
        dbln();
        println("Project Info:");
        printStrsWithSpacer("\tProject name", '-', "Name of the project. May not contain whitespace.", width);
        printStrsWithSpacer("\tEntry point", '-', "The file containing the default entry point. May not contain whitespace.", width);
        printStrsWithSpacer("\tAuthor", '-', "Name of the person or organization developing the project. Optional.", width);
        printStrsWithSpacer("\tLicense", '-', "The license for this project. A license.md file will be autogenerated. Optional.", width);
        dbln();
        println("Licences:");
        printStrsWithSpacer("\tSPDX short identifier)", '-', "(Description)", width);
        printStrsWithSpacer("\tApache-2.0", '-', "Apache License, Version 2.0", width);
        printStrsWithSpacer("\tBSD-3-Clause", '-', "The 3-Clause (New) BSD License also called Modified BSD License", width);
        printStrsWithSpacer("\tBSD-2-Clause", '-', "The 2-Clause (Simplified) BSD License also called FreeBSD License", width);
        printStrsWithSpacer("\tGPL-2.0", '-', "GNU General Public License version 2", width);
        printStrsWithSpacer("\tGPL-3.0-only", '-', "GNU General Public License version 3", width);
        printStrsWithSpacer("\tLGPL-2.1", '-', "GNU Lesser General Public License version 2.1", width);
        printStrsWithSpacer("\tLGPL-3.0", '-', "GNU Lesser General Public License version 3", width);
        printStrsWithSpacer("\tMIT", '-', "The MIT License", width);
        printStrsWithSpacer("\tMPL-2.0", '-', "Mozilla Public License 2.0", width);
        printStrsWithSpacer("\tCDDL-1.0", '-', "Common Development and Distribution License 1.0", width);
        printStrsWithSpacer("\tEPL-2.0", '-', "Eclipse Public License version 2.0", width);
        printStrsWithSpacer("\tZlib", '-', "The zlib/libpng License (Zlib)", width);
        dbln();
        println("License identifiers are not case sensitive.");
        println("Other licenses can be used but you must provide them.");

        if (!printAll) {
            return;
        }
    }

    if (str_eq(cmd, "test") || printAll) {
        if (printAll) {
            dbln();
        }

        println("Usage: nifty test <inputs> <flags>");
        printStrsWithSpacer("\tnifty test <string>", '-', "Build and run all tests in the default or specified target.", width);
        dbln();
        println("Examples:");
        printStrsWithSpacer("\tnifty test", '-', "Builds and runs all tests in the default target in 'build.toml'.", width); // TODO: NIFTY_BUILD_FILE
        printStrsWithSpacer("\tnifty test editor", '-', "Builds and runs all tests in the target 'editor' in 'build.toml'.", width); // TODO: NIFTY_BUILD_FILE
        dbln();
        println("Test specific flags:");
        printStrsWithSpacer("\t-file <string>", '-', "Builds and runs all the tests in the specified file.", width);
        printStrsWithSpacer("\t-name <string>", '-', "Builds and runs the specified test.", width);
        printStrsWithSpacer("\t-prefix <string>", '-', "Builds and runs all tests with the given prefix.", width);

        if (!printAll) {
            return;
        }
    }

    if (str_eq(cmd, "docs") || printAll) {
        if (printAll) {
            dbln();
        }

        println("docs");
        println("\tTODO");

        if (!printAll) {
            return;
        }
    }

    if (str_eq(cmd, "version") || printAll) {
        if (printAll) {
            dbln();
        }

        printStrsWithSpacer("version", '-', "Prints the nifty version.", width);

        if (!printAll) {
            return;
        }
    }

    if (str_eq(cmd, "info") || printAll) {
        if (printAll) {
            dbln();
        }

        printStrsWithSpacer("info", '-', "Prints nifty compiler information.", width);

        if (!printAll) {
            return;
        }
    }

    if (str_eq(cmd, "list") || printAll) {
        if (printAll) {
            dbln();
        }

        printStrsWithSpacer("list", '-', "Lists all the targets in the build file.", width);

        if (!printAll) {
            return;
        }
    }

    if (str_eq(cmd, "flags") || printAll) {
        if (printAll) {
            dbln();
        }

        println("Flags:");
        printStrsWithSpacer("\t--disable-colors", '-', "Disables color output to the terminal.", width);

        if (!printAll) {
            return;
        }
    }

    if (str_eq(cmd, "env") || printAll) {
        if (printAll) {
            dbln();
        }

        println("Environment variables checked by the compiler:");
        printStrsWithSpacer("\tNIFTY_DISABLE_COLORS", '-', "Disables color output to the terminal if defined.", width);

        if (!printAll) {
            return;
        }
    }

    if (str_eq(cmd, "config") || printAll) {
        if (printAll) {
            dbln();
        }

        println("config");
        println("\tTODO");

        if (!printAll) {
            return;
        }
    }

    if (str_eq(cmd, "colors") || printAll) {
        if (printAll) {
            dbln();
        }

        println("Colors:");
        println("Because colors will be different for different terminal configurations you may not like the default");
        println("color choices or they may not be easily readable. Because of this the colors can be overwritten in");
        println("the compiler config file. Run 'nifty help config' for information on configuration.");
        println("This command prints out a sentence in 256 colors with the code at the end.");
        println("The following can be changed:");
        printStrsWithSpacer("\terrorColor <number>", '-', "Sets the error color.", width);
        printStrsWithSpacer("\twarnColor <number>", '-', "Sets the warning color.", width);
        printStrsWithSpacer("\tlineColor <number>", '-', "Sets the squiggly line color for warnings/errors.", width);
        printStrsWithSpacer("\thighlightColor <number>", '-', "Sets the color for highlighting text in messages.", width);

        if (!printAll) {
            return;
        }
    }

    if (str_eq(cmd, "help")) {
        println("Huh?");
        return;
    }

    if (str_eq(cmd, "me")) {
        println("I wish I could :(");
        return;
    }

    if (str_eq(cmd, "definition")) {
        if (printAll) {
            dbln();
        }

        println("nifty\tnif*ty");
        printStrsWithSpacer("adjective", '-', "Particularly good, skillful, or effective.", width);
        printStrsWithSpacer("adjective", '-', "Fashionable; stylish.", width);

        return;
    }

    if (!str_empty(cmd) && !printAll) {
        println("Unknown help input '%s'.\n", cmd);
    }

    if (printAll) {
        dbln();
    }

    println("Usage: nifty [command] <inputs> <flags>\n");
    println("Commands:");
    printStrsWithSpacer("\tbuild", '-', "Build the default or specified target.", width);
    printStrsWithSpacer("\trun", '-', "Build and run the default or specified target.", width);
    printStrsWithSpacer("\tclean", '-', "Delete compiled files for the project or target.", width);
    printStrsWithSpacer("\thelp", '-', "Show this help information or information on the specified command.", width);
    printStrsWithSpacer("\tnew", '-', "Create new Nifty project in the current directory.", width);
    printStrsWithSpacer("\ttest", '-', "Build and run all tests in the default or specified target.", width);
    printStrsWithSpacer("\tdocs", '-', "Generate documentation from the default or specified target.", width);
    printStrsWithSpacer("\tversion", '-', "Prints Nifty version info.", width);
    printStrsWithSpacer("\tinfo", '-', "Prints information about the Nifty compiler.", width);
    printStrsWithSpacer("\tlist", '-', "List all of the targets for the build file in the current directory.", width);
    printStrsWithSpacer("\tcolors", '-', "Color codes can be set in the nifty config file, prints colors for reference.", width);
    dbln();
    println("To see a list of flags run 'nifty help flags'.");
    println("To see a list of environment variables used by nifty run 'nifty help env'.");
    println("To see a list of config options for the nifty compiler and nifty projects run `nifty help config'.");
    println("To show all help run 'nifty help all'.");
    dbln();
    println("If no command is given Nifty will build and run the default target from '%s'.", NIFTY_BUILD_FILE);
}

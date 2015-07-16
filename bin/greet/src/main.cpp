/*
 * Copyright (c) 2015, Olegs Briska
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the author nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL COPYRIGHT HOLDER BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/**
 * @file
 * @brief Implements the Greet command.
 */

// System headers
#include <cstdlib>
#include <iostream>
#include <vector>

// Boost headers
#include <boost/exception/diagnostic_information.hpp>
#include <boost/program_options.hpp>

// Project headers
#include <hello.hpp>

int main(int argc, const char* argv[]) {
    int result = EXIT_FAILURE;
    try {
        namespace po = boost::program_options;

        // Configure the command line option parser
        po::options_description desc("Options");
        desc.add_options()
                ("help,h", "Print this help message")
                ("who,w", po::value<std::string>(), "Whom to greet");

        // Parse command line options
        po::variables_map vm;
        po::parsed_options parsed = po::command_line_parser(argc, argv).
                options(desc).allow_unregistered().run();
        po::store(parsed, vm);

        // Handle --help option
        if (vm.count("help")) {
            std::cout << "Greet command:" << std::endl
                    << desc << std::endl;
            return EXIT_SUCCESS;
        }

        // Handle command line options
        auto additionalParameters = po::collect_unrecognized(parsed.options, po::include_positional);
        po::notify(vm);
        if (!additionalParameters.empty()) {
            throw std::runtime_error(std::string("Unrecognized option: ") + additionalParameters[0]);
        }
        if (!vm.count("who")) {
            throw std::runtime_error("Greet subject must be provided");
        }

        // Print the greeting
        greet(std::cout, vm["who"].as<std::string>());

        // We are done!
        result = EXIT_SUCCESS;
    } catch (std::exception& e) {
        std::cerr << boost::diagnostic_information(e) << std::endl;
    } catch (...) {
        std::cerr << "Unhandled exception" << std::endl;
    }
    return result;
}

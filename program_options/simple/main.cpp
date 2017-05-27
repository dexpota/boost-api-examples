#include <boost/program_options.hpp>
#include <iostream>

// Do not ever use this on a header file!
using namespace boost::program_options;

int main(int argc, const char* argv[]) {
    typedef std::vector<std::string> message_t;

    options_description options("A list of allowed options.");
    options.add_options()
        ("help", "Print an help message.")
        ("message", value<message_t>(), "Message to print to standard output.");

    positional_options_description positional;
    positional.add("message", -1);

    variables_map vm;
    store(command_line_parser(argc, argv).options(options).positional(positional).run(), vm);
    notify(vm);

    // check if help was passed as an option
    if(vm.count("help")) {
        std::cout << options << std::endl;
        return EXIT_SUCCESS;
    }

    if(vm.count("message")) {
        message_t message = vm["message"].as<message_t>();
        std::copy(message.begin(), message.end(), std::ostream_iterator<std::string>(std::cout, " "));
    }

    return EXIT_SUCCESS;
}
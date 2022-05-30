#ifndef __FRAMEWORK_EXIT_EXCEPTION__
#define __FRAMEWORK_EXIT_EXCEPTION__

class ExitException final {
public:
    int code;
    ExitException(int code) : code(code) {}
};

#endif
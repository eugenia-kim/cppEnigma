#include <string>

class RotorReflector {
    public:
        RotorReflector(int, argv);
        virtual std::string map(std::string) = 0;
    protected:
        int _argc;
        char** _argv;
}

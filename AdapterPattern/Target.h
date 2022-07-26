#ifndef Target_H
#define Target_H

class Target {
    public:
    virtual ~Target() = default;
    virtual std::string Request();

};
#endif
#pragma once

class Brakes
{
public:
    virtual void Apply() = 0;
    virtual void Release() = 0;
    virtual ~Brakes() = 0;

    enum BreakType {
        DUMMY,
    };

    static Brakes* GetInstance(BreakType type);

    static void RunSample();
};

class IBrakes
{
public:
    virtual void Apply() = 0;
    virtual void Release() = 0;
    virtual ~IBrakes() = 0;

    enum BreakType {
        DUMMY,
    };

    static IBrakes* GetInstance(BreakType type);

    static void RunSample();
};

class DummyBreaks: public IBrakes
{
public:
    DummyBreaks();
    ~DummyBreaks();

    void Apply();
    void Release();
};

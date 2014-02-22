class IEngine
{
public:
    virtual void Start() = 0;
    virtual void ShutDown() = 0;
    virtual ~IEngine() = 0;

    enum EngineType {
        DUMMY,
    };

    static IEngine* GetInstance(EngineType type);

    static void RunSample();
};

class DummyEngine: public IEngine
{
public:
    DummyEngine();
    ~DummyEngine();

    void Start();
    void ShutDown();
};

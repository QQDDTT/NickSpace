#ifndef SCRIPT_ENGINE_H
#define SCRIPT_ENGINE_H

#include <string>

// 脚本引擎
class ScriptEngine {
public:
    virtual ~ScriptEngine() {}
    virtual void execute(const std::string& script) = 0;
};

#endif // SCRIPT_ENGINE_H
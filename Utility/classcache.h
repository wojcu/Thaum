#ifndef CLASSCACHE_H
#define CLASSCACHE_H

#include <QSharedPointer>
#include <unordered_map>
#include <QDebug>

namespace Utility {

class ClassCreatorBase {
public:
    ClassCreatorBase();
    virtual ~ClassCreatorBase();

    virtual void *create() const = 0;
};

template<typename T>
class ClassCreator : public ClassCreatorBase {
public:
    ClassCreator() {

    }

    ~ClassCreator() {

    }

    void *create() const override {
        return new T();
    }
};

class ClassCache
{
public:
    static ClassCache &instance();
    ~ClassCache();

    template<typename T>
    void registerClass(const std::string &name) {
        m_types[name] = QSharedPointer<ClassCreator<T>>(new ClassCreator<T>());
    }

    template<typename T>
    QSharedPointer<T> create(const std::string &name) {
        if (m_types.find(name) == m_types.end())
            return QSharedPointer<T>();
        return QSharedPointer<T>(static_cast<T*>(m_types[name]->create()));
    }

private:
    ClassCache();
    ClassCache(const ClassCache &) = delete;
    ClassCache(ClassCache &&) = delete;

    std::unordered_map<std::string, QSharedPointer<ClassCreatorBase>> m_types;
};

template<typename T>
class AutomaticClassAdd {
public:
    AutomaticClassAdd(const std::string &name) {
        ClassCache::instance().registerClass<T>(name);
    }
};

}

#define CACHEADD(type) class type; Utility::AutomaticClassAdd<type> _G_CACHE_##type(#type);
#define CACHECREATEORGANISM(name) Utility::ClassCache::instance().create<Simulation::Organism>

#endif // CLASSCACHE_H
